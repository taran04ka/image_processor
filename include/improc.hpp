#ifndef IMAGE_PROCESSOR_IMPROC_H
#define IMAGE_PROCESSOR_IMPROC_H

#include "bitmap.h"
#include <vector>
#include <memory>

#define ARRAY_2D    1
#define VECTOR_OF_VECTORS 2
#define MATRIX_DATA_TYPE ARRAY_2D

struct BmpInfoDeleter {
    void operator()(BITMAPINFO* ptr) { delete[] ptr; }
};
using BmpInfoUniquePtr = std::unique_ptr<BITMAPINFO, BmpInfoDeleter>;

BmpInfoUniquePtr copy_bitmapinfo(BITMAPINFO* bmi, BITMAPFILEHEADER hdr);

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
    Matrix(std::size_t r, std::size_t c);
    Matrix(std::size_t r, std::size_t c, T v);
    Matrix(const Matrix& current);
    ~Matrix();
    std::size_t get_nrows() const;
    std::size_t get_ncols() const;
    void print() const;
#if MATRIX_DATA_TYPE == ARRAY_2D
    T* operator[] (std::size_t pos) { return m_[pos]; }
    const T* operator[] (std::size_t pos) const { return m_[pos]; }
#else
    typename MatrixData<T>::reference operator[] (std::size_t pos) {return m_[pos];}
    typename MatrixData<T>::const_reference operator[] (std::size_t pos) const {return m_[pos];}
#endif
protected:
    data_type m_;
private:
    std::size_t r_;
    std::size_t c_;
};

class Image : public Matrix<byte>{
private:
    BITMAPFILEHEADER hdr_;
    BITMAPINFO * bmi_ = nullptr;
public:
    Image(std::size_t h, std::size_t w, BITMAPINFO* bmi, BITMAPFILEHEADER hdr) : Matrix<byte>(h,w,0) {
        hdr_ = hdr;
        bmi_ = copy_bitmapinfo(bmi, hdr).get();
    }
    Image(std::size_t h, std::size_t w, BITMAPINFO* bmi, BITMAPFILEHEADER hdr, data_type data) : Image(h, w, bmi, hdr) {
        for (std::size_t i = 0; i < h; i++) {
            for (std::size_t j = 0; j < w; j++) {
                this->m_[i][j] = data[i][j];
            }
        }
    }
    Image(const Image& current);
    const BITMAPFILEHEADER& get_bitmapheader() { return hdr_; }
    BITMAPINFO* get_bitmapinfo() { return bmi_; }
};

enum ImagePrintMode {
    CHARS, NUMS
};

std::string to_string(const Image& im, ImagePrintMode print_mode = CHARS);

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
