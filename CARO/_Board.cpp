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
	_Common::textColor(240);
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
_Point& _Board::getParr(int i, int j)
{
	return _pArr[i][j];
}

//=======================================================================================================

//Tan cong duyet ngang 
long _Board::SoDiemTanCong_DuyetNgang(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempNgang = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < _size; iDem++)
	{
		if (_pArr[Dong][Cot + iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong][Cot + iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong][Cot + iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong][Cot + iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong][Cot + iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
	{
		if (_pArr[Dong][Cot - iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong][Cot - iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong][Cot - iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong][Cot - iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong][Cot - iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempNgang += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempNgang += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempNgang += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempNgang += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempNgang -= 1;
	else
		iScoreTempNgang -= 2;
	if (iSoQuanTa == 4)
		iScoreTempNgang *= 2;
	if (iSoQuanTa == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich2];
	return iScoreTempNgang;
}
// Tan cong Duyet doc
long _Board::SoDiemTanCong_DuyetDoc(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempDoc = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong + iDem][Cot].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong + iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong + iDem2][Cot].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot].getCheck() == 0)
					break;
			}
			break;
		}

	}

	for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong - iDem][Cot].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong - iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong - iDem2][Cot].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}

	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempDoc += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempDoc += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempDoc += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempDoc += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempDoc -= 1;
	else
		iScoreTempDoc -= 2;
	if (iSoQuanTa == 4)
		iScoreTempDoc *= 2;
	if (iSoQuanTa == 0)
		iScoreTempDoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempDoc += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempDoc += Defend_Score[iSoQuanDich2];
	return iScoreTempDoc;
}
// Tan cong Duyet cheo chinh
long _Board::SoDiemTanCong_DuyetCheo1(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempCheoNguoc = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < _size && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < _size && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempCheoNguoc -= 1;
	else
		iScoreTempCheoNguoc -= 2;
	if (iSoQuanTa == 4)
		iScoreTempCheoNguoc *= 2;
	if (iSoQuanTa == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich2];
	return iScoreTempCheoNguoc;
}
//Tan cong Duyet cheo phu
long _Board::SoDiemTanCong_DuyetCheo2(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempCheoXuoi = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	for (int iDem = 1; iDem < 6 && Cot + iDem < _size && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < _size && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempCheoXuoi -= 1;
	else
		iScoreTempCheoXuoi -= 2;
	if (iSoQuanTa == 4)
		iScoreTempCheoXuoi *= 2;
	if (iSoQuanTa == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich2];
	return iScoreTempCheoXuoi;
}
// Phong thu duyet doc
long _Board::SoDiemPhongThu_DuyetDoc(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempDoc = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong + iDem][Cot].getCheck() == -1)
			iSoQuanDich++;
		if (_pArr[Dong + iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot].getCheck() == -1)
					iSoQuanDich2++;
				if (_pArr[Dong + iDem2][Cot].getCheck() == 0)
					break;
			}
			break;
		}
	}
	for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong - iDem][Cot].getCheck() == -1)
			iSoQuanDich++;
		if (_pArr[Dong - iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot].getCheck() == -1)
					iSoQuanDich2++;
				if (_pArr[Dong - iDem2][Cot].getCheck() == 0)
					break;
			}
			break;
		}
	}


	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempDoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempDoc += Defend_Score[iSoQuanDich];
	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempDoc -= 1;
	else
		iScoreTempDoc -= 2;
	if (iSoQuanDich == 4)
		iScoreTempDoc *= 2;
	return iScoreTempDoc;
}
// Phong thu duyet ngang
long _Board::SoDiemPhongThu_DuyetNgang(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempNgang = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < _size; iDem++)
	{
		if (_pArr[Dong][Cot + iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong][Cot + iDem].getCheck() == -1)
			iSoQuanDich++;
		if (_pArr[Dong][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong][Cot + iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong][Cot + iDem2].getCheck() == -1)
					iSoQuanDich2++;
				if (_pArr[Dong][Cot + iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
	{
		if (_pArr[Dong][Cot - iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong][Cot - iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong][Cot - iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong][Cot - iDem2].getCheck() == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong][Cot - iDem].getCheck() == -1)
			iSoQuanDich++;
	}

	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich];
	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempNgang -= 1;
	else
		iScoreTempNgang -= 2;
	if (iSoQuanDich == 4)
		iScoreTempNgang *= 2;
	return iScoreTempNgang;
}
// Phong thu cheo chinh
long _Board::SoDiemPhongThu_DuyetCheo1(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{

	long iScoreTempCheoNguoc = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < _size && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < _size && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == -1)
			iSoQuanDich++;
	}

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}

		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}

				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == -1)
			iSoQuanDich++;
	}
	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich];
	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempCheoNguoc -= 1;
	else
		iScoreTempCheoNguoc -= 2;
	if (iSoQuanDich == 4)
		iScoreTempCheoNguoc *= 2;
	return iScoreTempCheoNguoc;
}
//Phong thu cheo phu
long _Board::SoDiemPhongThu_DuyetCheo2(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempCheoXuoi = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == -1)
			iSoQuanDich++;
	}

	for (int iDem = 1; iDem < 6 && Cot + iDem < _size && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem < 7 && Cot + iDem2 < _size && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == -1)
			iSoQuanDich++;
	}


	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich];

	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempCheoXuoi -= 1;
	else
		iScoreTempCheoXuoi -= 2;
	if (iSoQuanDich == 4)
		iScoreTempCheoXuoi *= 2;
	return iScoreTempCheoXuoi;
}

//Tim nuoc di cho may (kho)
_Point _Board::findTheBestMove_1()
{
	_Point curentCell;
	int row = 0, colum = 0;
	long Diem = 0;
	for (int i = 0; i < _size-1; i++)
	{
		for (int j = 0; j < _size-1; j++)
		{
			long DiemTanCong = 0;
			long DiemPhongThu = 0;
			if (_pArr[i][j].getCheck() == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						row = i;
						colum = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						row = i; 
						colum = j;
					}
				}
			}
		}
	}
	curentCell.setX(_left + colum * 4 + 2);
	curentCell.setY(_top + row * 2 + 1);
	return curentCell;
}
_Point _Board::findTheBestMove_2()
{
	_Point curentCell;
	int row = 0, colum = 0;
	long Diem = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			long DiemTanCong = 0;
			long DiemPhongThu = 0;
			if (_pArr[i][j].getCheck() == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);

				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						row = i;
						colum = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						row = i;
						colum = j;
					}
				}
			}
		}
	}
	curentCell.setX(_left + colum * 4 + 2);
	curentCell.setY(_top + row * 2 + 1);
	return curentCell;
}
