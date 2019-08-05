#pragma once

#include "Refrigerator.h"

class RefrigeratorFixture : public ::testing::Test {
protected:
	void SetUp() override;
	std::unique_ptr<Refrigerator> fridge_;
	bool out_drive_pin_;
	bool in_error_pin_;
};
