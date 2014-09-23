#include "../../include/graphics/graphics.h"

Color from_hex(int color)
{
    int r = (color >> 16) & 0xff;
    int g = (color >> 8) & 0xff;
    int b = color & 0xff;
    return Color { r, b, g };
}
