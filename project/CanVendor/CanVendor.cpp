#include "pch.h"
#include "CanVendor.h"
#include <iostream>

CanVendor::CanVendor( std::vector<bool>& drive_outputs ) :
	drive_outputs_( drive_outputs ) {};

void CanVendor::Vend( unsigned location ) {
	std::cout << "Vending item at location " << location << std::endl;

	if (location < drive_outputs_.size()) {
		drive_outputs_.at( location ) = true;
	}
}