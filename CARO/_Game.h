#include "_Board.h"
#include "_Common.h"
#include "_Point.h"
#include "_Menu.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <set>
class _Game : public _Board {
private:
	_Board* _b;
	bool _turn;
	int _x, _y;
	int _command;
	bool _loop;
	int _i, _j;
	int option;
	set <string> fileName;
public:
	_Game(int, int, int);
	~_Game();
public:
	int turnX = 0, turnO = 0;
	bool getTurn();
	int getCommand();
	void setCh(int);
	int getCh();
	bool isContinue();
	char waitKeyBoard();
	char askContinue();
	void startGame();
	void exitGame();
	int processFinish();
	bool processCheckBoard();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
public:
	void rule();
	void saveGame();
	void loadGame(string name);
	string loadFileName();
	void P1Win();
	void P2Win();
	void Draw();
	void printTurn();
public:
	//Choi voi may 
	void playWithAi_Hard();
	void playWithAi_Easy();
	

};
