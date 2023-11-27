#include"graph.h"
#include<ege/sys_edit.h>
#include<iostream>
#include<string>
#include <graphics.h>
#define SHOW_CONSOLE
using namespace std;


void show(graph& gra, int& num, node* n)//构建图
{
	if (gra.numver == 0)return;
	fillellipse(500, 600, 23, 23);//A
	n[0].x = 500; n[0].y = 600;
	char ch[100] = { NULL };
	xyprintf(500, 600, "A");
	fillellipse(200, 400, 23, 23);//B
	n[1].x = 200; n[1].y = 400;
	xyprintf(200, 400, "B");

	fillellipse(550, 420, 23, 23);//C
	n[2].x = 550; n[2].y = 420;
	xyprintf(550, 420, "C");

	fillellipse(800, 400, 23, 23);//D
	n[3].x = 800; n[3].y = 400;
	xyprintf(800, 400, " D");

	fillellipse(100, 380, 23, 23);//E
	n[4].x = 100; n[4].y = 380;
	xyprintf(100, 380, "E");

	fillellipse(200, 300, 23, 23);//F
	n[5].x = 200; n[5].y = 300;
	xyprintf(200, 300, "F");

	fillellipse(400, 250, 23, 23);//G
	n[6].x = 400; n[6].y = 250;
	xyprintf(400, 250, "G");

	fillellipse(780, 230, 23, 23);//H
	n[7].x = 780; n[7].y = 230;
	xyprintf(780, 230, "H");

	fillellipse(420, 150, 23, 23);//I
	n[8].x = 420; n[8].y = 150;
	xyprintf(420, 150, "I");

	fillellipse(820, 100, 23, 23);//J
	n[9].x = 820; n[9].y = 100;
	xyprintf(820, 100, "J");


}

void DFS(graph& gra, node* n, int m)                               //深度优先遍历
{
	cout << n[m].data << endl;
	n[m].sign = 1;
	int temp = gra.getFirstNeighbor(m);
	setlinewidth(5);
	setcolor(BROWN);
	while (temp != -1) {
		if (n[temp].sign == 0) { 
			Sleep(500); line(n[m].x, n[m].y, n[temp].x, n[temp].y); 
			DFS(gra, n, temp);
			//cout << n[m].data << " " << n[temp].data;
		}
		temp = gra.getNextNeighbor(m, temp);

	}
}
int prim(graph& gra, node* n, int m, int* d)                        //Prim最小生成树
{
	for (int p = 0; p < gra.numver; p++)
	{
		d[p] = INT_MAX;
	}
	d[m] = 0;
	int sum = 0;
	for (int i = 0; i < gra.numver; i++)
	{
		int u = -1;
		int min = INT_MAX;
		for (int j = 0; j < gra.numver; j++)
		{
			if (n[j].sign == 0 && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1) { return -1; }
		n[u].sign = 1;
		setlinewidth(5);
		setcolor(RED);
		sum += d[u];
		for (int l = 0; l < gra.numver; l++)
		{
			for (int k = l + 1; k < gra.numver; k++)
			{
				if (gra.edge[l][k] == d[u]) {
					Sleep(500);
					line(n[l].x, n[l].y, n[k].x, n[k].y);
				}
			}
		}
		for (int v = 0; v < gra.numver; v++) //找相邻的最小边
		{
			if (n[v].sign == 0 && gra.edge[u][v] < d[v]) {
				d[v] = gra.edge[u][v];
			}
		}
	}
	cout << sum << endl;//输出总权值
	return sum;
}
void dijkstra(graph& gra, node* n, int* d, int ch, int path[])                   //Dijkstra最短路径
{
	int min;
	for (int i = 0; i < gra.numver; i++)
	{
		d[i] = gra.getWeight(ch, i);
		if (i != ch && d[i] < INT_MAX)path[i] = ch;
		else path[i] = -1;
	}
	n[ch].sign = 1; d[ch] = 0; 
	for (int i = 0; i < gra.numver - 1; i++)
	{
		min = INT_MAX;
		int u = ch;
		for (int j = 0; j < gra.numver; j++)
		{
			if (n[j].sign == 0 && d[j] < min) {
				u = j;
				min = d[j];
			}
			n[u].sign = 1;
			for (int k = 0; k < gra.numver; k++)
			{
				int w = gra.getWeight(u, k);
				if (n[k].sign == 0 && w < INT_MAX && d[u] + w < d[k])
				{
					d[k] = d[u] + w;           //最短路径权值的累加
					path[k] = u;
				}
			}
		}
	}
	setlinewidth(5);
	setcolor(RED);
}
void printpath(graph& gra, node* n, int v, int* dist, int path[], int end)       //输出最短路径所经过的结点
{
	int i, j, k, num = gra.numver;
	int* d = new int[num];
	for (i = 0; i < num; i++)
	{
		if (i != v && i == end) {
			j = i; k = 0;
			while (j != v) 
			{
				d[k++] = j; 
				j = path[j]; 
			}
			cout << n[v].data << " ";
			while (k > 0) {
				cout << n[d[--k]].data << " ";			
			}
			cout << "最短路径长度：" << dist[i] << endl;
		}
	}

}
int main()
{
	initgraph(1000, 1000, INIT_RENDERMANUAL);	//初始化窗口
	setfillcolor(BLUE);
	setbkcolor(WHITE);
	setfontbkcolor(WHITE);
	cout << "结点：0-A;1-B;2-C;3-D;4-E;5-F;6-G;7-H;8-I;9-J" << endl;
	int num = 0;
	graph gra(20);
	node* no = new node[10];
	for (int p = 0; p < gra.numver; p++)
	{
		no[p].data = gra.verlist[p];
	}
	show(gra, num, no);
	cout << "输入1：DFS                   输入2：Prim                      输入3：Dijkstra" << endl;
	int c;
	cin >> c;
	if (c == 1)
	{
		int start;
		cout << "输入起点：" << endl;
		cin >> start;
		DFS(gra, no, start);
	}
	if (c == 2)
	{
		int* vec = new int[10];//用于prim算法
		int start;
		cout << "输入起点：" << endl;
		cin >> start;
		prim(gra, no, start, vec);
	}
	if (c == 3)
	{
		int start, end;
		cout << "输入起点和终点：" << endl;
		cin >> start >> end;
		int* arr = new int[10];
		int path[10];
		dijkstra(gra, no, arr, start, path);
		printpath(gra, no, start, arr, path, end);
		int i = end;
		setcolor(GREEN);
		while (path[i] != start)
		{
			Sleep(1000);
			line(no[i].x, no[i].y, no[path[i]].x, no[path[i]].y);
			i = path[i];
		}
		Sleep(1000);
		line(no[i].x, no[i].y, no[path[i]].x, no[path[i]].y);

	}
	getch();
	closegraph();
}
