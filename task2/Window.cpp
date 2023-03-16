#include "Window.h"
#include "Container.h"
#include <iostream>
Window::Window() :Container()
{
}

Window::Window(int x, int y) : Container(x, y)
{
}

Window::Window(int x, int y, int width, int height) : Container(x, y, width, height)
{
}

Window::~Window()
{
}

