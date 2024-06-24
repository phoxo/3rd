#pragma once

#ifdef PHOXODLL_EXPORTS
#define IMAGE_API __declspec(dllexport)
#else
#define IMAGE_API __declspec(dllimport)
#endif

extern "C"
{
    // heif和freeimage的使用需要初始化
    IMAGE_API void oxo_3rd_init();
    IMAGE_API void oxo_3rd_deinit();

    IMAGE_API IWICBitmap* oxo_load_heif_image(PCWSTR filepath, IWICImagingFactory* factory);

//    IMAGE_API HANDLE oxo_create_image_loader(PCWSTR filepath, SIZE* image_size);
//    IMAGE_API void oxo_delete_image_loader(HANDLE loader);
//    IMAGE_API IWICBitmap* oxo_load_image(HANDLE loader, IWICImagingFactory* factory);

    IMAGE_API SIZE oxo_svg_parse_image_size(char* svg_string);

    IMAGE_API IWICBitmap* oxo_freeimage_load(PCWSTR filepath, IWICImagingFactory* factory);
    IMAGE_API BOOL oxo_freeimage_save(PCWSTR filepath, IWICBitmap* img);
}
