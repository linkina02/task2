#pragma once
#include "Component.h"

class Line :
    public Component
{
private:
    int startX;
    int startY;
    int endX;
    int endY;
public:
    Line();
    Line(int x1, int y1, int x2, int y2);
    ~Line();
    void setStartPoint(int x, int y);
    void setEndPoint(int x, int y);
    string toString() override;
    void move(int x1, int y1, int x2, int y2);
    bool isClicked(int x, int y) override;

};