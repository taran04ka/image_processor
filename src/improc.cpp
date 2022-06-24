#include "improc.hpp"
#include "bitmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iterator>


template<typename T>
Matrix<T>::Matrix(std::size_t r, std::size_t c, T v) {
#if MATRIX_DATA_TYPE == ARRAY_2D
    m_ = new T*[r];
    for (std::size_t count = 0; count < r; count++) //for the T** type
        m_[count] = new T[c];
    for (std::size_t i = 0; i < r; i++) {
        for (std::size_t j = 0; j < c; j++) {
            m_[i][j]=v;
        }
    }
#else
    for (std::size_t i = 0; i < r; i++) {
        for (std::size_t j = 0; j < c; j++) {
            m_.push_back(v);
        }
    }
#endif
}


template<typename T>
Matrix<T>::Matrix(const Matrix &current) {
#if MATRIX_DATA_TYPE == ARRAY_2D
    for
#else
<<<<<<< Updated upstream
    std::copy(current.begin(), current.end(), std::back_inserter(m_));
=======
    for (std::size_t i = 0; i < r_; i++) {
        m_.push_back(current[i]);
        //std::copy(current.begin(), current.end(), std::back_inserter(m_[i]));
    }
>>>>>>> Stashed changes
#endif
}

#if MATRIX_DATA_TYPE == ARRAY_2D
template<typename T>
Matrix<T>::~Matrix() {
<<<<<<< Updated upstream
#if MATRIX_DATA_TYPE == ARRAY_2D
    for (std::size_t count = 0; count < m_[0].size(); count++)
        delete[] m_[count];
    delete[] m_;
#else
#endif
=======
    for (std::size_t count = 0; count < r_; count++)
        delete[] m_[count];
    delete[] m_;
>>>>>>> Stashed changes
}
#endif

template<typename T>
<<<<<<< Updated upstream
std::size_t Matrix<T>::get_nrows() {
#if MATRIX_DATA_TYPE == ARRAY_2D
    unsigned int counter = 0;
    while (m_!= nullptr){
        counter++;
        m_++;
=======
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
>>>>>>> Stashed changes
    }
    return counter;
#else
    return m_.size();
#endif

}

template<typename T>
std::size_t Matrix<T>::get_ncols() {
#if MATRIX_DATA_TYPE == ARRAY_2D
    unsigned int counter = 0;
    while (*m_ != nullptr){
        counter++;
        m_++;
    }
#else
    return m_[0].size();
#endif
}

byte** load_bitmap(const char* filepath, BITMAPINFO **BitmapInfo) {
    BITMAPFILEHEADER header;
    byte* bitmapBytes = LoadDIBitmap(filepath, BitmapInfo, &header);

    if (!bitmapBytes) {
        // Error when reading the input file.
        exit(-1);
    }

    const size_t h = (size_t) (*BitmapInfo)->bmiHeader.biHeight;
    const size_t w = (size_t) (*BitmapInfo)->bmiHeader.biWidth;
    const size_t bits_per_pixel = (*BitmapInfo)->bmiHeader.biBitCount;

    /* see: https://en.wikipedia.org/wiki/BMP_file_format#Pixel_storage */
    size_t row_size = (bits_per_pixel * w + 31) / 32 * 4;

    printf("Successfully loaded a %lux%lu image - %s.\n\n", h, w, filepath);

    byte** image_array = (byte**) malloc(sizeof(byte*) * h);
    for (size_t i = 0; i < h; i++) {
        image_array[i] = (byte*) malloc(sizeof(byte) * w);
        memset(image_array[i], 0, w);
    }

    byte* reader = bitmapBytes;

    // The order of the pixels in BMP file is as follows: from left to right, from bottom to top (first pixel is from
    // lower left corner of the picture).
    for (size_t i = 0; i < h; ++i) {
        /* Copy values of pixels in an image row. */
        for (size_t j = 0; j < w; ++j) {
            image_array[h - i - 1][j] = *reader;
            ++reader;
        }

        /* Skip padding bytes. */
        reader += row_size - w;
    }

    free(bitmapBytes);

    return image_array;
}

