#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "_Common.h"
#include <thread>
using namespace std;

class _Menu{
	int _choice;
	int _x, _y;
public:
	_Menu();
	// Thiết lập chế độ chơi
	void setChoice();
	// Đọc chế độ chơi
	int getChoice();
	// In Menu ra màn hình
	void displayMenu();
	void print();
	void printOptions(int X,int Y,char h);
	void printOptions_2(int X, int Y, char h);
	void printOptions_3(int X, int Y, char h);
	void printOptions_4(int X, int Y, char h);
	void printOptions_5(int X, int Y, char h);
	void printOptions_6(int X, int Y, char h);
	static void PlayBackSound();
	// Ẩn con trỏ
	static void hidePtr();
	// Hiện con trỏ
	static void showPtr();
};