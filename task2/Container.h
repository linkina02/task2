#pragma once
#include <string>
#include <list>
#include "component.h"
using namespace std;

class Container :public Component
{
protected:
	list<Component*> _components;
	void setSize();
public:
	Container();
	Container(int x, int y);
	Container(int x, int y, int width, int height);
	~Container();
	void addComponent(Component* component);
	list<Component*> getComponents();
	Component* findChildById(int id);
	void onClick(int x, int y);
};


