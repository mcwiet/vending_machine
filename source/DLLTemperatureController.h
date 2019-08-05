#pragma once

#include "ITemperatureController.h"

#ifdef TEMPERATURECONTROLLER_EXPORTS
#define TEMPERATURECONTROLLER_API __declspec(dllexport)
#else
#define TEMPERATURECONTROLLER_API __declspec(dllimport)
#endif

extern "C"
{
	TEMPERATURECONTROLLER_API ITemperatureController& GetTemperatureController();
}