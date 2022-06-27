#include "improc.hpp"
#include "bitmap.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iterator>
#include <cstring>
#include <sstream>
#include <functional>


template<typename T>
Matrix<T>::Matrix(std::size_t r, std::size_t c, T v) : r_(r), c_(c) {
#if MATRIX_DATA_TYPE == ARRAY_2D
    m_ = new T*[r_];
    for (std::size_t count = 0; count < r_; count++) //for the T** type
        m_[count] = new T[c_];
    for (std::size_t i = 0; i < r_; i++) {
        for (std::size_t j = 0; j < c_; j++) {
            m_[i][j]=v;
        }
    }
#else
    for (std::size_t i = 0; i < r_; i++) {
            //m_[i].insert(m_.end(), v);
            m_.push_back(std::vector<T> (c_,v));
    }
#endif
}


template<typename T>
Matrix<T>::Matrix(const Matrix &current) : r_(current.r_), c_(current.c_) {
#if MATRIX_DATA_TYPE == ARRAY_2D
    m_ = new T*[r_];
    for (std::size_t i = 0; i < r_; i++)
        m_[i] = new T[c_];
    for (std::size_t i = 0; i < r_; i++) {
        for (std::size_t j = 0; j < c_; j++) {
            m_[i][j] = current[i][j];
        }
    }
#else
    for (std::size_t i = 0; i < r_; i++) {
        m_.push_back(current[i]);
        //std::copy(current.begin(), current.end(), std::back_inserter(m_[i]));
    }
#endif
}

template<typename T>
std::size_t Matrix<T>::get_nrows() const {
    return r_;
}

template<typename T>
std::size_t Matrix<T>::get_ncols() const {
    return c_;
}

template<typename T>
Matrix<T>::Matrix(std::size_t r, std::size_t c) : r_(r), c_(c) {
#if MATRIX_DATA_TYPE == ARRAY_2D
    m_ = new T*[r_];
    for (std::size_t count = 0; count < r_; count++) {//for the T** type
        m_[count] = new T[c_];
        memset(m_[count], 0, c_*sizeof(T));
    }
#else
    for (std::size_t i = 0; i < r_; i++) {
        for (std::size_t j = 0; j < c_; j++) {
            //m_.insert(m_.end(), 0);
            m_[i].push_back(0);
        }
    }
#endif
}

template<typename T>
void Matrix<T>::print() const {
    for (int i = 0; i < r_; i++) {
        for (int j = 0; j < c_; j++) {
            std::cout<<m_[i][j]<<' ';
        }
        std::cout<<'\n';
    }
}

class FileIOError:public std::runtime_error{
public:
    FileIOError(const std::string message) : std::runtime_error(message) {}
};

Image load_bitmap(const std::string& filepath) {
    BITMAPFILEHEADER header;
    BITMAPINFO *BitmapInfo = new BITMAPINFO();
    byte* bitmapBytes = LoadDIBitmap(filepath.c_str(), &BitmapInfo, &header);

    if (!bitmapBytes) {
        // Error when reading the input file.
        throw FileIOError("A pointer to bitmapBytes was not created\n");
    }
    if(!BitmapInfo) throw FileIOError("A pointer to Bitmapinfo is still a nullpointer\n");

    const size_t h = (size_t) BitmapInfo->bmiHeader.biHeight;
    const size_t w = (size_t) BitmapInfo->bmiHeader.biWidth;
    const size_t bits_per_pixel = BitmapInfo->bmiHeader.biBitCount;

    /* see: https://en.wikipedia.org/wiki/BMP_file_format#Pixel_storage */
    size_t row_size = (bits_per_pixel * w + 31) / 32 * 4;

    Image return_image(h,w,BitmapInfo, header);

    printf("Successfully loaded a %zu%zu image - %s.\n\n", h, w, filepath.c_str());

    /*byte** image_array = (byte**) malloc(sizeof(byte*) * h);
    for (size_t i = 0; i < h; i++) {
        image_array[i] = (byte*) malloc(sizeof(byte) * w);
        memset(image_array[i], 0, w);
    }*/

    byte* reader = bitmapBytes;

    // The order of the pixels in BMP file is as follows: from left to right, from bottom to top (first pixel is from
    // lower left corner of the picture).
    for (size_t i = 0; i < h; ++i) {
        /* Copy values of pixels in an image row. */
        for (size_t j = 0; j < w; ++j) {
            return_image[h - i - 1][j] = (byte)*reader;
            ++reader;
        }

        /* Skip padding bytes. */
        reader += row_size - w;
    }

    free(bitmapBytes);

    return return_image;
}

