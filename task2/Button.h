#pragma once
#include <string>
#include "Component.h"
class Button :public Component
{
public:
	string title;
	Button(int x, int y);
	Button(int x, int y, int width, int height);
	Button();
	~Button();
};