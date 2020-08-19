#include "_Game.h"
#include "_Board.h"
_Game::_Game (int pSize, int pLeft, int pTop) {
	 _b = new _Board(pSize, pLeft, pTop);
	_loop = _turn = true;
	_command = -1;
	_x = pLeft; 
	_y = pTop;
	_i = _j = 0; // i hang va j cot tren ban co 
	turnX = turnO = 0;
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
	//Nhan phim tu ban phim
	_command = toupper(_getch());
	return _command;
}
char _Game::askContinue() {
	system("cls");
	cout << "Do you want to continue? <Y/N> ";
	char choice;
	cin >> choice;
	return choice;
}
void _Game::startGame()
{
	system("cls");
	_b->resetData();// Gan gia tri 0 cho cac o tren ban co
	_b->drawBoard();// Ve ban co
	_x = _b->getXAt(0, 0);// Tra ve vi tri cua con tro tren man hinh theo truc hoanh
	_y = _b->getYAt(0, 0);//Tra ve vi tri cua con tro tren man hinh theo truc tung
}
void _Game::exitGame()
{
	system("cls");
	_loop = false;
}
bool _Game::processCheckBoard()
{
	switch (_b->checkBoard(_x, _y, _turn)) // Check board kiem tra xem muoc di hop le hay khong va tra ve 1 so
	{									   //Neu turn = true rturn -1 (luot X), neu turn = false, return 1 (luot O)....
	case -1: 
	{
		cout << "X";	
	}
		break;
	case 1: 
	{	
		cout << "O";
	}
		break;
	case 0: return false;
	}
	return true;
}
int _Game::processFinish() {

	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
	int whoWin = _b->testBoard(_i, _j, _turn);//Ham test board nhan vao vi tri cua moi o co, luot choi va tra ve ket 1 so tuong ung voi cac truong hop
	switch (whoWin)
	{
		case -1: { cout << "\t\t\t\t\t\t\t\t\t\t\tPlayer 1 win"; break; }
		case 1: {cout << "\t\t\t\t\t\t\t\t\t\t\t\tPlayer 2 win"; break; }
		case 0: {cout << "\t\t\t\t\t\t\t\t\t\t\t\tdraw"; break; }
		case 2: _turn = !_turn;//Doi luot neu khong gi xay ra !
	}
	_Common::gotoXY(_x, _y);
	return whoWin;
}
void _Game::moveRight() {
	if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1)) {
		_x += 4;
		_j++;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveLeft() {
	if (_x > _b->getXAt(0, 0)) {
		_x -= 4;
		_j--;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveDown() {
	if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1)) {
		_y += 2;
		_i++;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveUp() {
	if (_y > _b->getYAt(0, 0)) {
		_y -= 2;
		_i--;
		_Common::gotoXY(_x, _y);
	}
}
// Choi voi may che do de 
//void _Game::playWithAi()
//{
//	
//	srand((int)time(0));
//	int row, colum;
//	map<int, bool> vis_row;
//	map<int, bool> vis_colum;
//	do 
//	{
//		do {
//			row =  rand() % (20);
//		} while (vis_row.find(row) != vis_row.end());
//		do {
//			colum =  rand() % (20);
//		} while (vis_colum.find(colum) != vis_colum.end());
//
//	} while (_b->checkBoard(row,colum,_turn) != 0);
//	vis_row[row] = true;
//	vis_colum[colum] = true;
//	_i = row; _j = colum;
//	_x = _b->getXAt(_i, _j);
//	_y = _b->getYAt(_i, _j);
//	gotoXY(_x, _y);
//}

//=========================================================
//int _Game::Minimax(int i, int j, int depth, bool isMax, int alpha, int beta)
//{
//	if (depth == 0)
//	{
//		int score = _b->getScore(i, j, depth);
//	}
//	if (isMax)
//	{
//		int best = INT_MIN;
//		// Traverse all cells 
//		for (int i = 0; i < _b->getSize(); i++)
//		{
//			for (int j = 0; j < _b->getSize(); j++)
//			{
//				// Check if cell is empty 
//				if (_b->getParr(i, j).getCheck() == 0)
//				{
//					// Make the move 
//					_b->getParr(i, j).setCheck(1);
//
//					// Call minimax recursively and choose 
//					// the maximum value 
//					int val = max(best, Minimax(i, j, depth - 1, !isMax, alpha, beta));
//					best = max(best, val);
//					alpha = max(alpha, best);
//					// Undo the move 
//					_b->getParr(i, j).setCheck(0);
//					// Alpha Beta Pruning 
//					if (beta <= alpha)
//						break;
//				}
//			}
//		}
//		return best;
//	}
//
//	// If this minimizer's move 
//	else
//	{
//		int best = INT_MAX;
//
//		// Traverse all cells 
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				// Check if cell is empty 
//				if (_b->getParr(i, j).getCheck() == 0)
//				{
//					// Make the move 
//					_b->getParr(i, j).setCheck(-1);
//
//					// Call minimax recursively and choose 
//					// the minimum value 
//					int val = min(best, Minimax(i, j, depth - 1, !isMax, alpha, beta));
//					best = min(best, val);
//					beta = min(beta, best);
//
//					// Undo the move 
//					_b->getParr(i, j).setCheck(0);
//
//					// Alpha Beta Pruning 
//					if (beta <= alpha)
//						break;
//				}
//			}
//		}
//		return best;
//	}
//}

void _Game::playWithAi_Hard()
{
	_Point result = _b->findTheBestMove_1();
	_j = (result.getX() - _b->getLeft() - 2) / 4;
	_i = (result.getY() - _b->getTop() - 1) / 2;
	_x = result.getX();
	_y = result.getY();
	gotoXY(_x, _y);
}
void _Game::playWithAi_Easy()
{
	_Point result = _b->findTheBestMove_2();
	_j = (result.getX() - _b->getLeft() - 2) / 4;
	_i = (result.getY() - _b->getTop() - 1) / 2;
	_x = result.getX();
	_y = result.getY();
	gotoXY(_x, _y);
}
void _Game::loadGame()
{
	//chua cai dat
}

