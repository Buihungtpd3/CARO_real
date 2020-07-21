#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;
// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
int main()
{
	//resize man hinh
	resizeConsole(900, 600);
	//system("color F1");
	// Doi mau chu 
	textcolor(12);
	cout << "HELLO CC" << endl;
	textcolor(11);
	cout << "......ok" << endl;
	// Nhan phim nhap vao 
	cout << "Nhap dai mot phim nao do: ";
	while (true)
	{
		fflush(stdin);
		if (_kbhit())
		{
			char c = _getch();
			cout << "\nDay la dai tieng noi Viet Nam. Phat thanh tu  " << c << " ===>Nuoc CHXHCNVN" << endl;
			break;
		}
	}
	cout << "Continue? <Y/N> ";
	char conti; 
	cin >> conti;
	// Tam dung 
	cout << "\nDong thu nhat ";
	cout << "\nDoi 2s";
	Sleep(2000);
	cout << "\nDong thu 2";
	//Di chuyen den vi tri thu x thu y
	//gotoxy(1, 600);
	Sleep(2000);
	cout << "\n\n\n";	
	return 0;
}