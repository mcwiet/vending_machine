#include "pch.h"
#include "CanVendorFixture.h"

TEST_F( CanVendorFixture, Successful_Vend ) {
	EXPECT_FALSE( outputs_.at( 2 ) );
	vendor_->Vend( 2 );
	EXPECT_TRUE( outputs_.at( 2 ) );
}

TEST_F( CanVendorFixture, Invalid_Location ) {
	EXPECT_NO_THROW( vendor_->Vend( NUM_OUTPUTS ) );
}