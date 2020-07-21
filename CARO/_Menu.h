#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "_Common.h"


class _Menu : public _Common{
	int _choice;
	int _x, _y;
public:
	_Menu();
	void setChoice();
	int getChoice();
	void displayMenu();
	void textColor(int);
	void move(char&);
};