#include "stdio.h"
#include "iostream "
#include"fstream"
#include "ctime"
#include "cstdlib"
#include"stdlib.h"
#include <iostream> 
#include <ctime>
using namespace std;


template <class Type>
void Swap(Type &x, Type &y);

inline int Random(int x, int y);

template <class Type>
int Partition(Type a[], int p, int r);

template<class Type>
int RandomizedPartition(Type a[], int p, int r);

template <class Type>
Type RandomizedSelect(Type a[], int p, int r, int k);

template <class Type>
void BubbleSort(Type a[], int p, int r);

template <class Type>
int Partition2(Type a[], int p, int r, Type x);

template <class Type>
Type Select(Type a[], int p, int r, int k);

template <class Type>
void Swap(Type &x, Type &y)
{
	Type temp = x;
	x = y;
	y = temp;
}

inline int Random(int x, int y)
{
	srand((unsigned)time(0));
	int ran_num = rand() % (y - x) + x;
	return ran_num;
}

template <class Type>
int Partition(Type a[], int p, int r)
{
	int i = p, j = r + 1;
	Type x = a[p];

	while (true)
	{
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j)
		{
			break;
		}
		Swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

template<class Type>
int RandomizedPartition(Type a[], int p, int r)
{
	int i = Random(p, r);
	Swap(a[i], a[p]);
	return Partition(a, p, r);
}

template <class Type>
Type RandomizedSelect(Type a[], int p, int r, int k)
{
	if (p == r)
	{
		return a[p];
	}
	int i = RandomizedPartition(a, p, r);
	int j = i - p + 1;
	if (k <= j)
	{
		return RandomizedSelect(a, p, i, k);
	}
	else
	{
		//������֪��������a[p:i]�е�Ԫ�ؾ�С��Ҫ�ҵĵ�kСԪ��
		//��ˣ�Ҫ�ҵ�a[p:r]�е�kСԪ����a[i+1:r]�е�k-jСԪ�ء�
		return RandomizedSelect(a, i + 1, r, k - j);
	}
}

template <class Type>
void BubbleSort(Type a[], int p, int r)
{
	//��¼һ�α������Ƿ���Ԫ�صĽ���   
	bool exchange;
	for (int i = p; i <= r - 1; i++)
	{
		exchange = false;
		for (int j = i + 1; j <= r; j++)
		{
			if (a[j] < a[j - 1])
			{
				Swap(a[j], a[j - 1]);
				exchange = true;
			}
		}
		//�����α���û��Ԫ�صĽ���,��ô�������   
		if (false == exchange)
		{
			break;
		}
	}
}

template <class Type>
int Partition2(Type a[], int p, int r, Type x)
{
	int i = p - 1, j = r + 1;

	while (true)
	{
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j)
		{
			break;
		}
		Swap(a[i], a[j]);
	}
	return j;
}


template <class Type>
Type Select(Type a[], int p, int r, int k)
{
	if (r - p < 75)
	{
		BubbleSort(a, p, r);
		return a[p + k - 1];
	}
	//(r-p-4)/5�൱��n-5
	for (int i = 0; i <= (r - p - 4) / 5; i++)
	{
		//��Ԫ��ÿ5���ֳ�һ�飬�ֱ����򣬲���������λ����a[p+i]����λ��
		//ʹ������λ������������������࣬�Ա��һ��������λ������λ��
		BubbleSort(a, p + 5 * i, p + 5 * i + 4);
		Swap(a[p + 5 * i + 2], a[p + i]);
	}
	//����λ������λ��
	Type x = Select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10);
	int i = Partition2(a, p, r, x);
	int j = i - p + 1;
	if (k <= j)
	{
		return Select(a, p, i, k);
	}
	else
	{
		return Select(a, i + 1, r, k - j);
	}
}
int main()
{
	int z,s;
	ofstream out;
	out.open("test.txt");
	ifstream in;
	in.open("test.txt");
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < 5000; i++) {
		out << rand() % 100000 << endl;
	}
	for (int i = 0; i < 5000; i++)
		out.close();
	int a[5000];
	int i;
	for (i = 0; i < 5000; i++)
		in >> a[i];
	in.close();

	while (1) {
		printf("��ѡ��\n 1:�漴��������ѡ��\n 2:��λ������ѡ��\n");
		scanf_s("%d", &s);
		switch (s)
		{

		case 1: {

			for (int i = 0; i < 5001; i++)
			{
				cout << a[i] << "  ";
			}
			cout << endl;
			printf("��ѡ��ڶ���С����\n");
			scanf_s("%d", &z);
			cout << "��kСԪ����\n" <<RandomizedSelect(a, 0, 4999, z) << endl;
			//�������򣬶Ա�ѡ����
			BubbleSort(a, 0, 5000);

			for (int i = 0; i < 5000; i++)
			{
				cout << "a[" << i << "]:" << a[i] << " ";
			}
			cout << endl;
			system("pause");

		}
				continue;

		case 2: {

			for (int i = 0; i < 5000; i++)
			{
				cout <<a[i] << "  ";
			}
			cout << endl;

			printf("��ѡ��ڶ���С����\n");
			scanf_s("%d", &z);
			cout << "��kСԪ����\n" << Select(a, 0, 4999, z) << endl;

			//�������򣬶ԱȽ��
			BubbleSort(a, 0, 5000);

			for (int i = 0; i < 5000; i++)
			{
				cout << "a[" << i << "]:" << a[i] << " ";
			}
			cout << endl;

		}
				continue;
		default:
			break;
		}
	}
}
	



