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
	_Board* _b; // Bàn cờ
	bool _turn; // Lượt đi, True = X, False = O
	int _x, _y;// Tọa độ con trỏ trên màn hình
	int _command;// Phím chờ
	bool _loop;// Biến quản lý flow game
	int _i, _j;// Tọa độ trên mảng 2 chiều của bàn cờ
	int option;// Sự lựa chọn chế độ chơi
	/*
	* 1> New Game
	* 2> Load Game
	* 3> Chơi với máy (Dễ)
	* 4> Chơi với máy (Khó)
	* 5> Luật chơi
	* 6> Thoát
	*/
	// File name dùng để quản lý tên những Game đã được lưu trong file Text để tránh trùng lặp
	set <string> fileName;
public:
	// Khởi tạo bàn cờ với thông số truyền vào: Lề trái, lề phải, kích thước
	_Game(int, int, int);
	~_Game();
public:
	// Đếm số lượt đi của X, Y
	int turnX = 0, turnO = 0;
	// Trả về lượt hiện tại
	bool getTurn();
	// Phím vừa mới nhập
	int getCommand();
	// SetChoice: Thiết lập chế độ chơi
	void setCh(int);
	// GetChoice: Đọc chế độ chơi
	int getCh();
	// Quản lý flow game
	bool isContinue();
	// Chờ nhập phím
	char waitKeyBoard();
	// Tiếp tục chơi ở chế độ cũ hay không
	bool askContinue();
	// Khởi tạo game
	void startGame();
	// Thoát game
	void exitGame();
	// Kiểm tra kết thúc game hay chưa
	int processFinish();
	// kiểm tra tính hợp lệ của nước đi
	bool processCheckBoard();
	// Di chuyển Phải, trái trên dưới trong bàn cờ 
	
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
public:
	// Luật chơi
	void rule();
	// Lưu game
	void saveGame();
	// Load game đã lưu
	void loadGame(string name);
	// Tải tên tất cả tập tin đã lưu 
	string loadFileName();
	// Hiệu ứng X win
	void P1Win();
	// Hiệu ứng O win 
	void P2Win();
	// Hiệu ứng hòa
	void Draw();
	// In số lượt chơi của người chơi 
	void printTurn();
public:
	//Choi voi may 
	void playWithAi_Hard();
	void playWithAi_Easy();
	

};
