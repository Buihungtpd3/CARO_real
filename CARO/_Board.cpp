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
	_pArr = new _Point * [pSize+1];
	for (int i = 0; i <= pSize; i++) _pArr[i] = new _Point  [pSize];
}
_Board::~_Board() {
	for (int i = 0; i < _size; i++) delete[] _pArr[i];
	delete[] _pArr;
}
void _Board::resetData() {
	if (_size == 0) return;
	//Ve ban co, co i hang va j cot ( j <=> x, i <=> y)
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_pArr[i][j].setX(4 * j + _left + 2);
			_pArr[i][j].setY(2 * i + _top + 1);
			_pArr[i][j].setCheck(0);
		}
	}
}
//Ham ve vien tren , duoi ========================================================================
void _Board::drawUpLine(int left, int top, char symbol1,char symbol2, char symbol3,int size)
{
	_Common::gotoXY(left, top);//Dua con tro den vi tri dau ban co
	for (int i = 0; i <= size * 4; i++)
	{
		if (i == 0) cout << symbol1;//218 la ma ascii cua goc vuong ben trai phia tren
		else if (i == size * 4) cout <<symbol2;//191 la ma ascii cua goc vuong phai phia tren
		else cout << symbol3;
	}
}

//Ham ve vien trai, phai =============================================================================
void _Board::drawSlideLine(int left, int top, char symbol, int size)
{
	_Common::gotoXY(left, top);
	for (int i = 0; i < size * 2 - 1; i++)
	{
		_Common::gotoXY(left, i + top + 1);
		cout << symbol;
	}
}
void _Board::drawBoard() {
	//Ve ban co
	if (_pArr == NULL) return;
	for (int i = 0; i <= _size; i++) {
		
		for (int j = 0; j <= _size; j++) {
			
			_Common::gotoXY(_left + 4 * i, _top + 2 * j);
			printf(".");
		}
	}
	//Ve vien (char + so  la ky tu dac biet trong ascii)
	drawUpLine(_left, _top, (char)218, (char)191, (char)196, _size);//Ve vien tren
	drawSlideLine(_left + 4 * _size, _top, (char)179, _size);//Ve vien ben phai
	drawUpLine(_left, _top + _size * 2,(char) 192, (char)217, (char)196,_size);//Ve vien duoi
	drawSlideLine(_left, _top, (char)179,_size);//Ve vien ben trai
	//Ve cai bang nho nho xinh xinh ben canh ban co
	drawUpLine(_left + _size*4+20, _top +10, (char)201, (char)187, (char)205, 10);//Ve vien tren
	drawSlideLine(_left + _size*4+20+40, _top+10, (char)186, 6);//Ve vien ben phai
	drawUpLine(_left + _size * 4 + 20, _top + 6 * 2 +10, (char)200, (char)188, (char)205, 10);//Ve vien duoi
	drawSlideLine(_left+_size*4+20, _top+10, (char)186, 6);//Ve vien ben trai
	//In cai bang
	_Common::textColor(9);
	gotoXY(_left + _size * 4 + 30, _top + 12);
	cout << "PLAYER 1";
	gotoXY(_left + _size * 4 + 48, _top + 12);
	cout << "PLAYER 2";
	gotoXY(_left + _size * 4 + 22, _top + 14);
	cout << "Turn:";
	gotoXY(_left + _size * 4 + 22, _top + 16);
	cout << "PRESS L TO SAVE GAME";
	gotoXY(_left + _size * 4 + 22, _top + 18);
	cout << "PRESS ESC TO EXIT GAME"; 
	_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());
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
	int Exception = 0;
	for (int k = j; k >= 0; k--)
	{
		if (_pArr[i][k].getCheck() == _pArr[i][j].getCheck())
			countLeft++;
		else
		{
			if (_pArr[i][k].getCheck() != 0)
				Exception++;
			break;
		}
	}
	for (int k = j + 1; k <= getSize(); k++)
	{
		if (_pArr[i][k].getCheck() == _pArr[i][j].getCheck())
			countRight++;
		else
		{
			if (_pArr[i][k].getCheck() != 0)
				Exception++;
			break;
		}
	}
	if (countLeft + countRight >= 5 and Exception != 2 ) return true;
	return false;
}
//Kiem tra cot ( i hang va j cot)
bool _Board :: checkColum(int i, int j)
{
	int countLeft = 0;
	int countRight = 0;
	int Exception = 0;
	for (int k = j; k >= 0; k--)
	{
		if (_pArr[k][j].getCheck() == _pArr[i][j].getCheck())
			countLeft++;
		else
		{
			if (_pArr[k][j].getCheck() != 0)
				Exception++;
			break;
		}
	}
	for (int k = j + 1; k <= getSize(); k++)
	{
		if (_pArr[k][j].getCheck() == _pArr[i][j].getCheck())
			countRight++;
		else
		{
			if (_pArr[k][j].getCheck() != 0)
				Exception++;
			break;
		}
	}
	if (countLeft + countRight >= 5 and Exception != 2) return true;
	return false;
}

