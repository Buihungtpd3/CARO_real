#include"_Game.h"
#include"_Common.h"
#include"_Board.h"
#include"_Point.h"
#include"_Menu.h"
#include <iostream>
#include<conio.h>
using namespace std;
void PvsP(_Game& t)
{
	t.setCh(1);
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
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (t.processCheckBoard())
				{
				switch (t.processFinish())
					{
				case -1: case 1: case 0:
					if (t.askContinue() == 'Y' || t.askContinue() == 'y')
					{
						_Common::textColor(240);
						t.startGame();
						return PvsP(t);					
					}
					else
					{
						t.exitGame();
						return;
					}
					}
				}
				break;
			}
			case 'L':
			{
				system("cls");
				t.saveGame();
				return;
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
void PvsE_EZ(_Game& t)
{
	
	t.setCh(3);
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
						t.saveGame();
						return;
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
						
						if (t.askContinue())
						{
							_Common::textColor(240);
							t.startGame();
							//return PvsE_EZ(t);
						}
						else
						{
							t.exitGame();
							return;
						}
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
					if (t.askContinue() == 'Y')
					{
						_Common::textColor(240);
						t.startGame();
						return PvsE_EZ(t);
					}
					else {
						t.exitGame();
						return;
					}
				}
				}
			}
			isPlayer = !isPlayer;
		}
	}
}
void PvsE_H(_Game&t)
{
	
	t.setCh(4);
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
						t.saveGame();
						return;
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
						if (t.askContinue() != 'Y')
						{
							_Common::textColor(240);
							t.startGame();
							return PvsE_H(t);
						}
						else
						{
							t.exitGame();
							return;
						}
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
					if (t.askContinue() != 'Y')
					{
						_Common::textColor(240);
						t.startGame();
						return PvsE_H(t);
					}
					else {
						
						t.exitGame();
						return;
					}
				}
				case 2: break;
				}
			}
			isPlayer = !isPlayer;
		}
	}
}
void LoadGame(_Game& t)
{
	string nameGame = t.loadFileName();
	t.startGame();
	t.loadGame(nameGame);
	int option = t.getCh();
	switch (option)
	{
	case 1: {
		PvsP(t);
		break;
	}
	case 3: {
		PvsE_EZ(t);
		break;
	}
	case 4: {
		PvsE_H(t);
		break;
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
	_Game t(20, 10, 5);
	// Cac che do 
	switch (userChosen)
	{		
	case 1://Nguoi vs Nguoi
	{
		t.startGame();
		PvsP(t);
		goto Label_main;
		break;
	}
	case 2:
	{
		//Load Game
		system("cls");
		LoadGame(t);
		break;
	}
	case 3://Choi voi may (de) 
	{
		t.startGame();
		PvsE_EZ(t);
		goto Label_main;
	}
	case 4://Choi voi may (kho)	
	{	
		t.startGame();
		PvsE_H(t);
		goto Label_main;
	}
	
	case 5:
	{
		t.rule();
		goto Label_main;
		break;
	}
	}
}
	