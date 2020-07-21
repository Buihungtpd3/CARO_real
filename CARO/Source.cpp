

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
const dong = 25, cot = 50, x = cot / 2, y = dong / 2;
/* Thu tuc ve 1 dong */
void Ve_1d(int x2, char c1++)
c {
	printf("%c%c", c2, c3);
	cprintf("%c%c", c2, c4);
	, char c2, char c3, char c4)
	cprintf for (int i = 1; i <= (x2 - 3) / 2; i
}
//============================================
/* Thu tuc ke bang */
void Ke_bang(int x1, int y1, int x2, int y2)
{
	gotoxy(x1, y1);
		Ve_1d(x2, 'Ú', 'Ä', 'Â', '¿');
		for (int i = 1; i < (y2 - y1); i++)
		{
			gotoxy(x1, y1 + i);
				Ve_1d(x2, 'Ã', 'Ä', 'Å', ' ́');
		}
	gotoxy(x1, y2);
	Ve_1d(x2, 'À', 'Ä', 'Á', 'Ù');
}
//============================================
/* Thu tuc nhap ho ten nguoi choi */
void Nhap_HoTen(char* Ten[])
{
	for (int k = 0; k < 2; k++)
	{
		printf("Nhap ho ten nguoi thu %d=", k + 1);
		gets(Ten[k]);
	}
}
//============================================
/* Thu tuc bam phim qua trai */
void Qua_Trai(int& l, int dx)
{
	if (l == -x / dx)
		l = (x + 1) / dx;
	else l--;
}
/* Thu tuc bam phim qua phai */
void Qua_Phai(int& l, int dx)
{
	if (l == (x + 1) / dx)
		l = -x / dx;
	else l++;
}
/* Thu tuc bam phim di len */
void Di_Len(int& k, int dy)
{
	if (k == -(y - 1) / dy)
		k = (y + 1) / dy;
	else k--;
}
//============================================
/* Thu tuc bam phim di xuong */
void Di_Xuong(int& k, int dy)
{
	if (k == (y + 1) / dy)
		k = -(y - 1) / dy;
	else k++;
}
//============================================
/* Ham kiem tra duong cheo goc trai */
int Ktra_DuongCheo1(int A[dong][cot], int k, int l, int > D, int > C)
{
	int i, j, m;
	for (i = k - 1, j = l - 1, m = 1; i >= k - 5; i--, j--)
		if (A[y + k][x + l] == A[y + i][x + j])
			m++;
		else
		{
			GTD = A[y + i][x + j];
			break;
		}
	for (i = k + 1, j = l + 1; i <= k + 5; i++, j++)
		if (A[y + k][x + l] == A[y + i][x + j])
			m++;
		else
		{
			GTC = A[y + i][x + j];
			break;
		}
	return m;
}
//============================================
/* Ham kiem tra duong thang dung */
int Ktra_DuongThang(int A[dong][cot], int k, int l, int > D, int > C)
{
	int i, m;
	for (i = k - 1, m = 1; i >= k - 5; i--)
		if (A[y + k][x + l] == A[y + i][x + l])
			m++;
		else
		{
			GTD = A[y + i][x + l];
			break;
		}
	for (i = k + 1; i <= k + 5; i++)
		if (A[y + k][x + l] == A[y + i][x + l])
			m++;
		else
		{
			GTC = A[y + i][x + l];
			break;
		}
	return m;
}
//============================================
/* Ham kiem tra duong cheo goc phai */
int Ktra_DuongCheo2(int A[dong][cot], int k, int l, int > D, int > C)
{
	int i, j, m;
	for (i = k - 1, j = l + 1, m = 1; i >= k - 5; i--, j++)
		if (A[y + k][x + l] == A[y + i][x + j])
			m++;
		else
		{
			GTD = A[y + i][x + j];
			break;
		}
	for (i = k + 1, j = l - 1; i <= k + 5; i++, j--)
		if (A[y + k][x + l] == A[y + i][x + j])
			m++;
		else
		{
			GTC = A[y + i][x + j];
			break;
		}
	return m;
}
//============================================
/* Ham kiem tra duong ngang */
int Ktra_DuongNgang(int A[dong][cot], int k, int l, int > D, int > C)
{
	int j, m;
	for (j = l - 1, m = 1; j >= l - 5; j--)
		if (A[y + k][x + l] == A[y + k][x + j])
			m++;
		else
		{
			GTD = A[y + k][x + j];
			break;
		}
	for (j = l + 1; j <= l + 5; j++)
		if (A[y + k][x + l] == A[y + k][x + j])
			m++;
		else
		{
			GTC = A[y + k][x + j];
			break;
		}
	return m;
}
//============================================
/* Ham kiem tra thang chua */
int Ktra_Thang(int A[dong][cot], int k, int l)
{
	int m, GTD, GTC, SoLan = 0;
	while (SoLan++ <= 4)
	{
		switch (SoLan)
		{
		case 1:
			m = Ktra_DuongCheo1(A, k, l, GTD, GTC);
			break;
		case 2:
			m = Ktra_DuongThang(A, k, l, GTD, GTC);
			break;
		case 3:
			m = Ktra_DuongCheo2(A, k, l, GTD, GTC);
			break;
		case 4:
			m = Ktra_DuongNgang(A, k, l, GTD, GTC);
			break;
		}
		if ((m == 5) && ((GTD == 0) || (GTC == 0)))
			return 1;
	}
	return 0;
}
/* Ham luu va xuat quan co */
char LuuXuat_QuanCo(int A[dong][cot], int k, int l, int Co)
{
	int So, mau;
	So = (Co == 'X') ? 1 : 2;
	mau = (Co == 'X') ? 12 : 14;
	if (A[y + k][x + l] == 0)
	{
		A[y + k][x + l] = So;
		textcolor(mau);
		putch(Co);
		if (Ktra_Thang(A, k, l) != 1)
			switch (Co)
			{
			case 'X':
				Co = 'O';
				break;
			case 'O':
				Co = 'X';
				break;
			}
	}
	return Co;
}
void main()
{
	int A[dong][cot], k, l, K_Tra, flag;
	const dx = 2, dy = 1;
	char* Ten[2];
	char ch, Co;
start:
	textattr(0x07);
	clrscr();
	Nhap_HoTen(Ten);
	printf("Ban %s chon quan co di truoc (X/O)=", Ten[0]);
	Co = toupper(getch());
	flag = (Co == 'X') ? 0 : 1;
	/* Tao gia tri 0 cho mang A[][] */
	for (k = 0; k < dong; k++)
		for (l = 0; l < cot; l++)
			A[k][l] = 0;
	clrscr();
	gotoxy(56, 1);
	textattr(0x5E + 128);
	cprintf("Tro Choi Caro !");
	textattr(0x07);
	/* Ke ban co caro */
	textcolor(2);
	Ke_bang(1, 1, cot, dong);
	textcolor(7);
	k = 0, l = 0;
	do
	{
		gotoxy(x + l * dx, y + k * dy);
		ch = getch();
		if (ch == 27) goto thoat;
		if (ch == '\0')
		{
			ch = getch();
			switch (ch)
			{
			case 'K':
				Qua_Trai(l, dx);
				break; // Trai
			case 'M':
				Qua_Phai(l, dx);
				break; // Phai
			case 'H':
				Di_Len(k, dy);
				break; // Len
			case 'P':
				Di_Xuong(k, dy);
				break; // Xuong
			}
		} // if (ch=='\0' )
		else
			if (ch == 13)
				switch (Co)
				{
				case 'X':
					Co = LuuXuat_QuanCo(A, k, l, Co);
				case 'O':
					Co = LuuXuat_QuanCo(A, k, l, Co);
				} // switch (Co)
		K_Tra = Ktra_Thang(A, k, l);
	} while ((ch != 27) && (K_Tra != 1));
	gotoxy(50, 23);
	textcolor(13);
	if ((K_Tra == 1) && (flag == 0))
		cprintf("Ban %s da thang !", Ten[A[y + k][x + l] - 1]);
	if ((K_Tra == 1) && (flag == 1))
		cprintf("Ban %s da thang !", Ten[2 - A[y + k][x + l]]);
thoat:
	gotoxy(50, 25);
	textcolor(11);
	cprintf("Ban co tiep tuc khong <Y/N> ?");
	textcolor(7);
	ch = getch();
	if (toupper(ch) == 'Y')
		goto start;
}
