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
		        //Ϊa[i]��ǰ���a[0...i-1]������������һ�����ʵ�λ��
			       for (j = i - 1; j >= 0; j--)
		           if (a[j] < a[i])
		        break;
		
			         //���ҵ���һ�����ʵ�λ��
			         if (j != i - 1)
			         {
			             //����a[i]������������
				            int temp = a[i];
			            for (k = i - 1; k > j; k--)
			                 a[k + 1] = a[k];
		             //��a[i]�ŵ���ȷλ����
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
	  printf("��ѡ�������㷨 \n 1��ð������\n 2: ѡ������ \n 3���������� \n 4:shell���� \n 5���鲢���� \n 6���������� \n ");
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
