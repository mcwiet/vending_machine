#pragma once

#include "CanVendor.h"

class CanVendorFixture : public ::testing::Test {
protected:
	void SetUp() override;
	std::vector<bool> outputs_;
	std::unique_ptr<CanVendor> vendor_;

	static const unsigned NUM_OUTPUTS = 10;
};