#include "pch.h"
#include "ConsoleInputFixture.h"

void ConsoleInputFixture::SetUp() {
	console_ = std::make_unique<ConsoleInput>( stream_ );
}