#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void text_color(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void display()
{

	text_color(11);
	int n = 43;
	for (int i = 43; i >= 1; i--) {
		Sleep(30);
		gotoXY(i, 1);
		char a;
		a = 95;
		cout << a;
		gotoXY(n, 1);
		a = 95;
		cout << a;
		n++;
	}
	cout << endl;
	for (int i = 2; i <= 18; i++) {

		system("color F1");
		if (i == 3)cout << "                 ____         _          ______      ________                " << endl;
		if (i == 4)cout << "                |   __|      |   |       |   __  |    |   __   |               " << endl;
		if (i == 5)cout << "                |  |         |  _  |      |  |___| |    |  |    |  |               " << endl;
		if (i == 6)cout << "                |  |        |  | |  |     |   _____|    |  |    |  |               " << endl;
		if (i == 7)cout << "                |  |       |  |___|  |    |  ||  |      |  |    |  |               " << endl;
		if (i == 8)cout << "                |  |___    |   _   |    |  | |  |     |  |____|  |               " << endl;
		if (i == 9)cout << "                |______|   |__|   |__|    |__|  |__|    |__________|               ";
		Sleep(30);
		gotoXY(1, i);
		char c = 179;
		cout << c;
		gotoXY(85, i);
		cout << c;
		gotoXY(2, i);
	}
	n = 85;
	for (int i = 1; i <= 43; i++) {
		Sleep(30);
		gotoXY(i, 18);
		char c = 95;
		cout <<  c;
		gotoXY(n, 18);
		cout <<  c;
		n--;
	}
	gotoXY(40, 13);
	//text_color(12);
	char h = 16;
	cout << h << " START";
	gotoXY(40, 14);
	//text_color(13);
	cout << h << " OPTION";
	gotoXY(40, 15);
	cout << h << " QUIT";
	gotoXY(40, 13);

	
Label_1:
	bool flag = true;
	int i = 40;
	int j = 13;
	int ch = 0;
	while (ch != 13) {
		if (_kbhit()) {
			ch = _getch();
			switch (ch) {
			case 80: {
				//doi mau 
				j++;
				gotoXY(i, j);
				break;
			}
			case 72: {
				//doi mau 
				j--;
				gotoXY(i, j);
				break;
			}
			case 77: {
				//doi mau 
				i++;
				gotoXY(i, j);
				break;
			}
			case 75: {
				//doi mau 
				i--;
				gotoXY(i, j);
				break;
			}
			}

		}
	}

	if (i == 40 && j == 13) {
		//setChoice(1);
		cout << "n = 1";
	}
	else if (i == 40 && j == 14) {
		//setChoice(2);

		cout << "n = 2";
	}
	else if (i == 40 && j == 15) {
		//setChoice(3);
		cout << "n = 3";
	}
	else if (i == 40 && j == 16) {
		//setChoice(4);
		cout << "n = 4";
	}
	else if (i == 40 && j == 17) {
		//setChoice(5);
		cout << "n = 5";
	}
	else {
		i = 40;
		j = 13;
		gotoXY(40, 13);
		goto Label_1;
	}
}
int main()
{
	
	display();
	cout << "\n\n\n\n\n\n\n\n\n\n";
	return 0;
}