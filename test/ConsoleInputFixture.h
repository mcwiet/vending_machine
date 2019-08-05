#pragma once

#include "ConsoleInput.h"

class ConsoleInputFixture : public ::testing::Test {
protected:
	void SetUp() override;
	std::unique_ptr<ConsoleInput> console_;
	std::stringstream stream_;
};