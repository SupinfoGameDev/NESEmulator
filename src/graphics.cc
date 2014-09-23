#include "../include/graphics/graphics.h"

Color::Color(int color)
{
    r = (color >> 16) & 0xff;
    g = (color >> 8) & 0xff;
    b = color & 0xff;
}
