#include "../include/graphics/graphics.h"
#include <cassert>

Color::Color(int color)
{
    r = (color >> 16) & 0xff;
    g = (color >> 8) & 0xff;
    b = color & 0xff;
}

Matrix::Matrix(int w, int h)
{
    pixels.reserve(w * h);
    width = w;
    height = h;
}

int& Matrix::at(int x, int y)
{
    assert(x < width && y < height
        && "x cannot be superior or equal to matrixwidth, and y cannot be superior or equal to matrix height");
    return pixels[x + y * width];
}
