#include "improc.hpp"
#include "bitmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iterator>
#include <cstring>
#include <sstream>


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
    r_ = current.r_;
    c_ = current.c_;
    for (int i = 0; i < r_; i++) {
        m_.push_back(current[i]);
        //std::copy(current.begin(), current.end(), std::back_inserter(m_[i]));
    }
#endif
}

template<typename T>
Matrix<T>::~Matrix() {
#if MATRIX_DATA_TYPE == ARRAY_2D
    for (std::size_t count = 0; count < r_; count++)
        delete[] m_[count];
    delete[] m_;
#else

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
Matrix<T>::Matrix(std::size_t r, std::size_t c) {
#if MATRIX_DATA_TYPE == ARRAY_2D
    r_ = r;
    c_ = c;
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
                ost<<'\n';
            }
        case NUMS:
            for (std::size_t i = 0; i < im.get_nrows(); i++) {
                for (std::size_t j = 0; j < im.get_ncols(); j++) {
                    ost<<(int)im[i][j]<<"  ";
                }
                ost<<'\n';
            }
    }
    //eturn std::to_string(ost);
}

Image::Image(const Image &current) : Matrix<byte>(current){
    hdr_ = current.hdr_;
    bmi_ = copy_bitmapinfo(current.bmi_, current.hdr_).get();
}
