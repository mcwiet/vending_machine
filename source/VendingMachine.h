#include <vector>
#include <functional>

class ITemperatureController;
class IItemSelector;
class IVendor;

class VendingMachine {
public:
	VendingMachine( ITemperatureController& temp_controller, IItemSelector& item_selector, IVendor& item_vendor );
	virtual ~VendingMachine() = default;
	int Execute();
private:
	void PopulateStatusFunctions();
	void PopulateTestMap();
	void StartHardware();

	ITemperatureController& temp_controller_;
	IItemSelector& item_selector_;
	IVendor& item_vendor_;
	std::vector<std::function<bool()>> status_functions_;
};