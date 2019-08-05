#include "pch.h"
#include "DLLVendor.h"
#include "CanVendor.h"

static const unsigned NUM_OUTPUTS = 10;

IVendor& GetVendor() {
	static std::vector<bool> outputs( NUM_OUTPUTS, false );
	static CanVendor inst( outputs );
	return inst;
}