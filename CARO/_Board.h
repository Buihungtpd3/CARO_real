#ifndef _Board_H
#define _Board_H
#include "_Menu.h"
#include "_Point.h"
#include "_Common.h"
// Mảng điểm tấn công và phòng thủ cho máy (Khó) 
const  long Defend_Score1[7] = { 0, 8, 512, 32768, 2097152, 134217728 };
const  long Attack_Score1[7] = { 0, 64, 4096, 262144, 16777216, 1073741824 };
// Mảng điểm tấn công và phòng thủ cho máy (dễ)
const  long Defend_Score2[7] = { 1, 2, 3, 1, 1, 1 };
const  long Attack_Score2[7] = { 2, 3, 4, 5, 6, 7 };

class _Board {
	int _size;
	int _left, _top;
	int cdraw = 0;
	_Point** _pArr;
	int _cdraw = 0;


public:
	//Contructor & destructor menthod
	_Board();
	_Board(int, int, int);
	~_Board();
public:
	//Bacsic menthod
	int getSize(); // Kích thước bàn cờ
	int getLeft();// Lề trái
	int getTop(); // Lề phải
	int getXAt(int, int); // Tọa độ x tại vị trí i, j trên bàn cờ
	int getYAt(int, int);// Tọa độ y tại vị trí i, j trên bàn cờ
	void resetData();// Đặt lại trạng thái các ô trên bàn cờ
	void drawBoard();// Vẽ bàn cờ
public:
	void loadData(int i, int j, int k);
	int checkBoard(int, int, bool);// Trả về kết quả thắng thua 
	int testBoard(int, int, bool);// Kiểm tra thắng thua trái phải ngang dọc 
	bool checkRow(int, int);// Kiểm tra trên hàng 
	bool checkColum(int, int);// kiểm tra trên cột
	bool checkMainDioganal(int, int);// Kiểm tra chéo chính
	bool checkSubDioganal(int, int);// Kiểm tra chéo phụ
	bool checkDraw();// Kiểm tra hòa hay không ?
	int get_Check(int i, int j) { return _pArr[i][j].getCheck(); }
	void setCheck(int i, int j, int val);
	int getCDraw();// Tổng sô nước đi hiện tại 
	_Point& getParr(int, int);// trả về bàn cờ
public:
	//Choi
	_Point findTheBestMove_1(); // Tìm nước đi (Khó): Sau khi tìm trả về tọa độ x, y
	_Point findTheBestMove_2(); // Tìm nước đi (Dễ): Sau khi tìm trả về tọa độ x, y
	long SoDiemTanCong_DuyetDoc(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemTanCong_DuyetNgang(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemTanCong_DuyetCheo1(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemTanCong_DuyetCheo2(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemPhongThu_DuyetDoc(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemPhongThu_DuyetNgang(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemPhongThu_DuyetCheo1(long, long, const long Defend_Score[], const long Attack_Score[]);
	long SoDiemPhongThu_DuyetCheo2(long, long, const long Defend_Score[], const long Attack_Score[]);

};
#endif
