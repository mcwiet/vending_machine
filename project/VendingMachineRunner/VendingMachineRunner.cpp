#include "VendingMachine.h"
#include "DLLTemperatureController.h"
#include <Windows.h>
#include <thread>
#include <chrono>
#include <exception>
#include <iostream>

class DLL_Load_Exception : public std::exception {};

typedef ITemperatureController& (__cdecl* TEMPCONTROLLER)();
typedef IItemSelector& (__cdecl* ITEMSELECTOR)();
typedef IVendor& (__cdecl* VENDOR)();

template<typename FUNCTYPE, typename OBJECTTYPE>
OBJECTTYPE& GetDLLObject( const LPCSTR& dll_name, const LPCSTR& func_name ) {
	auto hinst = LoadLibraryA( dll_name );
	if (hinst == nullptr) { throw DLL_Load_Exception(); }

	auto ModuleGetter = (FUNCTYPE)GetProcAddress( hinst, func_name );
	if (ModuleGetter == nullptr) {
		throw DLL_Load_Exception();
	}

	return ModuleGetter();
}

int main()
{
	try {
		auto& temp_controller = GetDLLObject<TEMPCONTROLLER, ITemperatureController>( "TemperatureController_Refrigerator.dll", "GetTemperatureController" );
		auto& item_selector = GetDLLObject<ITEMSELECTOR, IItemSelector>( "ItemSelector_ConsoleInput.dll", "GetItemSelector" );
		auto& vendor = GetDLLObject<VENDOR, IVendor>( "Vendor_CanVendor.dll", "GetVendor" );

		VendingMachine vm( temp_controller, item_selector, vendor );
		while (true) {
			vm.Execute();
			std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) ); // >:)
		}
	}
	catch (...) {
		std::cout << "Whoops! Failed trying to load one of the DLL's or "
			<< "its function for instantiating the object. At this time "
			<< "all DLL's must load successfully but should consider a "
			<< "method of gracefully running the application if some or "
			<< "all of these fail." << std::endl;
		return -1;
	}

	return 0;
}