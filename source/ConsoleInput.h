#include "IItemSelector.h"
#include <istream>

class ConsoleInput : public IItemSelector {
public:
	ConsoleInput( std::istream& input );
	virtual ~ConsoleInput() = default;
	virtual const char* GetSelection() override;
private:
	std::istream& input_;
	std::string last_selection_;
};