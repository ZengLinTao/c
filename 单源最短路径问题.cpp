    #include <iostream>
	#include <cstdio>
    #include <queue>
		 using namespace std;
	
		 #define maxn 110        //��󶥵����
		 #define INF 0xffffff    //Ȩֵ����
		 int w[maxn][maxn];      //�ڽӾ��󣬴洢Ȩֵ
	 int n;                  //�������
	
		 struct node             //����ڵ㣬����id�͵�Դ����Ĺ�����룬���ȶ�����Ҫ������
		 {
		     int id, weight;     //Դ����id�͹������
		     friend bool operator<(node a, node b)   //��Ҫʵ����С�ѣ����������У������Ҫ������������ض������ȼ�����СΪ��
			     {
			         return a.weight > b.weight;
			     }
		 };
	 priority_queue<node> q;     //���ȶ��У���С�ѣ�ʵ��Dijkstra����Ҫ���ݽṹ����stlʵ��
	 int parent[maxn];           //ÿ������ĸ��׽ڵ㣬�������ڻ�ԭ���·����
 bool visited[maxn];         //�����ж϶����Ƿ��Ѿ������·�����У�����˵�Ƿ����ҵ����·��
	 node d[maxn];               //Դ�㵽ÿ�����������룬�����ΪԴ�㵽���ж�������·��
	 void Dijkstra(int s)        //Dijkstra�㷨������Դ����
		 {
		     for (int i = 1; i <= n; i++)     //��ʼ��
			     {
			         d[i].id = i;
			         d[i].weight = INF;          //���������INF
			         parent[i] = -1;             //ÿ�����㶼�޸��׽ڵ�
			         visited[i] = false;
			     }
		     d[s].weight = 0;                //Դ�㵽Դ�����·ȨֵΪ0
		     q.push(d[s]);                   //ѹ�������
		     while (!q.empty())               //�㷨�ĺ��ģ����п�˵������˲���
			     {
			         node cd = q.top();          //ȡ��С������붥��
			         q.pop();
			         int u = cd.id;
			         if (visited[u])
				             continue;
			         visited[u] = true;
			         //�ɳڲ���
				        for (int v = 1; v <= n; v++) //�������������ڵĶ��㣬�����ɳڲ��������¹�����룬ѹ����С�
				         {
				             if (v != u && !visited[v] && d[v].weight > d[u].weight + w[u][v])
					             {
					                 d[v].weight = d[u].weight + w[u][v];
					                 parent[v] = u;
					                 q.push(d[v]);
					             }
				         }
			     }
		 }
    int main()
		 {
		     int m, a, b, c, st, ed;
		     printf("�����붥�����ͱ�����\n");
		     scanf_s("%d%d", &n, &m);
		     printf("��������Լ�Ȩֵ��a, b, c)\n");
		     for (int i = 1; i <= n; i++)     //�ڽӾ���洢ǰ��Ҫ��ʼ��
			         for (int j = i; j <= n; j++)
			             w[i][j] = w[j][i] = INF;
		     while (m--)
			     {
			         scanf_s("%d%d%d", &a, &b, &c);
			         if (w[a][b] > c)
				             w[a][b] = w[b][a] = c;
			    }
		     printf("�����������յ㣺\n");
		     scanf_s("%d%d", &st, &ed);
		     Dijkstra(st);
		     if (d[ed].weight != INF)
			         printf("���·��ȨֵΪ��%d\n", d[ed].weight);
		     else
			         printf("�����ڴӶ���%d������%d�����·����\n", st, ed);
			 system("pause");
		     return 0;
		 }
	

