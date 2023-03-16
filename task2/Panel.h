#pragma once
#include "Container.h"

class Panel :public Container
{
public:
	Panel();
	Panel(int x, int y);
	Panel(int x, int y, int width, int height);
	~Panel();
};

