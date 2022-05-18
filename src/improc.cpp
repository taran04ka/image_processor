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
    m_ = new T*[current.get_nrows()];
    for (int i = 0; i < current.get_nrows(); i++)
        m_[i] = new int[current.get_ncols()];

    for (int i = 0; i < current.get_nrows(); i++) {
        for (int j = 0; j < current.get_ncols(); j++) {
            m_[i][j] = current[i][j];
        }
    }
#else
    std::copy(current.begin(), current.end(), std::back_inserter(m_));
#endif
}

template<typename T>
Matrix<T>::~Matrix() {
#if MATRIX_DATA_TYPE == ARRAY_2D
    for (std::size_t count = 0; count < m_[0].size(); count++)
        delete[] m_[count];
    delete[] m_;
#else
#endif
}

template<typename T>
std::size_t Matrix<T>::get_nrows() {
#if MATRIX_DATA_TYPE == ARRAY_2D
    unsigned int counter = 0;
    while (m_!= nullptr){
        counter++;
        m_++;
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
