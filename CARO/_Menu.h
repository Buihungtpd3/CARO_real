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
	void printCaro();
	void printOptions();
	void hidePtr();
	void showPtr();
};