#ifndef _Common_H
#define _Common_H

#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;
class _Common {
public: 
	static void resizeConsole(int, int);
	static void fixConsoleWindow();
	static void gotoXY(int, int);
	static void textColor(int);
	static void backGround(int left, int top, int wide, int height, int color);
};
#endif