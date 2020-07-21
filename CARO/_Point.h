#ifndef _Point_H
#define _Point_H
#include <iostream>
class _Point {
	int _x, _y, _check;
public:
	_Point();
	_Point(int, int);
	bool setCheck(int);
	int getCheck();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
};
#endif