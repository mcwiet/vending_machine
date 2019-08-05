#include "pch.h"
#include "ConsoleInput.h"
#include <iostream>
#include <string>

ConsoleInput::ConsoleInput( std::istream& input ) :
	input_( input ) {};

const char* ConsoleInput::GetSelection() {
	std::cout << "Enter item: ";
	std::getline( input_, last_selection_ );
	return last_selection_.c_str();
}