#pragma once

#include "IItemSelector.h"

#ifdef ITEMSELECTOR_EXPORTS
#define ITEMSELECTOR_API __declspec(dllexport)
#else
#define ITEMSELECTOR_API __declspec(dllimport)
#endif

extern "C"
{
	ITEMSELECTOR_API IItemSelector& GetItemSelector();
}