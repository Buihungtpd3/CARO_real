#include "_Menu.h"

//Nhap su lua chon
void _Menu::setChoice()
{
	if (_x == 85 && _y == 9)
		_choice = 1;
	else if (_x == 85 && _y == 10)
		_choice = 2;
	else if (_x == 85 && _y == 11)
		_choice = 3;
	else if (_x == 85 && _y == 12)
		_choice = 4;
	else if (_x == 85 && _y == 13)
		_choice = 5;
	else if (_x == 85 && _y == 14)
		_choice = 6;
	else {
		_x = 85; _y = 9;
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

void _Menu::displayMenu()
{
	
	_Common::textColor(11);
	int n = 30;
	for (int x = 120; x >= 75; x--) {
		Sleep(20);
		gotoXY(x, 1);
		char a = (char)196;// ky tu "_"
		if (x == 120)
		{
			char temp = (char)191;
			cout << temp;
		}
		else{ cout << a; }
		
		gotoXY(n, 1);
		if (n == 30)
		{
			char temp = (char)218;
			cout << temp;
		}
		else 
		{cout << a;}	
		n++;
	}
	cout << endl;
	for (int y = 2; y <= 20; y++) {
		
		Sleep(20);
		gotoXY(30, y);
		char const c = (char)179;
		cout << c;
		gotoXY(120, y);
		cout << c;
		gotoXY(2, y);
	}
	n = 120;
	for (int x = 30; x <= 75; x++) {
		Sleep(20);
		gotoXY(x,20);
		char c = (char)196;
		if (x == 30)
		{
			char temp = (char)192;
			cout << temp;
		}
		else { cout << c; }		
		gotoXY(n,20);
		if (n == 120)
		{
			char temp = (char)217;
			cout << temp;
		}
		else { cout << c; }	
		n--;
	}
	
	print();
	

}

void _Menu::print()
{
	hidePtr();
	textColor(12);
	printOptions();
	
	while (true)
	{
		int color = 6 + rand() % (15 + 1 - 6);
		textColor(color);
		gotoXY(35, 4); cout << "         _                          ";
		gotoXY(35, 5); cout << "      ,:::::\\                         ";
		gotoXY(35, 6); cout << "     /:::::::|                        ";
		gotoXY(35, 7); cout << "    /:::' ::/                         ";
		gotoXY(35, 8); cout << "   /:::'      _         __      ___   ";
		gotoXY(35, 9); cout << "  /:::'     ,::::\\   /::::\\  / ._. \\  ";
		gotoXY(35, 10); cout << " .:::'    /./:| |   |:/     /:/   \\:\\ ";
		gotoXY(35, 11); cout << " |:::    /:/  |:|   |:|     |      |          ";
		gotoXY(35, 12); cout << " [:::   /:/__ |:| / |:|     \\:\\._./:/ ";
		gotoXY(35, 13); cout << " [:::   \\____/ \\_/  |:|      \\_____/  ";
		gotoXY(35, 14); cout << " \\:::.          ,~~~~~~~,           ";
		gotoXY(35, 15); cout << "  \\::::..  .:::::::::::::::::.        ";
		gotoXY(35, 16); cout << "   \\_`::::::::`/``~~     ";
		gotoXY(35, 17); cout << "     ~~~~~~~~  ";
		Sleep(100);
		if (_kbhit())
		{
			textColor(12);
			if (_getch() == 13) return;
			switch (_getch())
			{
			case 119:
			{
				//chen am thanh 
				//...
				if (_y >= 9 && _y <= 14) {
					_y--; gotoXY(_x, _y);
				}
				switch (_y)
				{
				case 9:
					{
						int x = 85;
						gotoXY(x, 9);
						char h = 41;
						textColor(26);
						cout << (char)175 << " NEWGAME";
						textColor(12);
						gotoXY(x, 10);
						cout << h << " LOAD GAME";
						gotoXY(x, 11);
						cout << h << " PLAY WITH PC (EASY)";
						gotoXY(x, 12);
						cout << h << " PLAY WITH PC (HARD)";
						gotoXY(x, 13);
						cout << h << " RULE";
						gotoXY(x, 14);
						cout << h << " QUIT";
						gotoXY(_x, _y);
						break;
					}
				case 10: 
					{
						int x = 85;
						gotoXY(x, 9);
						char h = 41;
						cout << h << " NEWGAME";
						gotoXY(x, 10);
						textColor(26);
						cout << (char)175 << " LOAD GAME";
						textColor(12);
						gotoXY(x, 11);
						cout << h << " PLAY WITH PC (EASY)";
						gotoXY(x, 12);
						cout << h << " PLAY WITH PC (HARD)";
						gotoXY(x, 13);
						cout << h << " RULE";
						gotoXY(x, 14);
						cout << h << " QUIT";
						gotoXY(_x, _y);
						break;
					}
				case 11:
					{
						int x = 85;
						gotoXY(x, 9);
						char h = 41;
						cout << h << " NEWGAME";
						gotoXY(x, 10);
						cout << h << " LOAD GAME";
						gotoXY(x, 11);
						textColor(26);
						cout << (char)175 << " PLAY WITH PC (EASY)";
						textColor(12);
						gotoXY(x, 12);
						cout << h << " PLAY WITH PC (HARD)";
						gotoXY(x, 13);
						cout << h << " RULE";
						gotoXY(x, 14);
						cout << h << " QUIT";
						gotoXY(_x, _y);
						break;
					}
				case 12:
					{
						int x = 85;
						gotoXY(x, 9);
						char h = 41;
						cout << h << " NEWGAME";
						gotoXY(x, 10);
						cout << h << " LOAD GAME";
						gotoXY(x, 11);
						cout << h << " PLAY WITH PC (EASY)";
						gotoXY(x, 12);
						textColor(26);
						cout << (char)175 << " PLAY WITH PC (HARD)";
						textColor(12);
						gotoXY(x, 13);
						cout << h << " RULE";
						gotoXY(x, 14);
						cout << h << " QUIT";
						gotoXY(_x, _y);
						break;
					}
				case 13:
					{
						int x = 85;
						gotoXY(x, 9);
						char h = 41;
						cout << h << " NEWGAME";
						gotoXY(x, 10);
						cout << h << " LOAD GAME";
						gotoXY(x, 11);
						cout << h << " PLAY WITH PC (EASY)";
						gotoXY(x, 12);
						cout << h << " PLAY WITH PC (HARD)";
						gotoXY(x, 13);
						textColor(26);
						cout << (char)175 << " RULE";
						textColor(12);
						gotoXY(x, 14);
						cout << h << " QUIT";
						gotoXY(_x, _y);
						break;
					}
				case 14:
					{
						int x = 85;
						gotoXY(x, 9);
						char h = 41;
						cout << h << " NEWGAME";
						gotoXY(x, 10);
						cout << h << " LOAD GAME";
						gotoXY(x, 11);
						cout << h << " PLAY WITH PC (EASY)";
						gotoXY(x, 12);
						cout << h << " PLAY WITH PC (HARD)";
						gotoXY(x, 13);
						cout << h << " RULE";
						gotoXY(x, 14);
						textColor(26);
						cout << (char)175 << " QUIT";
						textColor(12);
						gotoXY(_x, _y);
						break;
					}
				}
				break;
			}
			case 115:
			{
				//chen am thanh 
				//...
				if (_y >= 9 && _y <= 14) {
					_y++; gotoXY(_x, _y);
				}
				switch (_y)
				{
				case 9:
				{
					int x = 85;
					gotoXY(x, 9);
					char h = 41;
					textColor(26);
					cout << (char)175 << " NEWGAME";
					textColor(12);
					gotoXY(x, 10);
					cout << h << " LOAD GAME";
					gotoXY(x, 11);
					cout << h << " PLAY WITH PC (EASY)";
					gotoXY(x, 12);
					cout << h << " PLAY WITH PC (HARD)";
					gotoXY(x, 13);
					cout << h << " RULE";
					gotoXY(x, 14);
					cout << h << " QUIT";
					gotoXY(_x, _y);
					break;
				}
				case 10:
					{
						int x = 85;
						gotoXY(x, 9);
						char h = 41;
						cout << h << " NEWGAME";
						gotoXY(x, 10);
						textColor(26);
						cout << (char)175 << " LOAD GAME";
						textColor(12);
						gotoXY(x, 11);
						cout << h << " PLAY WITH PC (EASY)";
						gotoXY(x, 12);
						cout << h << " PLAY WITH PC (HARD)";
						gotoXY(x, 13);
						cout << h << " RULE";
						gotoXY(x, 14);
						cout << h << " QUIT";
						gotoXY(_x, _y);
						break;
					}
				case 11:
					{
						int x = 85;
						gotoXY(x, 9);
						char h = 41;
						cout << h << " NEWGAME";
						gotoXY(x, 10);
						cout << h << " LOAD GAME";
						gotoXY(x, 11);
						textColor(26);
						cout << (char)175 << " PLAY WITH PC (EASY)";
						textColor(12);
						gotoXY(x, 12);
						cout << h << " PLAY WITH PC (HARD)";
						gotoXY(x, 13);
						cout << h << " RULE";
						gotoXY(x, 14);
						cout << h << " QUIT";
						gotoXY(_x, _y);
						break;

					}
				case 12:
					{
						int x = 85;
						gotoXY(x, 9);
						char h = 41;
						cout << h << " NEWGAME";
						gotoXY(x, 10);
						cout << h << " LOAD GAME";
						gotoXY(x, 11);
						cout << h << " PLAY WITH PC (EASY)";
						gotoXY(x, 12);
						textColor(26);
						cout << (char)175 << " PLAY WITH PC (HARD)";
						textColor(12);
						gotoXY(x, 13);
						cout << h << " RULE";
						gotoXY(x, 14);
						cout << h << " QUIT";
						gotoXY(_x, _y);
						break;
					}
				case 13:
					{
						int x = 85;
						gotoXY(x, 9);
						char h = 41;
						cout << h << " NEWGAME";
						gotoXY(x, 10);
						cout << h << " LOAD GAME";
						gotoXY(x, 11);
						cout << h << " PLAY WITH PC (EASY)";
						gotoXY(x, 12);
						cout << h << " PLAY WITH PC (HARD)";
						gotoXY(x, 13);
						textColor(26);
						cout << (char)175 << " RULE";
						textColor(12);
						gotoXY(x, 14);
						cout << h << " QUIT";
						gotoXY(_x, _y);
						break;
					}
				case 14:
					{
						int x = 85;
						gotoXY(x, 9);
						char h = 41;
						cout << h << " NEWGAME";
						gotoXY(x, 10);
						cout << h << " LOAD GAME";
						gotoXY(x, 11);
						cout << h << " PLAY WITH PC (EASY)";
						gotoXY(x, 12);
						cout << h << " PLAY WITH PC (HARD)";
						gotoXY(x, 13);
						cout << h << " RULE";
						gotoXY(x, 14);
						textColor(26);
						cout << (char)175 << " QUIT";
						textColor(12);
						gotoXY(_x, _y);
						break;
					}
				}
				break;
			}

			}
			if (_y < 9 || _y > 14)
			{
				_y = 9;
				_x = 85; _y = 9;
				gotoXY(_x, _y);
			}
		}
	}
	return;
}
	  
void _Menu::printCaro()
{
	while (true)
	{		
		if (_getch() == 13) return;
		int color = 6 + rand() % (15 + 1 - 6);
		textColor(color);
		gotoXY(35, 4); cout << "         _                          ";
		gotoXY(35, 5); cout << "      ,:::::\\                         ";
		gotoXY(35, 6); cout << "     /:::::::|                        ";
		gotoXY(35, 7); cout << "    /:::' ::/                         ";
		gotoXY(35, 8); cout << "   /:::'      _         __      ___   ";
		gotoXY(35, 9); cout << "  /:::'     ,::::\\   /::::\\  / ._. \\  ";
		gotoXY(35, 10); cout << " .:::'    /./:| |   |:/     /:/   \\:\\ ";
		gotoXY(35, 11); cout << " |:::    /:/  |:|   |:|     |      |          ";
		gotoXY(35, 12); cout << " [:::   /:/__ |:| / |:|     \\:\\._./:/ ";
		gotoXY(35, 13); cout << " [:::   \\____/ \\_/  |:|      \\_____/  ";
		gotoXY(35, 14); cout << " \\:::.          ,~~~~~~~,           ";
		gotoXY(35, 15); cout << "  \\::::..  .:::::::::::::::::.        ";
		gotoXY(35, 16); cout << "   \\_`::::::::`/``~~     ";
		gotoXY(35, 17); cout << "     ~~~~~~~~  ";
		Sleep(5);	
	}
	
}

void _Menu::printOptions()
{

	int x = 85;
	gotoXY(x, 9);
	char h = 41;
	textColor(26);
	cout << (char)175 << " NEWGAME";
	textColor(12);
	gotoXY(x, 10);
	cout << h << " LOAD GAME";
	gotoXY(x, 11);
	cout << h << " PLAY WITH PC (EASY)";
	gotoXY(x, 12);
	cout << h << " PLAY WITH PC (HARD)";
	gotoXY(x, 13);
	cout << h << " RULE";
	gotoXY(x, 14);
	cout << h << " QUIT";
	_x = 85; _y = 9;
	gotoXY(_x, _y);
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
