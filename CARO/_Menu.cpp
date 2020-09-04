#include "_Menu.h"
#include <mmsystem.h>
#include <iostream>
#include <Windows.h>
//Nhap su lua chon
void _Menu::setChoice()
{
	PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
	int X = 100; int Y = 23;
	if (_x == X && _y == Y)
		_choice = 1;
	else if (_x == X && _y == Y+1)
		_choice = 2;
	else if (_x == X && _y == Y+2)
		_choice = 3;
	else if (_x == X && _y == Y+3)
		_choice = 4;
	else if (_x == X && _y == Y+4)
		_choice = 5;
	else if (_x == X && _y == Y+5)
		_choice = 6;
	else {
		_x = X; _y = Y;
		_Common::gotoXY(_x, _y);
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

void _Menu::displayMenu()
{
	_Common::textColor(249);
	print();
}

void _Menu::print()
{
	char key;
	hidePtr();
	_Common::textColor(244);
	int mau = 4;
	_Common::backGround(32-5, 11, 110, 30, 128);
	_Common::backGround(30 -5, 10, 110, 30, 13);
	int X = 100;//Toa do option
	int Y = 23;//Toa do option
	int x = X -55;// Toa do chu Caro
	int y = Y - 5;// Toa do chu Caro
	printOptions(X , Y , char(248));
	_x = X;
	_y = Y;
	_Common::gotoXY(_x, _y);
	PlaySound(TEXT("intro2.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	while (true)
	{
		int color = 1 + rand() % (15 + 1 - 1);
		_Common::textColor(color);
		_Common::gotoXY(x, y); cout << "          _                          ";
		_Common::gotoXY(x, ++y); cout << "      ,:::::\\                         ";
		_Common::gotoXY(x, ++y); cout << "     /:::::::|                        ";
		_Common::gotoXY(x, ++y); cout << "    /:::' ::/                         ";
		_Common::gotoXY(x, ++y); cout << "   /:::'      _         __      ___   ";
		_Common::gotoXY(x, ++y); cout << "  /:::'     ,::::\\   /::::\\  / ._. \\  ";
		_Common::gotoXY(x, ++y); cout << " .:::'    /./:| |   |:/     /:/   \\:\\ ";
		_Common::gotoXY(x, ++y); cout << " |:::    /:/  |:|   |:|     |      |          ";
		_Common::gotoXY(x, ++y); cout << " [:::   /:/__ |:| / |:|     \\:\\._./:/ ";
		_Common::gotoXY(x, ++y); cout << " [:::   \\____/ \\_/  |:|      \\_____/  ";
		_Common::gotoXY(x, ++y); cout << " \\:::.          ,~~~~~~~,           ";
		_Common::gotoXY(x, ++y); cout << "  \\::::..  .:::::::::::::::::.        ";
		_Common::gotoXY(x, ++y); cout << "   \\_`::::::::`/``~~     ";
		_Common::gotoXY(x, ++y); cout << "     ~~~~~~~~  ";
		x = X-55; y = Y -5;
		Sleep(150);
		showPtr();
		if (_kbhit())
		{
			key = _getch();
			_Common::textColor(mau);

			if (key == 13) return;

			switch (key)
			{
			case 119:
			{
				//chen am thanh 
				//PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (_y >= 23 && _y <= 28) {
					_y--; _Common::gotoXY(_x, _y);
				}
				switch (_y)
				{
				case 23:
					{
					printOptions(X,Y,(char)248);
						break;
					}
				case 24: 
					{
					printOptions_2(X, Y, (char)248);
					
						break;
					}
				case 25:
					{
					printOptions_3(X, Y, (char)248);
					
						break;
					}
				case 26:
					{
					printOptions_4(X, Y, (char)248);
					
						break;
					}
				case 27:
					{
					printOptions_5(X, Y, (char)248);
					
						break;
					}
				case 28:
					{
					printOptions_6(X, Y, (char)248);
					
						break;
					}
				}
				break;
			}
			case 115:
			{
				//chen am thanh 
				//PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (_y >= 23 && _y <= 28) {
					_y++; _Common::gotoXY(_x, _y);
				}
				switch (_y)
				{
				case 23:
				{
					printOptions(X, Y, (char)248);
					
					break;
				}
				case 24:
				{
					printOptions_2(X, Y, (char)248);
					
					break;
				}
				case 25:
				{
					printOptions_3(X, Y, (char)248);
				
					break;
				}
				case 26:
				{
					printOptions_4(X, Y, (char)248);
					
					break;
				}
				case 27:
				{
					printOptions_5(X, Y, (char)248);
					
					break;
				}
				case 28:
				{
					printOptions_6(X, Y, (char)248);
					
					break;
				}
				}
				break;
			}

			}
			if (_y < 23 || _y > 28)
			{
				_x = 100 ; _y = 23;
				_Common::gotoXY(_x, _y);
				printOptions(_x, _y, (char)175);
			}
		}
	}
	return;
}
	  
void _Menu::printOptions(int X,int Y, char h)
{
	int x = X;
	int y = Y;
	_Common::gotoXY(x, y);
	
	_Common::textColor(26);
	cout << (char)175 << " NEWGAME";
	_Common::textColor(4);
	_Common::gotoXY(x, ++y);
	cout << h << " LOAD GAME";
	_Common::gotoXY(x, ++y);
	cout << h << " PLAY WITH PC (EASY)";
	_Common::gotoXY(x, ++y);
	cout << h << " PLAY WITH PC (HARD)";
	_Common::gotoXY(x, ++y);
	cout << h << " RULE";
	_Common::gotoXY(x, ++y);
	cout << h << " QUIT";

}
void _Menu::printOptions_2(int X, int Y, char h)
{
	int x = X;
	int y = Y;
	_Common::gotoXY(x, y);
	cout << h << " NEWGAME";
	_Common::gotoXY(x, ++y);
	//==============================
	_Common::textColor(26);
	cout << (char)175  << " LOAD GAME";
	_Common::textColor(4);
	//=======================================
	_Common::gotoXY(x, ++y);
	cout << h << " PLAY WITH PC (EASY)";
	_Common::gotoXY(x, ++y);
	cout << h << " PLAY WITH PC (HARD)";
	_Common::gotoXY(x, ++y);
	cout << h << " RULE";
	_Common::gotoXY(x, ++y);
	cout << h << " QUIT";
	
}
void _Menu::printOptions_3(int X, int Y, char h)
{
	int x = X;
	int y = Y;
	_Common::gotoXY(x, y);
	cout << h << " NEWGAME";
	_Common::gotoXY(x, ++y);

	cout << h <<" LOAD GAME";
	
	_Common::gotoXY(x, ++y);
	//==============================
	_Common::textColor(26);
	cout << (char)175 << " PLAY WITH PC (EASY)";
	_Common::textColor(4);
	//=======================================
	_Common::gotoXY(x, ++y);
	cout << h << " PLAY WITH PC (HARD)";
	_Common::gotoXY(x, ++y);
	cout << h << " RULE";
	_Common::gotoXY(x, ++y);
	cout << h << " QUIT";

	
}
void _Menu::printOptions_4(int X, int Y, char h)
{
	int x = X;
	int y = Y;
	_Common::gotoXY(x, y);
	cout << h <<" NEWGAME";
	_Common::gotoXY(x, ++y);
	cout << h <<" LOAD GAME";
	_Common::gotoXY(x, ++y);
	cout << h << " PLAY WITH PC (EASY)";
	_Common::gotoXY(x, ++y);
	//==============================
	_Common::textColor(26);
	cout << (char)175 << " PLAY WITH PC (HARD)";
	_Common::textColor(4);
	//=======================================
	_Common::gotoXY(x, ++y);
	cout << h << " RULE";
	_Common::gotoXY(x, ++y);
	cout << h << " QUIT";
	
	
}
void _Menu::printOptions_5(int X, int Y, char h)
{
	int x = X;
	int y = Y;
	_Common::gotoXY(x, y);
	cout << h <<" NEWGAME";
	_Common::gotoXY(x, ++y);

	cout << h << " LOAD GAME";
	
	_Common::gotoXY(x, ++y);
	cout << h << " PLAY WITH PC (EASY)";
	_Common::gotoXY(x, ++y);
	cout << h << " PLAY WITH PC (HARD)";
	_Common::gotoXY(x, ++y);
	//==============================
	_Common::textColor(26);
	cout << (char)175 << " RULE";
	_Common::textColor(4);
	//=======================================
	_Common::gotoXY(x, ++y);
	cout << h << " QUIT";
	
}
void _Menu::printOptions_6(int X, int Y, char h)
{
	int x = X;
	int y = Y;
	_Common::gotoXY(x, y);
	cout << h <<" NEWGAME";
	_Common::gotoXY(x, ++y);
	
	cout << h <<" LOAD GAME";
	
	_Common::gotoXY(x, ++y);
	cout << h << " PLAY WITH PC (EASY)";
	_Common::gotoXY(x, ++y);
	cout << h << " PLAY WITH PC (HARD)";
	_Common::gotoXY(x, ++y);
	cout << h << " RULE";
	_Common::gotoXY(x, ++y);
	//==============================
	_Common::textColor(26);
	cout << (char)175 << " QUIT";
	_Common::textColor(4);
	//=======================================
	
}
void _Menu::hidePtr()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void _Menu::showPtr()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void _Menu::PlayBackSound()
{
	PlaySound(TEXT("intro2.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
