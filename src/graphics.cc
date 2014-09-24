#include "../include/graphics/graphics.h"
#include <cassert>

Matrix::Matrix(int w, int h)
{
    pixels.reserve(w * h);
    width = w;
    height = h;
}

int& Matrix::at(int x, int y)
{
    assert(x < width && y < height && "variable can't be superior to matrix size");
    return pixels[x + y * width];
}
