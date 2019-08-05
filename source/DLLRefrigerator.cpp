#include "pch.h"
#include "Refrigerator.h"
#include "DLLTemperatureController.h"

ITemperatureController& GetTemperatureController() {
	static bool drive_gpio;
	static bool status_gpio;
	static Refrigerator inst( drive_gpio, status_gpio );
	return inst;
}