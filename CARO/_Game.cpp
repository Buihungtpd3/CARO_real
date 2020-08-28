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
	option = 1;
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
		cin >> c;
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
	while (1)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 13:
				return c;
				break;
			}
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
	_turn = true;
	_i = _j = 0;
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
		_Common::backGround(110, 30, 40, 15, 240);
		// ket thuc luot X thong bao bat dau O	
		veDoc(135 - 5, 34, 7, 112);
		veDoc(150 - 5, 34, 7, 112);
		veNgang(141 - 5, 32, 4, 112);
		veNgang(141 - 5, 43, 4, 112);
		gotoXY(138 - 5, 33); cout << "   ";
		gotoXY(147 - 5, 33); cout << "   ";
		gotoXY(138 - 5, 42); cout << "   ";
		gotoXY(147 - 5, 42); cout << "   ";

		veDoc(130 - 5, 33, 7, 96);
		veDoc(145 - 5, 33, 7, 96);
		veNgang(136 - 5, 31, 4, 96);
		veNgang(136 - 5, 42, 4, 96);
		gotoXY(133 - 5, 32); cout << "   ";
		gotoXY(142 - 5, 32); cout << "   ";
		gotoXY(133 - 5, 41); cout << "   ";
		gotoXY(142 - 5, 41); cout << "   ";
		gotoXY(_x, _y);
		textColor(253);
		cout << "X";	
		textColor(240);
	}
		break;
	case 1: 	
	{
		turnO++;
		// ket thuc luot O thong bao bat dau X
		_Common::backGround(120, 30, 40, 15, 240);
		cheoPhai(130, 33, 10, 10, 112);
		cheoTrai(130, 33, 10, 10, 112);
		cheoTrai(125, 32, 10, 10, 96);
		cheoPhai(125, 32, 10, 10, 96);
		textColor(249);
		gotoXY(_x, _y);
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
	textColor(240);
	showPtr();
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
	textColor(240);
	showPtr();
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
void _Game::setCh(int n)
{
	option = n;
}
int _Game::getCh()
{
	return option;
}
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
string _Game::loadFileName()
{
	fstream input;
	set <string> fileName;
	textColor(240);
	input.open("Name.txt", ios::in);
	int i = 16;
	string nameFile;


	while (!input.eof())
	{
		input >> nameFile;
		fileName.insert(nameFile);
	}


	bool flag = true;
	while (flag != false)
	{
		system("cls");
		gotoXY(64, 16);
		textColor(176);
		cout << "LIST FILE:";
		textColor(240);
		set <string> ::iterator itr;
		for (itr = fileName.begin(); itr != fileName.end(); ++itr)
		{
			gotoXY(75, i);
			textColor(248);
			cout << *itr;
			textColor(240);
			i++;
		}

		input.close();
		gotoXY(64, 30);
		textColor(240);
		cout << "ENTER YOUR FILE:";
		getline(cin, nameFile);
		set <string> ::iterator it;
		it = fileName.find(nameFile);
		if (it != fileName.end())
		{
			return nameFile;
			flag = false;		
		}
		else
		{
			gotoXY(75, 32);
			textColor(100);
			cout << "NOT FOUND";
			char key = _getch();
			textColor(240);
		}
	}
}
void _Game::loadGame(string name)
{
	// Doc file 
	fstream f;
	int status;
	f.open(name, ios::in);
	if (!f)
	{
		// cout nay kia kia no
	}
	else
	{
		f >> turnX >> turnO >> option >> _turn;
		for (int i = 0; i < _b->getSize(); i++)
			for (int j = 0; j < _b->getSize(); j++)
			{
				f >> status;
				_b->setCheck(i, j, status);			
			}
		_x = _b->getXAt(0, 0);
		_y = _b->getYAt(0, 0);
		_b->drawBoard();
		f.close();
	}

	f.close();
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

void _Game::saveGame()
{
	string data;
	string temp;
	fstream input;
	ofstream f1;
	ofstream f2;
	input.open("Name.txt", ios::in);
	while (!input.eof())
	{
		input >> temp;
		_Game::fileName.insert(temp);
	}
	input.close();
	bool flag = true;
	do
	{
		system("cls");
		backGround(65, 14, 50, 10, 112);
		backGround(60, 13, 50, 10, 192);
		
		textColor(192);
		gotoXY(65, 15);
		cout << "ENTER FILE NAME: ";
		textColor(203);
		getline(cin, data);

		set <string> ::iterator it;
		it = fileName.find(data);
		if (it != fileName.end())
		{
			textColor(100);
			gotoXY(65, 19);
			hidePtr();
			cout << "    FILE NAME HAVE EXITED! TRY AGAIN    ";
			char key = _getch();
			textColor(240);
		}
		else
		{
			textColor(100);
			gotoXY(80, 19);
			cout << "   DONE!!   ";
			textColor(240);
			flag = false;
		}
	} while (flag == true);


	f1.open(data, ios::out);
	f2.open("Name.txt", ios::app);
	f2 << data << " " << endl;
	//thong tin
	f1 << turnX << " " << turnO << " " <<  option << " " << _turn << endl;
	for (int i = 0; i < _b->getSize(); i++)
	{
		for (int j = 0; j < _b->getSize(); j++)
		{
			f1 << _b->get_Check(i, j) << " ";
		}
		f1 << endl;
	}
	f1.close();
	f2.close();
	_Common::gotoXY(78, 21);
	textColor(192);
	cout << "ESC : BACK";
	textColor(240);
	int t = 1;
	while (t)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 27:
				return;
				break;
			}
		}
	}
}

int _Game::getTurn()
{
	return _turn;
}