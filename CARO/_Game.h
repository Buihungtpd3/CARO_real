#include "_Board.h"
#include "_Common.h"
#include "_Point.h"
#include <stdlib.h>
#include <time.h>
#include <map>
class _Game : public _Board {
	_Board* _b;
	bool _turn;
	int _x, _y;
	int _command;
	bool _loop;
	int _i, _j;
	int turnX, turnO;
	//int Minimax(_Point **, int, int, int, int&, int&, bool);
public:
	_Game(int, int, int);
	~_Game();
	int getCommand();
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
	void playWithAi();
	//void playWithAi(int);
	void loadGame();

};
