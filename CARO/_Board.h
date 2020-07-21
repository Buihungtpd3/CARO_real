#ifndef _Board_H
#define _Board_H
#include "_Menu.h"
#include "_Point.h"
#include "_Common.h"

class _Board : public _Point, public _Menu{
	int _size;
	int _left, _top;
	_Point** _pArr;
public:
	_Board();
	_Board(int, int, int);
	~_Board();
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	int testBoard(int,int,bool);
	bool checkRow(int, int);
	bool checkColum(int, int);
	bool checkMainDioganal(int, int);
	bool checkSubDioganal(int, int);

};
#endif