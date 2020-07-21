#include "_Menu.h"
//Nhap su lua chon
void _Menu::setChoice()
{
	char key = 0;
	char h = 16;
	while (key != 13)
	{
		move(key);
	}
	if (_x == 70 && _y == 13)
		_choice = 1;	
	else if (_x == 70 && _y == 14)
		_choice = 2;
	else if (_x == 70 && _y == 15)
		_choice = 3;
	else if (_x == 70 && _y == 16)
		_choice = 4;
	else if (_x == 70 && _y == 17)
		_choice = 5;
	else {
		_x = 70; _y = 13;
		gotoXY(_x, _y);
	}
}
//Xuat ra 1 so int, 1: new game, 2 :load game, 3: save game, 4: Luat choi, 5: thoat
int _Menu::getChoice()
{
	return _choice;
}
_Menu::_Menu()
{
	_choice = 0;
	_x = 0;
	_y = 0;
}
void _Menu::textColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void _Menu::displayMenu()
{
	_Common::textColor(11);
	//in thanh ngang tren
	int n = 30;
	for (int x = 120; x >= 75; x--) {
		Sleep(20);
		gotoXY(x, 1);
		char a = 196;// ky tu "_"
		if (x == 120)
		{
			char temp = 191;
			cout << temp;
		}
		else{ cout << a; }
		
		gotoXY(n, 1);
		if (n == 30)
		{
			char temp = 218;
			cout << temp;
		}
		else 
		{cout << a;}	
		n++;
	}
	cout << endl;
	for (int y = 2; y <= 20; y++) {
		if (y == 3)cout << "" << endl;
		if (y == 4)cout << "" << endl;
		if (y == 5)cout << "" << endl;
		if (y == 6)cout << "" << endl;
		if (y == 7)cout << "" << endl;
		if (y == 8)cout << "" << endl;
		if (y == 9)cout << "";
		
		Sleep(20);
		gotoXY(30, y);
		char const c = 179;
		cout << c;
		gotoXY(120, y);
		cout << c;
		gotoXY(2, y);
	}
	n = 120;
	for (int x = 30; x <= 75; x++) {
		Sleep(20);
		gotoXY(x,20);
		char c = 196;
		if (x == 30)
		{
			char temp = 192;
			cout << temp;
		}
		else { cout << c; }		
		gotoXY(n,20);
		if (n == 120)
		{
			char temp = 217;
			cout << temp;
		}
		else { cout << c; }	
		n--;
	}
	int x = 70;
	gotoXY(x, 13);
	char h = 16;
	cout << h << " NEWGAME";
	gotoXY(x, 14);
	cout << h << " LOAD GAME";
	gotoXY(x, 15);
	cout << h << " SAVE GAME";
	gotoXY(x, 16);
	cout << h << " RULE";
	gotoXY(x, 17);
	cout << h << " QUIT";
	_x = 70; _y = 13;
	gotoXY(_x, _y);
}
void _Menu::move(char &key)
{
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case 97:  {_x--;  gotoXY(_x, _y); break; }
		case 115: {_y++;  gotoXY(_x, _y); break; }
		case 100: {_x++;  gotoXY(_x, _y); break; }
		case 119: {_y--;  gotoXY(_x, _y); break; }
		}
	}
}
	  