int save_bitmap(const std::string& filename, const Image& image) {
    if(!image.get_bitmapinfo()) throw (FileIOError("In save_bitmap function for a given Image instance its handle to BITMAPINFO structure is a null pointer\n"));
    const size_t h = (size_t) image.get_bitmapinfo()->bmiHeader.biWidth;
    const size_t w = (size_t) image.get_bitmapinfo()->bmiHeader.biHeight;
    const size_t bits_per_pixel = image.get_bitmapinfo()->bmiHeader.biBitCount;
    const size_t row_size = (bits_per_pixel * w + 31) / 32 * 4;

    byte* bitmapBytes = (byte*) malloc(sizeof(byte) * image.get_bitmapinfo()->bmiHeader.biSizeImage);
    byte* writer = bitmapBytes;

    const size_t padding = row_size - w;

    for (size_t i = 0; i < h; ++i) {

        /* Przepisz wartosci pikseli wiersza obrazu. */
        for (size_t j = 0; j < w; j++) {
            *writer++ = image[h - i - 1][j];
        }

        /* Ustaw bajty wyrownania. */
        for (size_t j = 0; j < padding; j++) {
            *writer++ = 0;
        }
    }

    int status = SaveDIBitmap(filename.c_str(), image.get_bitmapinfo(), bitmapBytes);
    free(bitmapBytes);

    return status;
}

BmpInfoUniquePtr copy_bitmapinfo(BITMAPINFO *bmi, BITMAPFILEHEADER hdr) {
    if(bmi == nullptr){
        return nullptr;
    }
#ifdef _WIN32
    auto size = hdr.bfOffBits - sizeof(BITMAPFILEHEADER);
#endif
#ifndef _WIN32
    auto size = hdr.bfOffBits - 18;
#endif
    BITMAPINFO * ptr = reinterpret_cast<BITMAPINFO*> (new char [size]);
    //bmi = (BITMAPINFO*) new char [size];
    std::memcpy(ptr, bmi, size);
    return BmpInfoUniquePtr (ptr);
}

std::string to_string(const Image &im, ImagePrintMode print_mode) {
    std::ostringstream ost;
    switch (print_mode){
        case CHARS:
            for (std::size_t i = 0; i < im.get_nrows(); i++) {
                for (std::size_t j = 0; j < im.get_ncols(); j++) {
                    ost<<(char)im[i][j];
                }
                ost<<'\n';
            }
            break;
        case NUMS:

            for (std::size_t i = 0; i < im.get_nrows(); i++) {
                for (std::size_t j = 0; j < im.get_ncols(); j++) {
                    ost<<"  "<<(int)im[i][j];
                }
                ost<<'\n';
            }
            break;
    }
    std::string str = ost.str();
    str.pop_back();
    return str;
}

using Mask = Matrix<double>;

Image transform(const Image &im_in, std::function<byte(byte)> func) {
    Image tmp(im_in);
    for (std::size_t i = 0; i < im_in.get_nrows(); i++) {
        for (std::size_t j = 0; j < im_in.get_ncols(); j++) {
            tmp[i][j] = func(tmp[i][j]);
        }
    }
    return tmp;
}

Mask get_averaging_mask(std::size_t n) {
    return {n,n,1.0/(double)(n*n)};   //maybe wrong casting to double
}

Image filter(const Image &im_in, const Mask &mask) {
    Image new_im(im_in);
    std::size_t mask_length = (mask.get_nrows()-1)/2;
    for (std::size_t i = 0; i < im_in.get_nrows(); i++) {
        for (std::size_t j = 0; j < im_in.get_ncols(); j++) {
            byte sum = 0;
            for (std::size_t k = i; k < i+mask.get_nrows(); k++) {
                for (std::size_t l = j; l < j + mask.get_ncols(); l++) {

                    std::size_t pixel_val;
                    if(k < mask_length || l < mask_length || k > im_in.get_nrows() || l > im_in.get_ncols()){
                        pixel_val = 0;
                    }else{
                        pixel_val = im_in[k - mask_length][l - mask_length];
                    }
                    sum += (byte)(mask[k - i][l - j] * (double)pixel_val);            //maybe wrong casting to double
                }
            }
            new_im[i][j] = sum;
        }
    }
    return new_im;
}



Image::Image(const Image &current) : Matrix<byte>(current){
    hdr_ = current.hdr_;
    bmi_ = copy_bitmapinfo(current.bmi_.get(), current.hdr_);
}
