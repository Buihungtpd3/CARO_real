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
	_Menu m;
	m.displayMenu();
	m.setChoice();
	int userChossen = m.getChoice();
	switch (userChossen)
	{
	case 1: goto Label_1; break;
	case 2: goto Label_2; break;
	case 3: goto Label_3; break;
	case 4: goto Label_4; break;
	case 5: goto Label_5; break;
	}
Label_5:
	//Thoat Game
	system("cls");
	cout << "Thoat\n";
	system("pause");
	goto Label_main;
Label_4:
	//Luat Choi
	system("cls");
	cout << "In luat choi\n";
	system("pause");
	goto Label_main;
Label_3:
	//Luu Game
	system("cls");
	cout << "Ham luu game\n";
	system("pause");
	goto Label_main;
Label_2:
	//Load Game
	system("cls");
	cout << "Ham Load game\n";
	system("pause");
	goto Label_main;
Label_1:
	//New Game( Cai nay la choi vs nguoi ) 
	system("cls");
	_Game t(20, 10, 5);
	t.startGame();
	
	while (t.isContinue()) {

		t.waitKeyBoard();
		if (t.getCommand() == 27)// Neu bang ESC thi luu game r thoat
		{
			//Luu Game 
			//...........
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
				if (t.processCheckBoard()) {
					switch (t.processFinish())
					{
						case -1: 
							if (t.askContinue() != 'Y')
							{
								t.exitGame();
							}
							else t.startGame();
						case 1:
							if (t.askContinue() != 'Y')
							{
								t.exitGame();
							}
							else t.startGame();
						case 0:
							if (t.askContinue() != 'Y')
							{
								t.exitGame();
							}
							else t.startGame();
					}				
				}
			}
		}
	}
	goto Label_main;
}