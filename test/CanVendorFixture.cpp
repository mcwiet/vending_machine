#include "pch.h"
#include "CanVendorFixture.h"

void CanVendorFixture::SetUp() {
	outputs_.reserve( NUM_OUTPUTS );
	for (unsigned i = 0; i < NUM_OUTPUTS; ++i) {
		outputs_.push_back( false );
	}
	vendor_ = std::make_unique<CanVendor>( outputs_ );
}