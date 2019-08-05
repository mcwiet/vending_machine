#include "pch.h"
#include "RefrigeratorFixture.h"

TEST_F( RefrigeratorFixture, Good_Start ) {
	fridge_->StartRegulating();
	in_error_pin_ = false;
	EXPECT_TRUE( fridge_->IsOkay() );
	EXPECT_TRUE( out_drive_pin_ );
}

TEST_F( RefrigeratorFixture, Bad_Start ) {
	fridge_->StartRegulating();
	in_error_pin_ = true;
	EXPECT_FALSE( fridge_->IsOkay() );
	EXPECT_TRUE( out_drive_pin_ );
}

TEST_F( RefrigeratorFixture, Stop_When_Okay ) {
	fridge_->StartRegulating();
	in_error_pin_ = false;
	EXPECT_TRUE( fridge_->IsOkay() );
	EXPECT_TRUE( out_drive_pin_ );

	fridge_->StopRegulating();
	EXPECT_FALSE( out_drive_pin_ );
}

TEST_F( RefrigeratorFixture, Stop_When_Errored ) {
	fridge_->StartRegulating();
	in_error_pin_ = true;
	EXPECT_FALSE( fridge_->IsOkay() );
	EXPECT_TRUE( out_drive_pin_ );

	fridge_->StopRegulating();
	EXPECT_FALSE( out_drive_pin_ );
}