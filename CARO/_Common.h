#ifndef _Common_H
#define _Common_H

#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;
class _Common {
public:
	// Đặt lại kích thước màn hình 
	static void resizeConsole(int, int);
	// Cố định kích thước màn hình
	static void fixConsoleWindow();
	// Di chuyển đến tọa độ (x,y) trên màn hình
	static void gotoXY(int, int);
	// Tô màu ký tự 
	static void textColor(int);
	// Vẽ hình chữ nhật << Left: lề trái, Top: Lề trên, Wide: chiều rộng, Height: Chiều cao, Color: Màu >> 
	static void backGround(int left, int top, int wide, int height, int color);
	// Vẽ chéo phụ
	static void cheoTrai(int left, int top, int dai, int cao, int color);
	// Vẽ chéo chính
	static void cheoPhai(int left, int top, int dai, int cao, int color);
	// Vẽ đường thẳng ngang
	static void veNgang(int left, int top, int dai, int color);
	// Vẽ đường thẳng dọc
	static void veDoc(int left, int top, int dai, int color);
public:
	// Vẽ viền trái
	static void drawSlideLine(int, int, char, int);
	// Vẽ viền phải
	static void drawUpLine(int, int, char, char, char, int);

};
#endif