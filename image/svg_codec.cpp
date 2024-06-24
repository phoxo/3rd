#include "pch.h"
#include "image.h"

#pragma warning( disable : 4244 ) 
#define NANOSVG_IMPLEMENTATION
#include "3rd/nanosvg/nanosvg.h"

SIZE oxo_svg_parse_image_size(char* svg_string)
{
    CSize   ret;
    auto   nano = nsvgParse(svg_string, "px", 96);
    if (nano)
    {
        ret = CSize((int)ceil(nano->width), (int)ceil(nano->height));
        nsvgDelete(nano);
    }
    return ret;
}
