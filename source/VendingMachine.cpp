#include "pch.h"
#include "VendingMachine.h"
#include "ITemperatureController.h"
#include "IItemSelector.h"
#include "IVendor.h"
#include <iostream>
#include <map>
#include <thread>
#include <chrono>

static std::map<std::string, unsigned> TEST_ITEM_MAP;

VendingMachine::VendingMachine( ITemperatureController& temp_controller, IItemSelector& item_selector, IVendor& item_vendor ) :
	temp_controller_( temp_controller ),
	item_selector_( item_selector ),
	item_vendor_( item_vendor )
{
	PopulateStatusFunctions();
	PopulateTestMap();
	StartHardware();
};

void VendingMachine::PopulateStatusFunctions() {
	status_functions_.push_back( std::bind( &ITemperatureController::IsOkay, &temp_controller_ ) );
}

void VendingMachine::PopulateTestMap() {
	TEST_ITEM_MAP.emplace( "coke", 1 );
	TEST_ITEM_MAP.emplace( "diet coke", 2 );
	TEST_ITEM_MAP.emplace( "dr. pepper", 3 );
	TEST_ITEM_MAP.emplace( "sprite", 4 );
	TEST_ITEM_MAP.emplace( "irish coffee", 5 );
}

void VendingMachine::StartHardware() {
	temp_controller_.StartRegulating();
}

int VendingMachine::Execute() {
	int ret = 0;

	// Check hardware status
	for (auto check_status : status_functions_) {
		ret = (check_status()) ? 0 : -1;
		if (ret < 0) { break; }
	}

	// @todo(mc) Just some test code to make things look better, let the user see the items available
	std::cout << "Available items:" << std::endl;
	for (auto item : TEST_ITEM_MAP) {
		std::cout << item.first << std::endl;
	}

	std::cout << std::endl;
	std::string selection = item_selector_.GetSelection();  // Get user input

	// @todo(mc) Just some test code to make things look better, vend the user's item
	auto item = TEST_ITEM_MAP.find( selection );
	if (item != TEST_ITEM_MAP.end()) {
		item_vendor_.Vend( item->second );
	}
	else {
		std::cout << "Invalid item entered: " << selection;
		std::cout << std::endl;
	}
	// @todo(mc)
	for (int i = 0; i < 5; ++i) { // >:) dirty
		std::cout << ".";
		std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
	}
	system( "cls" ); // >:) dirty

	return ret;
}