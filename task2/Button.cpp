#include "Component.h"
#include "Button.h"
Button::Button() :Component()
{
}

Button::Button(int x, int y) :Component(x, y)
{
}

Button::Button(int x, int y, int width, int height) :Component(x, y, width, height)
{
}


Button::~Button()
{
}

