#pragma once

class CCodecBase
{
public:
    CSize   m_image_size; // �����๹�����д��

    virtual ~CCodecBase() {}

    virtual IWICBitmapPtr CreateWICBitmap(IWICImagingFactory* factory) = 0;
};