//Kiem tra tren cheo chinh (i hang va j cot)
bool _Board::checkMainDioganal(int i, int j)
{
	int countLeft = 0;
	int countRight = 0;
	int Exception = 0;
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
		{
			if (_pArr[k][l].getCheck() != 0)
				Exception++;
			break;
		}
	}
	for (int k = i + 1; k <= _size; k++)
	{
		if (_pArr[k][l_1].getCheck() == _pArr[i][j].getCheck())
		{
			l_1++;
			countRight++;
		}
		
		else
		{
			if (_pArr[k][l_1].getCheck() != 0)
				Exception++;
			break;
		}
	}
	if (countLeft + countRight >= 5 and Exception != 2) return true;
	return false;
}
//kiem tra duong cheo phu
bool _Board::checkSubDioganal(int i, int j)
{
	int countLeft = 0;
	int countRight = 0;
	int Exception = 0;
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
		{
			if (_pArr[k][l].getCheck() != 0)
				Exception++;
			break;
		}
	}
	for (int k = i + 1; k <= _size; k++)
	{
		if (_pArr[k][l_1].getCheck() == _pArr[i][j].getCheck())
		{
			l_1--;
			countRight++;
		}

		else
		{
			if (_pArr[k][l_1].getCheck() != 0)
				Exception++;
			break;
		}
	}
	if (countLeft + countRight >= 5 and Exception != 2) return true;
	return false;
}
int _Board::testBoard(int i, int j, bool pturn) { 
	//kiem tra thang thua va tra lai ket qua : -1: player 1 win, 1: player 2 win, 0: hoa, 2 binh thuong.
	_cdraw++;
	if (checkRow(i, j) == true || checkColum(i,j) == true || checkMainDioganal(i,j) == true || checkSubDioganal(i,j) == true)
	{
		if (pturn) return -1; // X win
		else return 1;// O win
	}
	if (checkDraw())
		return 0;
	return 2;
}
_Board::_Board(){
	_left = 0;
	_top = 0;
	_size = 0;
	_pArr = nullptr;
};
bool _Board::checkDraw()
{
	if (_cdraw == 400) return true;
	return false;
}
int _Board::getCDraw()
{
	return _cdraw;
}
int _Board::getScore(int i, int j, int depth)
{
	if (checkRow(i, j) == true || checkColum(i, j) == true || checkMainDioganal(i, j) == true || checkSubDioganal(i, j) == true)
	{
		if (_pArr[i][j].getCheck() == -1) return -10 + depth;
		else if (_pArr[i][j].getCheck() == 1) return 10 - depth;
	}
	return 0;
}
//Thay doi trang thai quan co tai 1 o bat ky
void _Board::setCheckOnBoard(int i, int j, int value)
{
	_pArr[i][j].setCheck(value);
}
int _Board::getCheckOnBoard(int i, int j)
{
	return _pArr[i][j].getCheck();
}
_Point** _Board::getParr()
{
	return _pArr;
}

int _Board ::Minimax(int i, int j, int depth, int a, int b, bool isMax)
{
	if (depth == 0 || getCDraw() == getSize() * getSize())
	{
		int Score = getScore(i, j, depth);
		return Score;
	}
	if (isMax)
	{
		int maxEval = INT_MIN;
		for (int k = 0; k < getSize(); k++)
			for (int h = 0; h < getSize(); h++)
			{
				if (_pArr[k][h].getCheck() == 0)
				{
					_pArr[k][h].setCheck(1);//Tao nuoc di gia
					int evaluation = Minimax(k, h, depth - 1, a, b, !isMax);
					maxEval = max(maxEval, evaluation);
					a = max(maxEval, evaluation);
					if (b <= a) break;
					_pArr[k][h].setCheck(0);//Tra ve nhu cu
				}
			}
		return maxEval;
	}
	else
	{
		int minEval = INT_MAX;
		for (int k = 0; k < getSize(); k++)
			for (int h = 0; h < getSize(); h++)
			{
				if (_pArr[k][h].getCheck() == 0)
				{
					_pArr[k][h].setCheck(-1);//Tao nuoc di gia
					int evaluation = Minimax(k, h, depth - 1, a, b, !isMax);
					minEval = min(minEval, evaluation);
					b = min(minEval, evaluation);
					if (b <= a) break;
					_pArr[k][h].setCheck(0);//Tra ve nhu cu
				}
			}
		return minEval;
	}
}
void _Board :: findThebestMove(int*& result)
{
	int bestMove = INT_MIN;
	int moveVal = 0;
	int depth = 10;
	int a = INT_MIN;
	int b = INT_MAX;
	bool isMax = true;

	for (int i = 0; i < getSize(); i++)
	{
		for (int j = 0; j < getSize(); j++)
		{
			if (_pArr[i][j].getCheck() != 0)
			{
				_pArr[i][j].setCheck(1);
				moveVal = Minimax(i, j, depth, a, b, isMax);
				_pArr[i][j].setCheck(0);
			}
			if (moveVal > bestMove)
			{
				bestMove = moveVal;
				*result = i;
				*(result + 1) = j;
			}
		}
	}
	result[0] = 10;
	result[1] = 10;

}