int save_bitmap(const char* filepath, byte** image, BITMAPINFO* BitmapInfo) {

    const size_t h = (size_t) BitmapInfo->bmiHeader.biWidth;
    const size_t w = (size_t) BitmapInfo->bmiHeader.biHeight;
    const size_t bits_per_pixel = BitmapInfo->bmiHeader.biBitCount;
    const size_t row_size = (bits_per_pixel * w + 31) / 32 * 4;

    byte* bitmapBytes = (byte*) malloc(sizeof(byte) * BitmapInfo->bmiHeader.biSizeImage);
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

    int status = SaveDIBitmap(filepath, BitmapInfo, bitmapBytes);
    free(bitmapBytes);

    return status;
}
<<<<<<< Updated upstream
=======

BmpInfoUniquePtr copy_bitmapinfo(BITMAPINFO *bmi, BITMAPFILEHEADER hdr) {
#ifdef _WIN32
    auto size = hdr.bfOffBits - sizeof(BITMAPFILEHEADER);
#endif
#ifndef _WIN32
    auto size = hdr.bfOffBits - 18;
#endif
    auto * ptr = (BITMAPINFO*) new char [size];
    bmi = (BITMAPINFO*) new char [size];
    std::memcpy(bmi, ptr, size);
    return BmpInfoUniquePtr (bmi);
}

std::string to_string(const Image &im, ImagePrintMode print_mode) {
    std::ostringstream ost;
    switch (print_mode){
        case CHARS:
            for (std::size_t i = 0; i < im.get_nrows(); i++) {
                for (std::size_t j = 0; j < im.get_ncols(); j++) {
                    ost<<(char)im[i][j];
                }
                ost<< std::endl;
            }break;

        case NUMS:

            for (std::size_t i = 0; i < im.get_nrows(); i++) {
                for (std::size_t j = 0; j < im.get_ncols(); j++) {
                    ost<<"  "<<(int)im[i][j];
                }
                ost<<std::endl;
            }break;

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
            func(tmp[i][j]);
        }
    }
    return tmp;
}

Mask get_averaging_mask(std::size_t n) {
    return {n,n,1.0/(double)(n*n)};
}

Image filter(const Image &im_in, const Mask &mask) {
    Image new_im(im_in);
    std::size_t mask_length = (mask.get_nrows()-1)/2;
    for (std::size_t i = 0; i < im_in.get_nrows(); i++) {
        for (std::size_t j = 0; j < im_in.get_ncols(); j++) {
            byte sum = 0;
            for (std::size_t k = i; k < i+mask.get_nrows(); k++) {
                for (std::size_t l = j; l < j+mask.get_ncols(); l++) {

                    std::size_t pixel_val;
                    if(k < mask_length || l < mask_length || k > im_in.get_nrows() || l > im_in.get_ncols()){
                        pixel_val = 0
                    }else{
                        pixel_val = im_in[k - mask_length][l - mask_length];
                    }
<<<<<<< Updated upstream
//                    if(i>=mask_length) {
//
//                    }
//                    if(j>=mask_length){
//
//                    }
//                    if(i+mask_length >= im_in.get_nrows()) delete it
//                          pixel_val = 0;
//                    }
//                    if(j+mask_length >= im_in.get_ncols()) delete it
//                    {
//                          pixel_val = 0;
//                    }
                    sum += (byte)(mask[k - i][l - j] * pixel_val)
=======
                    sum += (byte)(mask[k - i][l - j] * (double)pixel_val);
>>>>>>> Stashed changes
                }
            }
            new_im[i][j] = sum
        }
    }
    return new_im;
}

Image::Image(const Image &current) : Matrix<byte>(current){
    hdr_ = current.hdr_;
    bmi_ = copy_bitmapinfo(current.bmi_, current.hdr_).get();
}
>>>>>>> Stashed changes
