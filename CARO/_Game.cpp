#include "_Game.h"
#include "_Board.h"
_Game::_Game (int pSize, int pLeft, int pTop) {
	 _b = new _Board(pSize, pLeft, pTop);
	_loop = _turn = true;
	_command = -1;
	_x = pLeft; 
	_y = pTop;
}
_Game::~_Game() {
	delete _b;
}
int _Game::getCommand(){
	return _command;
}
bool _Game::isContinue() {
	return _loop;
}
char _Game::waitKeyBoard() {
	_command = toupper(_getch());
	return _command;
}
char _Game::askContinue() {
	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 4);
	return waitKeyBoard();
}
void _Game::startGame()
{
	system("cls");
	_b->resetData();
	_b->drawBoard();
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
}
void _Game::exitGame()
{
	system("cls");
	_loop = false;
}
bool _Game::processCheckBoard()
{
	switch (_b->checkBoard(_x, _y, _turn)) // Check board kiem tra xem muoc di hop le hay khong va tra ve 1 so
	{									   //Neu turn = 1 rturn -1 (luot X), neu turn = 0, return 1 (luot O)....
	case -1: 
		cout << "X";
		break;
	case 1: 
		cout << "O";
		break;
	case 0: return false;
	}
	return true;
}
int _Game::processFinish() {

	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
	int whoWin = _b->testBoard(_x, _y, _turn);
	switch (whoWin)
	{
		case -1: { cout << "\t\t\t\\t\t\t\t\tPlayer 1 win"; break; }
		case 1: {cout << "\t\t\t\t\t\t\t\t\t\tPlayer 2 win"; break; }
		case 0: {cout << "\t\t\t\t\t\t\t\t\t\tdraw"; break; }
		case 2: _turn = !_turn;//Doi luot neu khong gi xay ra !
	}
	_Common::gotoXY(_x, _y);
	return whoWin;
}
void _Game::moveRight() {
	if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1)) {
		_x += 4;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveLeft() {
	if (_x > _b->getXAt(0, 0)) {
		_x -= 4;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveDown() {
	if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1)) {
		_y += 2;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveUp() {
	if (_y > _b->getYAt(0, 0)) {
		_y -= 2;
		_Common::gotoXY(_x, _y);
	}
}

void _Game::saveGame()
{
	//chua cai dat
}
void _Game::loadGame()
{
	//chua cai dat
}

void _Game::law()
{
	//chua cai dat
}

