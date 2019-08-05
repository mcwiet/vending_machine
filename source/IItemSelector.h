#pragma once

class IItemSelector {
public:
	virtual const char* GetSelection() = 0;
};