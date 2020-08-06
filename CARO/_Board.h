#ifndef _Board_H
#define _Board_H
#include "_Menu.h"
#include "_Point.h"
#include "_Common.h"
// Mang diem tan cong phong thu cho may kho
const  long Defend_Score1[7] = { 0, 8, 512, 32768, 2097152, 134217728 };
const  long Attack_Score1[7] = { 0, 64, 4096, 262144, 16777216, 1073741824 };
// Mang diem tan cong phong thu cho may de
const  long Defend_Score2[7] = { 1, 2, 3, 1, 1, 1 };
const  long Attack_Score2[7] = { 2, 3, 4, 5, 6, 7 };

class _Board : public _Point, public _Menu{
	int _size;
	int _left, _top;
	int cdraw = 0;
	_Point** _pArr;
	int _cdraw = 0;
	//ve vien trai phai
	void drawSlideLine(int, int, char,int);
	//Ve vien tren duoi
	void drawUpLine(int, int,char,char,char,int);
	
public:
	//Contructor & destructor menthod
	_Board();
	_Board(int, int, int);
	~_Board();
public:
	//Bacsic menthod
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	void resetData();
	void drawBoard();
public:
	int checkBoard(int, int, bool);
	int testBoard(int,int,bool);
	bool checkRow(int, int);
	bool checkColum(int, int);
	bool checkMainDioganal(int, int);
	bool checkSubDioganal(int, int);
	bool checkDraw();
	int getCDraw();
	_Point& getParr(int,int);
public:
	//Choi
	_Point findTheBestMove_1(); // Tim nuoc di kho
	_Point findTheBestMove_2(); // Tm nuoc di de 
	long SoDiemTanCong_DuyetDoc(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemTanCong_DuyetNgang(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemTanCong_DuyetCheo1(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemTanCong_DuyetCheo2(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemPhongThu_DuyetDoc(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemPhongThu_DuyetNgang(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemPhongThu_DuyetCheo1(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemPhongThu_DuyetCheo2(long, long, const long Defend_Score[], const long Attack_Score[]);
	
};
#endif