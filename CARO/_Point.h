#ifndef _Point_H
#define _Point_H
#include <iostream>
class _Point {
	int _x, _y, _check;
	
public:
	_Point();
	_Point(int, int);
	bool setCheck(int); // Đặt trạng thái bàn cờ
	int getCheck();// Đọc trạng thái bàn cờ 
	int getX();// Đọc tọa độ theo trục X
	int getY();// Đọc tọa độ theo trục Y
	void setX(int);// Thiết lâp tọa độ X
	void setY(int); // Thiêt lập tọa độ Y
	
};
#endif