#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "mmsystem.h"
using namespace std;
void move(int i, int j);
int Quit();
void moveinmenu(int i, int j);
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//void soundmenu(int i) {
//	if (i == 1) PlaySound(TEXT("xs.wav"), NULL, SND_ASYNC);
//	else return;
//
//}
void run(int key);
void runop() {
	system("cls");
	gotoXY(20, 1);
	cout << "Music           On";
	gotoXY(36, 1);
	int c = 0;
	int k = 0;
	do {

		c = _getch();
		if (c == 72 || c == 80) {
			if (k % 2 == 0) cout << "Off";
			if (k % 2 != 0) cout << "On ";
			k += 1;
		}
		gotoXY(36, 1);
	} while (c != 13);
	if (k % 2 == 0) run(1);
	else run(0);

}
void run(int key) {
	system("cls");
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	int n = 43;
	for (int i = 43; i >= 1; i--) {
		Sleep(30);
		gotoXY(i, 1);
		cout << "-";
		gotoXY(n, 1);
		cout << "-";
		n++;
	}
	cout << endl;
	for (int i = 2; i <= 18; i++) {
		//SetConsoleTextAttribute(hConsoleColor, 240);
		if (i == 3)cout << "                 _____         ___         _______       __________                " << endl;
		if (i == 4)cout << "                |   __|       |   |       |   __  |     |   ___    |               " << endl;
		if (i == 5)cout << "                |  |         |  _  |      |  |___| |    |  |    |  |               " << endl;
		if (i == 6)cout << "                |  |        |  | |  |     |   _____|    |  |    |  |               " << endl;
		if (i == 7)cout << "                |  |       |  |___|  |    |  ||  |      |  |    |  |               " << endl;
		if (i == 8)cout << "                |  |___    |   _   |      |  | |  |     |  |____|  |               " << endl;
		if (i == 9)cout << "                |______|   |__|   |__|    |__|  |__|    |__________|               ";
		Sleep(30);
		gotoXY(1, i);
		cout << "|";
		gotoXY(85, i);
		cout << "|";
		gotoXY(2, i);
		//system("color 70");
	}
	n = 85;
	for (int i = 1; i <= 43; i++) {
		Sleep(30);
		gotoXY(i, 19);
		cout << "-";
		gotoXY(n, 19);
		cout << "-";
		n--;
	}
	gotoXY(40, 13);
	cout << "* START";
	gotoXY(40, 14);
	cout << "* OPTION";
	gotoXY(40, 15);
	cout << "* QUIT";
	gotoXY(40, 13);
	moveinmenu(40, 13);
}
void board() {
	system("cls");
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			if (i == 0 || i == 10) cout << " _";
			else if (i % 2 != 0) cout << "| ";
			else cout << " _";
		}
		cout << endl;
	}
}
int Quit() {
	system("cls");
	gotoXY(40, 10);
	cout << "Are You Sure?";
	gotoXY(39, 11);
	cout << "Yes";
	gotoXY(52, 11);
	cout << "No";
	gotoXY(52, 11);
	int k = 52;
	while (k == 39 || k == 52) {
		int c = _getch();
		if (c == 13 && k == 39) {
			system("cls");
			gotoXY(20, 10);
			cout << "Exiting..." << endl;
			int t = 0;
			int p = 20;
			for (int i = 1; i <= 51; i++) {
				gotoXY(p, 11);
				Sleep(10);
				cout << "----";
				gotoXY(30, 10);
				cout << t << "%";
				t += 2;
				p += 1;
			}
			Sleep(5);
			exit(0);
		}
		if (c == 13 && k == 52) {
			system("cls");
			return 0;
		}
		if (c == 75) { gotoXY(39, 11); k = 39; }
		if (c == 77) { gotoXY(52, 11); k = 52; }
	}
}
void move(int i, int j)
{
	gotoXY(i, j);
	int c = _getch();
	if (c == 80) j++;
	if (c == 72) j--;
	if (c == 77) i++;
	if (c == 75) i--;
	move(i, j);
}

void moveinmenu(int i, int j) {

	gotoXY(i, j);
	int c = _getch();
	if (c == 80) j++;
	if (c == 72) j--;
	if (c == 13 && j == 13) {
		system("cls");
		gotoXY(40, 5);
		cout << "LET'S GO!";
		gotoXY(1, 20);
		board();
		return;
	}
	if (c == 13 && j == 15) {
		if (Quit() == -1) return;
		else run(1);
		return;
	}
	if (c == 13 && j == 14) runop();
	if (j < 13) j++;
	if (j > 15) j--;
	moveinmenu(i, j);
}

int main() {
	run(1);
	
	return 0;
}