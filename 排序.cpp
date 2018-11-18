#include "stdio.h"
#include "iostream "
#include"fstream"
#include "ctime"
#include "cstdlib"
#include"stdlib.h"
using namespace std;
void Maopao(int a[]) {

	long long start = clock();
	int t;
	for (int i = 0; i < 5000 - 1; i++) {
		for (int j = 0; j < 5000 - 1 - i; j++)
		{
			if (a[j] > a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < 5000; i++)
		cout << a[i] << "  ";
	cout << endl;
	long long end = clock();
	cout << "\n时间为\n" << endl;
	cout << double(end - start) / CLOCKS_PER_SEC << endl;

}
void Choose(int a[]) {
	long long start = clock();
	int mix, temp;
	for (int i = 0; i < 5000; i++) {
		mix = i;
		for (int j = i + 1; j < 5000; j++)
			if (a[j] < a[mix])
				mix = j;
		if (i != mix) {
			temp = a[i];
			a[i] = a[mix];
			a[mix] = temp;
		}
	}
	for (int i = 0; i < 5000; i++)
		cout << a[i] << "  ";
	cout << endl;
	long long end = clock();
	cout << "\n时间为\n" << endl;
	cout << double(end - start) / CLOCKS_PER_SEC << endl;

}
void insert(int a[]){
	long long start = clock();
	int i, j, k  ;

	   for (i = 1; i < 5000; i++)
	     {
		        //为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置
			       for (j = i - 1; j >= 0; j--)
		           if (a[j] < a[i])
		        break;
		
			         //如找到了一个合适的位置
			         if (j != i - 1)
			         {
			             //将比a[i]大的数据向后移
				            int temp = a[i];
			            for (k = i - 1; k > j; k--)
			                 a[k + 1] = a[k];
		             //将a[i]放到正确位置上
				            a[k + 1] = temp;
			        }
		    }
	   for (int i = 0; i < 5000; i++)
		  cout << a[i] << "  ";
	   cout << endl;
	   long long end = clock();
	   cout << "\n时间为\n" << endl;
	   cout << double(end - start) / CLOCKS_PER_SEC << endl;
}

void shellsort(int a[]) {
	long long start = clock();
	int i, j;
	int r, temp;
	int x = 0;
	for (r = 5000 / 2; r >= 1; r /= 2)//r>=1保证至少有两个可以比较的数，r/=2确定序列对
	{
		for (i = r; i < 5000; i++)
		{
			temp = a[i];
			j = i - r;
			while (j >= 0 && temp < a[j])//对配对的两个数进行比较
			{
				a[j + r] = a[j];
				j -= r;
			}
			a[j + r] = temp;
		}
	}
	for (int i = 0; i < 5000; i++)
		cout << a[i] << "  ";
	cout << endl;
	long long end = clock();
	cout << "\n时间为\n" << endl;
	cout << double(end - start) / CLOCKS_PER_SEC << endl;
}
	


int main(){
  ofstream out;
  out.open("test.txt");
  ifstream in;
  in.open("test.txt");
  srand(static_cast<unsigned int>(time(NULL)));
  for (int i = 0; i < 5000; i++)
	  
  out.close();
  int a[5000];
  int i;
  int *p;
 for (i = 0; i < 5000; i++) 
	  in >> a[i];
    in.close();	  
   int ch;
  while (1) {
	  printf("请选择排序算法 \n 1：冒泡排序\n 2: 选择排序 \n 3：插入排序 \n 4:shell排序 \n \n \n");
	  scanf_s("%d", &ch);
	  switch (ch) {
	  case 1:  Maopao(a); continue;
	  case 2:  Choose(a); continue;
	  case 3:  insert(a); continue;
	  case 4:  shellsort(a); continue;
	  }
  }
  system("pause");
  return 0;

}
