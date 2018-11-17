#include <iostream>
#include"stdlib.h"
#include"stdio.h"
using namespace std;

int size = 0;
static int tile = 1;
static int board[100][100] = { 0 };

void chess_board(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)
		return;

	int t = tile++;   //tile means ��Ƭ����ʯ�����ǵĲ���
	int sz = size / 2;    //ÿ�ν��л���

	//cover top left corner
	if (dr < tr + sz && dc < tc + sz)     //notice < <   //ע��һ�����������<>=�⼸������Ҫ���ƺñ߽�
		chess_board(tr, tc, dr, dc, sz);
	else {
		board[tr + sz - 1][tc + sz - 1] = t;
		chess_board(tr, tc, tr + sz - 1, tc + sz - 1, sz);
	}

	//cover top right corner
	if (dr < tr + sz && dc >= tc + sz)   //notice < >=
		chess_board(tr, tc + sz, dr, dc, sz);
	else {
		board[tr + sz - 1][tc + sz] = t;
		chess_board(tr, tc + sz, tr + sz - 1, tc + sz, sz);
	}

	//cover lower left corner
	if (dr >= tr + sz && dc < tc + sz)   //notice >= <
		chess_board(tr + sz, tc, dr, dc, sz);
	else {
		board[tr + sz][tc + sz - 1] = t;
		chess_board(tr + sz, tc, tr + sz, tc + sz - 1, sz);
	}

	//cover lower right corner
	if (dr >= tr + sz && dc >= tc + sz)  //notice >= >=
		chess_board(tr + sz, tc + sz, dr, dc, sz);
	else {
		board[tr + sz][tc + sz] = t;                       //���һ������������
		chess_board(tr + sz, tc + sz, tr + sz, tc + sz, sz);   //�ݹ�ò���
	}
}

void print_chess_board()
{
	int size=4;
	cout.setf(ios::left);     //�����
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout.width(3);    //��ӡ���Ϊ3
			cout << board[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int size = 0;
	cout << "������size" << endl;
	cin >> size;
	chess_board(0, 0, 3, 4, size);
	print_chess_board();
	system("pause");
	return 0;
}
