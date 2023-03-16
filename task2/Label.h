#pragma once
#include <string>
#include "Component.h"
class Label :public Component
{
private:
	string _text;
public:
	string title;
	Label(int x, int y);
	Label(int x, int y, int width, int height, string text);
	string getText();
	void setText(string text);
	string toString() override;
	Label();
	~Label();
};
