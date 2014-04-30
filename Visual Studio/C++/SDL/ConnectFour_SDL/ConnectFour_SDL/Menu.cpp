#include <stack>
#include <memory>
#include <cassert>



class Menu
{
public:
	// Common to all menus:
	// (for example)
	virtual void draw() = 0;
	virtual void onMouseMove(int x, int y) = 0;
	virtual void onMouseButton(int button, bool is_down) = 0;
	// ... etc.
};
