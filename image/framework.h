#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

#include <atltypes.h>
#include <atlstr.h>
#include "UIStone/Source/base/global.h"
using namespace uistone;

#define FREEIMAGE_LIB
#include "3rd/FreeImage/Dist/FreeImage.h"
#ifdef _DEBUG
#pragma comment (lib, "FreeImageLibd.lib")
#else
#pragma comment (lib, "FreeImageLib.lib")
#endif

#include "libheif/heif.h"
#ifdef _DEBUG
#pragma comment (lib, "heif.lib")
#pragma comment (lib, "libde265.lib")
#pragma comment (lib, "x265-static.lib")
#else
#pragma comment (lib, "heif.lib")
#pragma comment (lib, "libde265.lib")
#pragma comment (lib, "x265-static.lib")
#endif

#include "UIStone/misc/codec_freeimage.h"
