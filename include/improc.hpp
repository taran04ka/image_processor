#ifndef IMAGE_PROCESSOR_IMPROC_H
#define IMAGE_PROCESSOR_IMPROC_H

#include "bitmap.h"
#include <vector>

#define ARRAY_2D    1
#define VECTOR_OF_VECTORS 2
#define MATRIX_DATA_TYPE ARRAY_2D

template<class T>
#if MATRIX_DATA_TYPE == ARRAY_2D
using MatrixData = T**;
#else
using MatrixData = std::vector<std::vector<T>>;
#endif

template <typename T>
class Matrix{
public:
    using data_type = MatrixData<T>;
    Matrix(std::size_t r, std::size_t c, T v);
    Matrix(const Matrix& current);
    ~Matrix();
    std::size_t get_nrows();
    std::size_t get_ncols();
    T& operator[] (std::size_t pos) { return m_[pos]; }
private:
    data_type m_;
};

class Image{

};

/**
 * Load a BMP file from the disk.
 *
 * @param filepath File to load.
 * @return The loaded image.
 */
extern byte** load_bitmap(const char* filepath, BITMAPINFO **BitmapInfo);

/**
 * Save a BMP file to disk.
 *
 * @param filepath File to save.
 * @param image Image to save.
 * @return EXIT_SUCCESS on success or EXIT_FAILURE on failure.
 */
extern int save_bitmap(const char* filepath, byte** image, BITMAPINFO* BitmapInfo);

#endif //IMAGE_PROCESSOR_IMPROC_HPP
