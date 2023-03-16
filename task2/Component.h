#pragma once
#include <string>
#include <list>
using namespace std;

class Component
{
private:
	static int _idCounter;
	list<int> getOffset();
protected:
	int _id;
	int _width;
	int _height;
	int _x;
	int _y;
public:
	Component();
	Component(int x, int y);
	Component(int x, int y, int width, int height);
	~Component();
	bool _isVisible;
	Component* _parent;
	void move(int x, int y);
	virtual bool isClicked(int x, int y);
	void onClick(int x, int y);
	virtual string toString();
	string getName();
	int getId();
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getWidth();
	void setWidth(int width);
	int getHeight();
	void setHeight(int height);
};

