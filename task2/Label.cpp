#include "Component.h"
#include "Label.h"
Label::Label() :Component()
{
}

Label::Label(int x, int y) :Component(x, y)
{
}

Label::Label(int x, int y, int width, int height, string text) :Component(x, y, width, height)
{
	_text = std::move(text);
}

string Label::getText() {
	return _text;
}

void Label::setText(string text) {
	_text = std::move(text);
}

string Label::toString()
{
	string res;

	res += getName() + "[id = " + to_string(_id) + ", pos = (" + to_string(_x) + ", " + to_string(_y)
		+ "), size = (" + to_string(_width) + " x " + to_string(_height) + "), text = " + _text + ", ";
	if (_isVisible)
		res += "visible = true, ";
	else res += "visible = false, ";
	if (_parent != nullptr)
		res += "par_id = " + to_string(_parent->getId()) + "] ";
	return res;
}

Label::~Label()
{
}

