#include "_Common.h"
void _Common::gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void _Common::fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void _Common::resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void _Common::textColor(int x)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);

}
void _Common::backGround(int left, int top, int wide, int height, int color)
{
	gotoXY(left, top);
	textColor(color);
	for (int i = left; i < wide + left; i++)
		for (int j = top; j < height + top; j++)
		{
			gotoXY(i, j);
			string a = " ";
			cout << a;
		}
}
void  _Common::cheoTrai(int left, int top, int dai, int cao, int color)
{
	textColor(color);
	int h = 0;
	for (int i = left; i <= dai + left; i++)
	{
		int k = 0;
		for (int j = cao + top; j >= top; j--)
		{
			if (h == k)
			{

				gotoXY(i, j);
				cout << "   ";
			}
			k++;
		}
		h++;
	}


}
void  _Common::cheoPhai(int left, int top, int dai, int cao, int color)
{
	textColor(color);
	int h = 0;
	for (int i = left; i <= left + dai; i++)
	{
		int k = 0;
		for (int j = top; j <= top + cao; j++)
		{
			if (h == k)
			{

				gotoXY(i, j);
				cout << "   ";
			}
			k++;
		}
		h++;
	}
}
void  _Common::veNgang(int left, int top, int dai, int color)
{
	textColor(color);
	for (int i = left; i <= left + dai; i++)
	{
		gotoXY(i, top);
		cout << "  ";
	}
}
void  _Common::veDoc(int left, int top, int dai, int color)
{
	textColor(color);
	for (int i = top; i <= top + dai; i++)
	{

		gotoXY(left, i);
		cout << "   ";
	}
}
//Ham ve vien tren , duoi ========================================================================
void _Common::drawUpLine(int left, int top, char symbol1, char symbol2, char symbol3, int size)
{
	gotoXY(left, top);//Dua con tro den vi tri dau ban co
	for (int i = 0; i <= size * 4; i++)
	{
		if (i == 0) cout << symbol1;//218 la ma ascii cua goc vuong ben trai phia tren
		else if (i == size * 4) cout << symbol2;//191 la ma ascii cua goc vuong phai phia tren
		else cout << symbol3;
	}
}

//Ham ve vien trai, phai =============================================================================
void _Common::drawSlideLine(int left, int top, char symbol, int size)
{
	gotoXY(left, top);
	for (int i = 0; i < size * 2 - 1; i++)
	{
		gotoXY(left, i + top + 1);
		cout << symbol;
	}
}