#include"_Game.h"
#include"_Common.h"
#include"_Board.h"
#include"_Point.h"
#include"_Menu.h"
#include <iostream>
#include<conio.h>
#include <math.h>
using namespace std;
_Board _b(10, 10, 10);
int Minimax(_Board &_b, int i, int j, int depth, bool isMax, int alpha, int beta)
{
		if (depth == 0)
		{
			int score = _b.getScore(i, j, depth);
		}
		//if maximizer
		if (isMax)
		{
			int best = INT_MIN;

			// Traverse all cells 
			for (int i = 0; i < _b.getSize(); i++)
			{
				for (int j = 0; j < _b.getSize(); j++)
				{
					// Check if cell is empty 
					if (_b.getParr(i,j).getCheck() == 0)
					{
						// Make the move 
						_b.getParr(i, j).setCheck(1);

						// Call minimax recursively and choose 
						// the maximum value 
						int val = max(best,Minimax (_b,i,j, depth-1, !isMax,alpha,beta));
						best = max(best, val);
						alpha = max(alpha, best);
						// Undo the move 
						_b.getParr(i, j).setCheck(0);

						// Alpha Beta Pruning 
						if (beta <= alpha)
							break;
					}
				}
			}
			return best;
		}

		// If this minimizer's move 
		else
		{
			int best = INT_MAX;

			// Traverse all cells 
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					// Check if cell is empty 
					if (_b.getParr(i,j).getCheck() == 0)
					{
						// Make the move 
						_b.getParr(i, j).setCheck(-1);

						// Call minimax recursively and choose 
						// the minimum value 
						int val = min(best, Minimax(_b, i, j, depth - 1, !isMax,alpha,beta));
						best = min(best, val);
						beta = min(beta, best);
						// Undo the move 
						_b.getParr(i, j).setCheck(0);
						// Alpha Beta Pruning 
						if (beta <= alpha)
							break;
					}
				}
			}
			return best;
		}
}
_Point* findTheBestMove(_Board &_b)
{
	_Point* ocurPtr = new _Point;
	int moveVal = 0;
	int bestMove = INT_MIN;
	int a = INT_MIN;
	int b = INT_MAX;
	bool isMAX = true;
	
	for (int i = 0; i < _b.getSize(); i++)
		for (int j = 0; j < _b.getSize(); j++)
		{
			if (_b.getParr(i, j).getCheck() == 0)
			{
				_b.getParr(i, j).setCheck(1);
				moveVal = Minimax(_b,i, j, _b.getSize() / 2,!isMAX,a,b);
				_b.getParr(i, j).setCheck(0);
				if (moveVal > bestMove)
				{
					bestMove = moveVal;
					ocurPtr->setX(_b.getParr(i, j).getX());
					ocurPtr->setY(_b.getParr(i, j).getY());
				}
			}
		}
	
	return ocurPtr;
}
int main()
{
	int moveVal = 0;
	int bestMove = INT_MIN;
	int a = INT_MIN;
	int b = INT_MAX;
	bool isMAX = true;
	
	_b.resetData();
	_b.getParr(0, 0).setCheck(-1);
	_b.getParr(0, 1).setCheck(-1);
	cout << "Vi tri (0,0)" << endl;
	cout << _b.getParr(0, 0).getX() << endl;
	cout << _b.getParr(0, 0).getY() << endl;
	cout << "Vi tri (0,1)" << endl;
	cout << _b.getParr(0, 1).getX() << endl;
	cout << _b.getParr(0, 1).getY() << endl;

	_Point* cur = new _Point;
	cur = findTheBestMove(_b);
	cout << "Vi tri danh co" << endl;
	cout << cur->getX() << endl;
	cout << cur->getY();

	
	return 0;
}