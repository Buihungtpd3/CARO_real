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
	char c = ' ';
	while (c != 'y' && c != 'Y' && c != 27)
	{
		backGround(52, 16, 58, 10, 112);
		backGround(50, 15, 58, 10, 192);

		gotoXY(65, 17);
		textColor(103);
		cout << "DO YOU WANT PLAY AGIAN?";
		textColor(199);
		gotoXY(65, 19);
		cout << "PRESS " << "Y" << " TO RESTART";
		gotoXY(65, 20);
		cout << "PRESS " << "ESC" << " TO QUIT";
		gotoXY(65, 22);
		cout << "ENTER YOUR CHOSE: ";
		c = _getch();
		gotoXY(84, 22);
		textColor(192);
		if (c != 'y' && c != 'Y' && c != 27)
		{
			gotoXY(66, 22);
			cout << "EROR! TRY AGAIN: ";
			gotoXY(65, 22);
			cout << "ENTER YOUR CHOSE: ";
		}
	}
	return c;

}
void _Game::startGame()
{
	system("cls");
	_b->resetData();// Gan gia tri 0 cho cac o tren ban co
	_b->drawBoard();// Ve ban co
	_x = _b->getXAt(0, 0);// Tra ve vi tri cua con tro tren man hinh theo truc hoanh
	_y = _b->getYAt(0, 0);//Tra ve vi tri cua con tro tren man hinh theo truc tung
	turnX = turnO = 0;
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
		turnX++;
		textColor(253);
		cout << "X";	
		textColor(240);
	}
		break;
	case 1: 
		turnO++;
	{	textColor(249);
		cout << "O";
		textColor(240);
	}
		break;
	case 0: return false;
	}
	return true;
}
//Ham in ra X win 
void _Game::P1Win()
{
	system("cls");
	hidePtr();
	int arr[4] = { 43,48,95,96};
	int color;
	int index = 0;
	for (int i = 0; i < 20; i++)
	{
		Sleep(200);
		index = 0 + rand() % (4);
		color = arr[index];
		// X

		cheoPhai(45, 11, 10, 10, 112);
		cheoTrai(45, 11, 10, 10, 112);
		cheoTrai(40, 10, 10, 10, color);
		cheoPhai(40, 10, 10, 10, color);
		// W

		cheoPhai(60, 11, 10, 10, 112);
		cheoTrai(70, 16, 3, 3, 112);
		cheoPhai(73, 16, 3, 3, 112);
		cheoTrai(76, 11, 10, 10, 112);

		cheoPhai(55, 10, 10, 10, color);
		cheoTrai(65, 15, 3, 3, color);
		cheoPhai(68, 15, 3, 3, color);
		cheoTrai(71, 10, 10, 10, color);

		// I

		veNgang(91, 11, 10, 112);
		veDoc(96, 11, 10, 112);
		veNgang(91, 21, 10, 112);

		veNgang(86, 10, 10, color);
		veDoc(91, 10, 10, color);
		veNgang(86, 20, 10, color);

		//N

		veDoc(107, 11, 10, 112);
		cheoPhai(108, 11, 10, 10, 112);
		veDoc(119, 11, 10, 112);

		veDoc(102, 10, 10, color);
		cheoPhai(103, 10, 10, 10, color);
		veDoc(114, 10, 10, color);
	}
}
void _Game::P2Win()
{
	system("cls");
	hidePtr();
	int arr[4] = { 43,48,95,96 };
	int color;
	int index = 0;
	for (int i = 0; i < 20; i++)
	{
		Sleep(200);
		index = 0 + rand() % (4);
		color = arr[index];
		// O
		veDoc(42, 13, 7, 112);
		veDoc(57, 13, 7, 112);
		veNgang(48, 11, 4, 112);
		veNgang(48, 22, 4, 112);
		gotoXY(45, 12); cout << "   ";
		gotoXY(54, 12); cout << "   ";
		gotoXY(45, 21); cout << "   ";
		gotoXY(54, 21); cout << "   ";

		veDoc(38, 12, 7, color);
		veDoc(53, 12, 7, color);
		veNgang(44, 10, 4, color);
		veNgang(44, 21, 4, color);
		gotoXY(41, 11); cout << "   ";
		gotoXY(50, 11); cout << "   ";
		gotoXY(41, 20); cout << "   ";
		gotoXY(50, 20); cout << "   ";

		// W

		cheoPhai(60, 11, 10, 10, 112);
		cheoTrai(70, 16, 3, 3, 112);
		cheoPhai(73, 16, 3, 3, 112);
		cheoTrai(76, 11, 10, 10, 112);

		cheoPhai(55, 10, 10, 10, color);
		cheoTrai(65, 15, 3, 3, color);
		cheoPhai(68, 15, 3, 3, color);
		cheoTrai(71, 10, 10, 10, color);

		// I

		veNgang(91, 11, 10, 112);
		veDoc(96, 11, 10, 112);
		veNgang(91, 21, 10, 112);

		veNgang(86, 10, 10, color);
		veDoc(91, 10, 10, color);
		veNgang(86, 20, 10, color);

		//N

		veDoc(107, 11, 10, 112);
		cheoPhai(108, 11, 10, 10, 112);
		veDoc(119, 11, 10, 112);

		veDoc(102, 10, 10, color);
		cheoPhai(103, 10, 10, 10, color);
		veDoc(114, 10, 10, color);
	}
}
int _Game::processFinish() {

	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
	int whoWin = _b->testBoard(_i, _j, _turn);//Ham test board nhan vao vi tri cua moi o co, luot choi va tra ve ket 1 so tuong ung voi cac truong hop
	switch (whoWin)
	{
		case -1: 
		{ 
			P1Win();
			break;
		}
		case 1: 
		{
			P2Win();
			break; 
		}
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
void _Game::printTurn()
{
	int x = _x;
	int y = _y;
	gotoXY(_b->getLeft() + _b->getSize() * 4 + 35, _b->getTop()+ 14);
	textColor(252);
	cout << turnX;
	gotoXY(_b->getLeft() + _b->getSize() * 4 + 53,_b ->getTop() + 14);
	textColor(252);
	cout << turnO;
	textColor(240);
	_x = x; _y = y;
	gotoXY(x, y);
}
