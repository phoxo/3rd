#include "pch.h"
#include "image.h"

IWICBitmap* oxo_freeimage_load(PCWSTR filepath, IWICImagingFactory* factory)
{
    auto   img_type = FreeImage_GetFIFFromFilenameU(filepath);
    if (img_type == FIF_UNKNOWN)
        return NULL;

    IWICBitmap   * load_img = nullptr;
    FCCodecFreeImage::CAutoFIBITMAP   img(FreeImage_LoadU(img_type, filepath));
    if (img)
    {
        img.ConvertTo32bpp();
        FreeImage_FlipVertical(img);

        UINT   width = FreeImage_GetWidth(img);
        UINT   height = FreeImage_GetHeight(img);
        UINT   pitch = FreeImage_GetPitch(img);
        auto   data_ptr = FreeImage_GetBits(img);

        if (data_ptr && pitch)
        {
            factory->CreateBitmapFromMemory(width, height, WICNormal32bpp, pitch, pitch * height, (BYTE*)data_ptr, &load_img);
        }
    }
    return load_img;
}

BOOL oxo_freeimage_save(PCWSTR filepath, IWICBitmap* img)
{
    CWICLockedPixelBuffer   buf(img);
    if (buf.IsFormat32bpp())
    {
        FCImage   img;
        img.Attach32bppBuffer(buf.m_width, buf.m_height, buf.m_data);
        BOOL   ret = FCCodecFreeImage::Save(filepath, img);
        img.Release32bppBuffer();
        return ret;
    }
    assert(FALSE);
    return FALSE;
}
