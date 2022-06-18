#include "imqueue.hpp"
#include "improc.hpp"
#include "improc.cpp"

Image processing_function(const Image &im_in){
    return filter(im_in, get_averaging_mask(3));
}