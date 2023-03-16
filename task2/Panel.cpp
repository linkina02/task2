#include "Panel.h"
#include "Container.h"
#include <iostream>

Panel::Panel() :Container()
{
}

Panel::Panel(int x, int y) : Container(x, y)
{
}

Panel::Panel(int x, int y, int width, int height) : Container(x, y, width, height)
{
}

Panel::~Panel()
{
}

