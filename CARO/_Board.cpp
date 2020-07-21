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
	return 0;
}
//Kiem tra hang ( i hang va j cot)
bool _Board::checkRow(int i, int j)
{
	int countLeft = 0;
	int countRight = 0;
	for (int k = j; k >= 0; k--)
	{
		if (_pArr[i][k].getCheck() == _pArr[i][j].getCheck())
			countLeft++;
		else break ;
	}
	for (int k = j + 1; k <= getSize(); k++)
	{
		if (_pArr[i][k].getCheck() == _pArr[i][j].getCheck())
			countRight++;
		else break;
	}
	if (countLeft + countRight == 5) return true;
	return false;
}
//Kiem tra cot ( i hang va j cot)
bool _Board :: checkColum(int i, int j)
{
	int countLeft = 0;
	int countRight = 0;
	for (int k = j; k >= 0; k--)
	{
		if (_pArr[k][j].getCheck() == _pArr[i][j].getCheck())
			countLeft++;
		else break;
	}
	for (int k = j + 1; k <= getSize(); k++)
	{
		if (_pArr[k][j].getCheck() == _pArr[i][j].getCheck())
			countRight++;
		else break;
	}
	if (countLeft + countRight == 5) return true;
	return false;
}

//Kiem tra tren cheo chinh (i hang va j cot)
bool _Board::checkMainDioganal(int i, int j)
{
	int countLeft = 0;
	int countRight = 0;
	int l = j; // moi lan lap lai se giam di 1 va the vao j ( kiem tra ben trai)
	int l_1 = j + 1;// moi lan lap lai se tang them 1 va the vao j ( kiem tra ben phai)
	for (int k = i; k >= 0; k--)
	{
		if (_pArr[k][l].getCheck() == _pArr[i][j].getCheck())
		{
			l--;
			countLeft++;
		}
		
		else
			break;
	}
	for (int k = i + 1; k <= _size; k++)
	{
		if (_pArr[k][l_1].getCheck() == _pArr[i][j].getCheck())
		{
			l_1++;
			countRight++;
		}
		
		else break;
	}
	if (countLeft + countRight == 5) return true;
	return false;
}
//kiem tra duong cheo phu
bool _Board::checkSubDioganal(int i, int j)
{
	int countLeft = 0;
	int countRight = 0;
	int l = j; // moi lan lap lai se tang them 1 va the vao j ( kiem tra ben trai)
	int l_1 = j - 1;// moi lan lap lai se giam them 1 va the vao j ( kiem tra ben phai)
	for (int k = i; k >= 0; k--)
	{
		if (_pArr[k][l].getCheck() == _pArr[i][j].getCheck())
		{
			l++;
			countLeft++;
		}

		else
			break;
	}
	for (int k = i + 1; k <= _size; k++)
	{
		if (_pArr[k][l_1].getCheck() == _pArr[i][j].getCheck())
		{
			l_1--;
			countRight++;
		}

		else break;
	}
	if (countLeft + countRight == 5) return true;
	return false;
}
int _Board::testBoard(int i, int j, bool pturn) { 
	//-1: player 1 win, 1: player 2 win, 0: hoa, 2 binh thuong.
	if (checkRow(i, j) == true || checkColum(i,j) == true || checkMainDioganal(i,j) == true || checkSubDioganal(i,j) == true)
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