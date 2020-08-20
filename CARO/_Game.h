#include "_Board.h"
#include "_Common.h"
#include "_Point.h"
#include <stdlib.h>
#include <time.h>
#include <map>
class _Game : public _Board {
private:
	_Board* _b;// bàn cờ
	bool _turn;// lượt đi
	int _x, _y;// tọa độ
	int _command;// phím nhập vào 
	bool _loop;// biến quản lý lập 
	int _i, _j;// tọa độ trên bàn cờ
	int turnX, turnO;// lượt của X vs lượt của Y
public:
	_Game(int, int, int);
	~_Game();
public:
	int getCommand();// trả về phím nhập vào 
	bool isContinue();// Biến loop á
	char waitKeyBoard();// chờ nhập vào 
	char askContinue();// đi tiếp hay không 
	void startGame();// Bắt đầu game 
	void exitGame();// thay đổi biến loop
	int processFinish();// Trả về biến kiểu int, 0: hòa, 1: O thắng, -1: X thằng. 2: tiếp tục game
	bool processCheckBoard();// Kiểm tra ô đó đánh được hay không ?
	void moveRight();// Sang phải trên bàn cờ
	void moveLeft();// Sang trái trên bàn cờ
	void moveUp();// Đi lên trên bàn cờ
	void moveDown();// Đi xuống trên bàn cờ
	
	void loadGame();// Tải game từ file
public:
	//Choi voi may 
	void playWithAi_Hard();
	void playWithAi_Easy();
	

};
