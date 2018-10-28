#include "stdio.h"
#include "iostream "
#include"fstream"
#include "ctime"
#include "cstdlib"
#include"stdlib.h"
using namespace std;
void Maopao(int a[]) {
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
		cout << a[i] << " ";
	cout << endl;
}
void Choose(int a[]) {
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
		cout << a[i] << " ";
	cout << endl;

}
void insert(int a[]){
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
		  cout << a[i] << " ";
	   cout << endl;

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
  for (int i = 0; i < 5000; i++)
  {
	  a[i] = rand() % 100000;
	  
	 
  }
  p = a;
   for (int i=0;i<5000;i++)  
	  in.close();
  long long start =clock();
  int ch;
  while (1) {
	  printf("请选择排序算法 \n 1：冒泡排序\n 2: 选择排序 \n 3：插入排序 \n 4:shell排序 \n 5：归并排序 \n 6：快速排序 \n ");
	  scanf_s("%d", &ch);
	  switch (ch) {
	  case 1:  Maopao(a);
	  case 2:  Choose(a);
	  case 3:  insert(a);
	  }

  }
  

  long long end=clock();
  cout<<double(end-start)/CLOCKS_PER_SEC<<endl;

  system("pause");
  return 0;

}
