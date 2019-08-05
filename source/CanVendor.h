#pragma once

#include "IVendor.h"
#include <vector>

class CanVendor : public IVendor {
public:
	CanVendor( std::vector<bool>& drive_outputs );
	virtual ~CanVendor() = default;
	virtual void Vend( unsigned location ) override;
private:
	std::vector<bool>& drive_outputs_;
};