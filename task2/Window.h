#pragma once
#include <string>
#include "Container.h"

using namespace std;
class Window :public Container
{
public:
	string title;
	Window();
	Window(int x, int y);
	Window(int x, int y, int width, int height);
	~Window();

};

