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
		//由于已知道子数组a[p:i]中的元素均小于要找的第k小元素
		//因此，要找的a[p:r]中第k小元素是a[i+1:r]中第k-j小元素。
		return RandomizedSelect(a, i + 1, r, k - j);
	}
}

template <class Type>
void BubbleSort(Type a[], int p, int r)
{
	//记录一次遍历中是否有元素的交换   
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
		//如果这次遍历没有元素的交换,那么排序结束   
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
	//(r-p-4)/5相当于n-5
	for (int i = 0; i <= (r - p - 4) / 5; i++)
	{
		//将元素每5个分成一组，分别排序，并将该组中位数与a[p+i]交换位置
		//使所有中位数都排列在数组最左侧，以便进一步查找中位数的中位数
		BubbleSort(a, p + 5 * i, p + 5 * i + 4);
		Swap(a[p + 5 * i + 2], a[p + i]);
	}
	//找中位数的中位数
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
		printf("请选择：\n 1:随即划分线性选择\n 2:中位数线性选择\n");
		scanf_s("%d", &s);
		switch (s)
		{

		case 1: {

			for (int i = 0; i < 5001; i++)
			{
				cout << a[i] << "  ";
			}
			cout << endl;
			printf("请选择第多少小的数\n");
			scanf_s("%d", &z);
			cout << "第k小元素是\n" <<RandomizedSelect(a, 0, 4999, z) << endl;
			//重新排序，对比选择结果
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

			printf("请选择第多少小的数\n");
			scanf_s("%d", &z);
			cout << "第k小元素是\n" << Select(a, 0, 4999, z) << endl;

			//重新排序，对比结果
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
	



