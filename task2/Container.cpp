#include "Container.h"
#include <iostream>

Container::Container() :Component()
{
	setSize();
}

Container::Container(int x, int y) : Component(x, y)
{
	setSize();
}

Container::Container(int x, int y, int width, int height) : Component(x, y, width, height)
{
}

Container::~Container()
{
}

void Container::setSize()
{
	_width = 50;
	_height = 50;
}

list<Component*> Container::getComponents()
{
	return _components;
}


void Container::addComponent(Component* component)
{
	if (!_isVisible) component->_isVisible = false;
	component->_parent = this;
	_components.emplace_front(component);
}

void Container::onClick(int x, int y)
{
	for (Component* c : _components) {
		if (c->isClicked(x, y)) {
			c->onClick(x, y);
			return;
		}
	}

	if (isClicked(x, y)) Component::onClick(x, y);
	else cout << "You clicked on blank area" << endl;
}

Component* Container::findChildById(int id)
{
	if (_id == id) return this;
	for (auto* c: getComponents())
	{
		if (c->getId() == id) return c;
		return ((Container*)c)->findChildById(id);
	}
}
