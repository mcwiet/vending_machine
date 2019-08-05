#include "pch.h"
#include "ConsoleInput.h"
#include "DLLItemSelector.h"
#include <iostream>

IItemSelector& GetItemSelector() {
	static ConsoleInput inst( std::cin );
	return inst;
}