#include "pch.h"
#include "Refrigerator.h"
// DLL internal state variables
static const std::string start_reg_ = "Starting refrigeration.";
static const std::string stop_reg_ = "Stopping refrigeration.";

Refrigerator::Refrigerator( bool& out_drive_pin, bool& in_error_pin ) :
	out_drive_pin_( out_drive_pin ),
	in_error_pin_( in_error_pin ) {
};

void Refrigerator::StartRegulating() {
	std::cout << start_reg_ << std::endl;
	out_drive_pin_ = true;
}

void Refrigerator::StopRegulating() {
	std::cout << stop_reg_ << std::endl;
	out_drive_pin_ = false;
}

bool Refrigerator::IsOkay() {
	return !in_error_pin_;
}