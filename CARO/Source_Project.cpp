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
					if (t.askContinue())
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
			}
		}
	}
	return;
}
void PvsE_EZ(_Game& t)
{
	
	t.setCh(3);
	t.printTurn();
	while (t.isContinue())
	{
		t.printTurn();
		//Luot cua nguoi choi
		if (t.getTurn())
		{
			t.waitKeyBoard();
			switch (t.getCommand())
			{
			case 27: return; break;
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
						if (t.askContinue())
						{
							_Common::textColor(240);
							t.startGame();
							return PvsE_EZ(t);
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

			}
		}
		//Luot cua may 	
		else
		{
			t.playWithAi_Easy();
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (t.processCheckBoard())
			{
				switch (t.processFinish())
				{
				case -1: case 1: case 0:
				{
					if (t.askContinue() )
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
		}
	}
}
void PvsE_H(_Game&t)
{
	
	t.setCh(4);
	t.printTurn();
	while (t.isContinue())
	{
		t.printTurn();
		//Luot cua nguoi choi
		if (t.getTurn())
		{
			t.waitKeyBoard();
			switch (t.getCommand())
			{
			case 27: return; break;
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
						if (t.askContinue())
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
				break;
			}
			case 'L':
			{
				system("cls");
				t.saveGame();
				return;
			}

			}
			
		}
		//Luot cua may 	
		else
		{
			t.playWithAi_Hard();
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (t.processCheckBoard())
			{
				switch (t.processFinish())
				{
				case -1: case 1: case 0:
				{
					if (t.askContinue() )
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
	_Common::resizeConsole(1350, 800);
	_Common::fixConsoleWindow();
	system("cls");
	_Menu m;
	m.displayMenu();
	m.setChoice();
	m.showPtr();
	int userChosen = m.getChoice();
	_Common::textColor(240);
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
		goto Label_main;
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
	
