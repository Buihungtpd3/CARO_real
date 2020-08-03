#include"_Game.h"
#include"_Common.h"
#include"_Board.h"
#include"_Point.h"
#include"_Menu.h"
#include <iostream>
#include<conio.h>
using namespace std;

int main () {
	Label_main:
	system("cls");
	_Common::resizeConsole(1200, 800);
	_Common::fixConsoleWindow();
	system("cls");
	_Menu m;
	m.displayMenu();
	m.setChoice();
	int userChosen = m.getChoice();
	switch (userChosen)
	{
	case 1: goto Label_1; break;
	case 2: 
	{
		//Load Game
		system("cls");
		cout << "Ham Load game\n";
		system("pause");
		 break;
	}
	case 3:
	{
		//Choi voi may	
		system("cls");
		_Game t(20, 10, 5);
		t.startGame();
		bool isPlayer = 1;
		while (t.isContinue())
		{
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
						}
						t.waitKeyBoard();
					} while (t.getCommand() != 13);
					//===========================================================
						if (t.processCheckBoard())
						{
							switch (t.processFinish())
							{
							case -1: case 1: case 0:
								if (t.askContinue() != 'Y')
								{
									t.exitGame();
								}
								else  t.startGame();
							}
						}				
				}
				isPlayer = !isPlayer;
			}
				
			else
			{
				t.playWithAi();
				if (t.processCheckBoard())
				{
					switch (t.processFinish())
					{
					case -1: case 1: case 0:
						if (t.askContinue() != 'Y')
						{
							t.exitGame();
						}
						else  t.startGame();
					}
				}
				isPlayer = !isPlayer;
			}
		}
		goto Label_main;
	}
	case 4: 
	{
		//Luat Choi
		system("cls");
		cout << "In luat choi\n";
		system("pause");
		 break; 
	}
	case 5:
		{
			//Thoat Game
			system("cls");
			cout << "Thoat\n";
			system("pause");
		break;
		}
	}
	Label_1:
	//New Game( Cai nay la choi vs nguoi ) 
	system("cls");
	_Game t(20, 10, 5);
	t.startGame();
	
	while (t.isContinue()) {

		t.waitKeyBoard();
		if (t.getCommand() == 27)// Neu bang ESC thi luu game r thoat
		{
			t.exitGame();
		}
		else
		{
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
			case 13:
				if (t.processCheckBoard()) 
				{
					switch (t.processFinish())
					{
					case -1: case 1: case 0:
						if (t.askContinue() != 'Y')
						{
							t.exitGame();
						}
						else  t.startGame();
					}				
				}
			}
		}
	}
}