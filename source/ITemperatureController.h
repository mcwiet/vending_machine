#pragma once

class ITemperatureController {
public:
	virtual void StartRegulating() = 0;
	virtual void StopRegulating() = 0;
	virtual bool IsOkay() = 0;
};