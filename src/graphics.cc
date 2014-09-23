#include "../include/graphics/graphics.h"

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
    if (x >= width || y >= height)
    {
        return -1;
    }
    return pixels[x + y * width];
}
