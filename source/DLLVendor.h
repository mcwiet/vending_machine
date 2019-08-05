#pragma once

#include "IVendor.h"

#ifdef VENDOR_EXPORTS
#define VENDOR_API __declspec(dllexport)
#else
#define VENDOR_API __declspec(dllimport)
#endif

extern "C"
{
	VENDOR_API IVendor& GetVendor();
}