#include "_Board.h"
int _Board::getSize()
{
	return _size;
}
int _Board::getLeft()
{
	return _left;
}
int _Board::getTop()
{
	return _top;
}
int _Board::getXAt(int i, int j)
{
	return _pArr[i][j].getX();
}
int _Board::getYAt(int i, int j)
{
	return _pArr[i][j].getY();
}
_Board::_Board(int pSize, int pX, int pY)
{
	_size = pSize;
	_left = pX;
	_top = pY;
	_pArr = new _Point * [pSize];
	for (int i = 0; i < pSize; i++) _pArr[i] = new _Point[pSize];
}
_Board::~_Board() {
	for (int i = 0; i < _size; i++) delete[] _pArr[i];
	delete[] _pArr;
}
void _Board::resetData() {
	if (_size == 0) return;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_pArr[i][j].setX(4 * j + _left + 2);
			_pArr[i][j].setY(2 * i + _top + 1);
			_pArr[i][j].setCheck(0);
		}
	}
}
void _Board::drawBoard() {
	//Ve ban co ne 
	if (_pArr == NULL) return;
	for (int i = 0; i <= _size; i++) {
		for (int j = 0; j <= _size; j++) {
			_Common::gotoXY(_left + 4 * i, _top + 2 * j);
			printf(".");
		}
	}
	_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());
	//Ve cai bang nho nho xinh xinh ben canh ban co
		

}
int _Board::checkBoard (int pX, int pY, bool pTurn) {
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
			{
				if (pTurn) _pArr[i][j].setCheck(-1);
				else _pArr[i][j].setCheck(1);
				return _pArr[i][j].getCheck();
			}
		}				
	}	
}
//Kiem tra hang
bool _Board:: checkRow(int pX, int pY)
{
	int countLeft = 0;
	int countRight = 0;
	int key = _pArr[pX][pY].getCheck();
	bool flag = true;
	int i = pX;
	return false;
}
////Kiem tra ben phai
//bool _Board::checkColum(int pX, int pY)
//{
//	int countLeft = 0;
//	int countRight = 0;
//	int key = _pArr[pX][pY].getCheck();
//	for (int i = pY; i >= 0; i--)
//	{
//		if (_pArr[pX][i].getCheck() == key)
//			countLeft++;
//		else break;
//	}
//	for (int i = pY+1 + 1; i <= _size; i++)
//	{
//		if (_pArr[pX][i].getCheck() == key)
//			countRight++;
//		else break;
//	}
//	return (countLeft + countRight) == 5;
//	return false;
//	
//}
////Kiem tra cheo chinh
//bool _Board::checkMainDioganal(int pX, int pY)
//{
//	int countLeft = 0;
//	int countRight = 0;
//	int key = _pArr[pX][pY].getCheck();
//	for (int i = pY; i >= 0; i--)
//	{
//		if (_pArr[i][i].getCheck() == key)
//			countLeft++;
//		else break;
//	}
//	for (int i = pY + 1 + 1; i <= _size; i+=4)
//	{
//		if (_pArr[i][i].getCheck() == key)
//			countRight++;
//		else break;
//	}
//	return (countLeft + countRight) == 5;
//	return false;
//}
////Kiem tra cheo phu
//bool _Board::checkSubDioganal(int pX, int pY)
//{
//	int countLeft = 0;
//	int countRight = 0;
//	int key = _pArr[pX][pY].getCheck();
//	for (int i = pX; i >= 0; i--)
//	{
//		if (_pArr[i][_size - i + 1].getCheck() == key)
//			countLeft++;
//		else break;
//	}
//	for (int i = pX; i <= _size; i++)
//	{
//		if (_pArr[i][_size -i + 1].getCheck() == key)
//			countRight++;
//		else break;
//	}
//	return (countLeft + countRight) == 5;
//	return false;
//}
int _Board::testBoard(int pX, int pY, bool pturn) { 
	//Kiem tra theo dong
	//-1: player 1 win, 1: player 2 win, 0: hoa, 2 binh thuong.
	
	if (checkRow(pX, pY) == true)
	{
		if (pturn) return -1;
		else return 1;
	}
	
	return 2;
}
_Board::_Board(){
	_left = 0;
	_top = 0;
	_size = 0;
	_pArr = nullptr;
};