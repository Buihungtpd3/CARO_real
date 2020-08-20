#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "_Common.h"
using namespace std;

class _Menu : public _Common{
	int _choice;
	int _x, _y;
public:
	_Menu();
	void setChoice();
	int getChoice();
	void displayMenu();
	void print();
	void printOptions(int X,int Y,char h);
	void printOptions_2(int X, int Y, char h);
	void printOptions_3(int X, int Y, char h);
	void printOptions_4(int X, int Y, char h);
	void printOptions_5(int X, int Y, char h);
	void printOptions_6(int X, int Y, char h);
	void hidePtr();
	void showPtr();
};