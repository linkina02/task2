#include "Component.h"
#include <iostream>
#include <typeinfo>
#include <exception>

int Component::_idCounter = 0;

Component::Component()
{
	_x = 0;
	_y = 0;
	_width = 1;
	_height = 1;
	_id = _idCounter;
	_idCounter++;
	_isVisible = true;
	_parent = nullptr;

}

Component::Component(int x, int y) :Component()
{
	setX(x);
	setY(y);
}

Component::Component(int x, int y, int width, int height) :Component(x, y)
{
	setWidth(width);
	setHeight(height);

}

void Component::move(int x, int y)
{
	setX(x);
	setY(y);
}

void Component::onClick(int x, int y)
{
	string s = getName();
	cout << "You clicked on " << s << " [id = " << _id << "] " << endl;
}

string Component::toString()
{
	string res;
	
	res += getName() + "[id = " + to_string(_id) + ", pos = (" + to_string(_x) + ", " + to_string(_y)
		+ "), size = (" + to_string(_width) + " x " + to_string(_height) + "), ";
	if (_isVisible) 
		res += "visible = true";
	else res += "visible = false";
	if (_parent != nullptr)
		res += ", par_id = " + to_string(_parent->getId()) + "] ";
	else res += "]";
	return res;

}

string Component::getName()
{
	string name = typeid(*this).name();
	return name.substr(6, name.length());
}

int Component::getId()
{
	return _id;
}

int Component::getX()
{
	return _x;
}

void Component::setX(int x)
{
	if (x >= 0) _x = x;
	else throw exception("Illigal value");
}

int Component::getY()
{
	return _y;
}

void Component::setY(int y)
{
	if (y >= 0) _y = y;
	else throw exception("Illigal value");
}

int Component::getWidth()
{
	return _width;
}

void Component::setWidth(int width)
{
	if (width >= 0) _width = width;
	else throw exception("Illigal value");
}

int Component::getHeight()
{
	return _height;
}

void Component::setHeight(int height)
{
	if (height >= 0) _height = height;
	else throw exception("Illigal value");
}

bool Component::isClicked(int x, int y)
{
	if (!_isVisible) return false;

	list<int> d = getOffset();
	int dx = d.front();
	int dy = d.back();

	return ((x >= (_x + dx)) && (x <= ((_x + dx) + _width))
		&& (y >= (_y + dy)) && (y <= ((_y + dy) + _height)));
}


Component::~Component()
{
}

list<int> Component::getOffset()
{
	list<int> d;
	int dx = 0;
	int dy = 0;
	d.emplace_front(dx);
	d.emplace_back(dy);

	Component* root = _parent;
	if (root == nullptr) return d;
	else {
		d.emplace_front(d.front() + root->_x);
		d.emplace_back(d.back() + root->_y);
	}

	while (1) {
		if (root->_parent != nullptr) {
			root = root->_parent;
			d.emplace_front(d.front() + root->_x);
			d.emplace_back(d.back() + root->_y);
		}
		else break;
	}
	return d;
}
