#include "pch.h"
#include "RefrigeratorFixture.h"

void RefrigeratorFixture::SetUp() {
	fridge_ = std::make_unique<Refrigerator>( out_drive_pin_, in_error_pin_ );
}