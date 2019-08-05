#pragma once

#include "ITemperatureController.h"

class Refrigerator : public ITemperatureController {
public:
	Refrigerator( bool& drive_pin, bool& status_pin );
	virtual ~Refrigerator() = default;
	virtual void StartRegulating() override;
	virtual void StopRegulating() override;
	virtual bool IsOkay() override;

private:
	bool& out_drive_pin_;
	bool& in_error_pin_;
};
