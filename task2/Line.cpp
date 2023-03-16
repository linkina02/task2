#include "Component.h"
#include "Line.h"

Line::Line() :Component()
{
}

Line::Line(int x1, int y1, int x2, int y2) {
    setStartPoint(x1, y1);
    setEndPoint(x2, y2);
}

void Line::setStartPoint(int x, int y) {
    if (x >= 0 && y>=0)
    { 
        startX = x;
        startY = y;
    }
    else throw exception("Illigal value");
   
}

void Line::setEndPoint(int x, int y) {
    if (x >= 0 && y >= 0)
    {
        endX = x;
        endY = y;
    }
    else throw exception("Illigal value");
}

string Line::toString()
{
	string res;

	res += getName() + "[id = " + to_string(_id) + ", pos = ((" + to_string(startX) + ", " + to_string(startY)
		+ "), (" + to_string(endX) + ", " + to_string(endY) + ")), ";
	if (_isVisible)
		res += "visible = true, ";
	else res += "visible = false, ";
	if (_parent != nullptr)
		res += "par_id = " + to_string(_parent->getId()) + "] ";
	return res;
}

void Line::move(int x1, int y1, int x2, int y2)
{
    setStartPoint(x1, y1);
    setEndPoint(x2, y2);
}

bool Line::isClicked(int x, int y)
{
    if (!_isVisible) return false;
    return (((x - startX) * (endY - startY)) == ((y - startY) * (endX - startX)));
}

Line::~Line()
{
}

