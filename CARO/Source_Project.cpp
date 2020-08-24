#include"_Game.h"
#include"_Common.h"
#include"_Board.h"
#include"_Point.h"
#include"_Menu.h"
#include <iostream>
#include<conio.h>
using namespace std;
void PvsP()
{
	system("cls");
	_Game t(20, 10, 5);
	t.startGame();
	t.printTurn();
	while (t.isContinue()) {
		t.printTurn();
		t.waitKeyBoard();
		if (t.getCommand() == 27)// Neu bang ESC thi thoat game
		{
			t.exitGame();
		}
		else
		{
			switch (t.getCommand())
			{
			case 'A':
			{ 
				t.moveLeft();
				break;
			}
			case 'W':
			{
				t.moveUp();
				break;
			}
			case 'D':
			{	
				t.moveRight();
				break;
			}
			case 'S':
			{	
				t.moveDown();
				break;
			}
			case 13:
			{
				if (t.processCheckBoard())
				{
				switch (t.processFinish())
					{
				case -1: case 1: case 0:
					if (t.askContinue() != 'Y')
					{
						t.startGame();
					}
					else t.exitGame();
					}
				}
				break;
			}
			case 'L':
			{
				system("cls");
				cout << "Goi ham luu game";
				break;
			}
			case 'T':
			{
				system("cls");
				cout << "Goi ham Load game";
				break;
			}





			}
		}
	}
	return;
}
void PvsE_EZ()
{
	system("cls");
	_Game t(20, 10, 5);
	t.startGame();
	bool isPlayer = 1;
	t.printTurn();
	while (t.isContinue())
	{
		t.printTurn();
		//Luot cua nguoi choi
		if (isPlayer)
		{
			t.waitKeyBoard();
			if (t.getCommand() == 27)// Neu bang ESC thi luu game roi thoat
			{
				t.exitGame();
			}
			else
			{
				do {
					switch (t.getCommand())
					{
					case 'A':
						t.moveLeft();
						break;
					case 'W':
						t.moveUp();
						break;
					case 'D':
						t.moveRight();
						break;
					case 'S':
						t.moveDown();
						break;
					case 'L':
					{
						system("cls");
						cout << "Goi ham luu game";
						break;
					}
					case 'T':
					{
						system("cls");
						cout << "Goi ham Load game";
						break;
					}

					}
					t.waitKeyBoard();
				} while (t.getCommand() != 13);
				if (t.processCheckBoard())
				{
					switch (t.processFinish())
					{
					case -1: case 1: case 0:
					{
						system("pause");
						if (t.askContinue() != 'Y')
						{
							t.startGame();
						}
						else t.exitGame();
					}
					}
				}
			}
			isPlayer = !isPlayer;
		}
		//Luot cua may 	
		else
		{
			t.playWithAi_Easy();
			if (t.processCheckBoard())
			{
				switch (t.processFinish())
				{
				case -1: case 1: case 0:
				{
					system("pause");
					if (t.askContinue() != 'Y')
					{
						t.startGame();
					}
					else  t.exitGame();
				}
				}
			}
			isPlayer = !isPlayer;
		}
	}
}
void PvsE_H()
{
	system("cls");
	_Game t(20, 10, 5);
	t.startGame();
	bool isPlayer = 1;
	t.printTurn();
	while (t.isContinue())
	{
		t.printTurn();
		//Luot cua nguoi choi
		if (isPlayer)
		{
			t.waitKeyBoard();
			if (t.getCommand() == 27)// Neu bang ESC thi luu game roi thoat
			{
				t.exitGame();
			}
			else
			{
				do {
					switch (t.getCommand())
					{
					case 'A':
						t.moveLeft();
						break;
					case 'W':
						t.moveUp();
						break;
					case 'D':
						t.moveRight();
						break;
					case 'S':
						t.moveDown();
						break;
					case 'L':
					{
						system("cls");
						cout << "Goi ham luu game";
						break;
					}
					case 'T':
					{
						system("cls");
						cout << "Goi ham Load game";
						break;
					}
					}
					t.waitKeyBoard();
				} while (t.getCommand() != 13);
				if (t.processCheckBoard())
				{
					switch (t.processFinish())
					{
					case -1: case 1: case 0:
					{
						system("pause");
						if (t.askContinue() != 'Y')
						{
							t.startGame();
						}
						else t.exitGame();
					}
					}
				}
			}
			isPlayer = !isPlayer;
		}
		//Luot cua may 	
		else
		{
			t.playWithAi_Hard();
			if (t.processCheckBoard())
			{
				switch (t.processFinish())
				{
				case -1: case 1: case 0:
				{
					system("pause");
					if (t.askContinue() != 'Y')
					{
						t.startGame();
					}
					else  t.exitGame();
				}
				case 2: break;
				}
			}
			isPlayer = !isPlayer;
		}
	}
}
int main() {
Label_main:
	//...............................
	system("color F1");
	system("cls");
	_Common::resizeConsole(1520, 1080);
	_Common::fixConsoleWindow();
	system("cls");
	_Menu m;
	m.displayMenu();
	m.setChoice();
	m.showPtr();
	int userChosen = m.getChoice();
	m.textColor(240);

	// Cac che do 
	switch (userChosen)
	{		
	case 1://Nguoi vs Nguoi
	{
		PvsP();
		goto Label_main;
		return 0;
	}
	case 2:
	{
		//Load Game
		system("cls");
		cout << "Ham Load game    \n";
		cout << "12345";
		system("pause");
		break;
	}
	case 3://Choi voi may (de) 
	{
	
		PvsE_EZ();
		goto Label_main;
	}
	case 4://Choi voi may (kho)	
	{		
		PvsE_H();
		goto Label_main;
	}
	
	case 5:
	{
		return 0;
		break;
	}
	}
}
	