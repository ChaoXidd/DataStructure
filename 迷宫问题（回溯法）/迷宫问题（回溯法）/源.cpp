#include<iostream>
using namespace std;
#define maxM 10
#define maxN 10
#define direct 8

typedef struct {
	int a, b, dir;
}offsets;

string direction[direct] = { "N","NE","E","SE","S","SW","W","NW" };
offsets _move[direct] = { {-1,0,0},{-1,1,1},{0,1,2},{1,1,3},{1,0,4},{1,-1,5},{0,-1,6},{-1,-1,7} };

int SeekPath(int Maze[][maxN], int Mark[][maxN], int x, int y, int s, int t, int m, int p)//从x，y开始寻找向m，p的路，试探出发点为s，t
{
	
	int g, h, d;
	if (x == m && y == p) return 1;
	for (int i = 0; i < direct; i++)
	{
		g = x + _move[i].a;
		h = y + _move[i].b;
		d = _move[i].dir;
		if (!Maze[g][h] && !Mark[g][h])
		{
			Mark[g][h] = 1;
			if (SeekPath(Maze, Mark, g, h, s, t, m, p))
			{
				cout << "(" << g << "," << h << ")" << "     direction: " << direction[d] << endl;
				return 1;
			}
		}

	}
	if (x == s && y == t) cout << "No Path in Maze" << endl;
	return 0;
}



int main()
{
	int Maze[10][10] = {
		  1, 1, 1 ,1, 1, 1, 0, 1, 1, 1,
		  0, 0, 1, 1, 1, 1, 0, 1, 1, 1,
		  1, 0, 0, 1, 1, 1, 0, 1 ,0, 0, 
		  0, 1, 0, 0, 0, 1, 0, 1 ,0, 1, 
		  1, 0, 1, 1, 1, 0, 0, 1 ,0, 1, 
		  1, 0, 1 ,1, 1, 0, 1, 1, 0, 1,
		  1, 0, 1 ,1, 1, 0, 1, 1, 0, 1,
		  1, 0, 1 ,1, 1, 0, 1, 1, 0, 1,
		  1, 0, 1 ,1, 1, 0, 0, 0, 1, 1,
		  1, 0, 1 ,1, 1, 1, 1, 1, 1, 1,
	};
	int Mark[maxM][maxN];

	for (int i = 0; i < maxM - 1; i++)
		for (int j = 0; j < maxN - 1; j++)
			Mark[i][j] = 0;

	for (int i = 0; i < maxM; i++)
		Mark[i][0] = Mark[i][maxN  - 1] = 1;

	for (int j = 0; j < maxN - 1; j++)
		Mark[0][j] = Mark[maxM - 1][j] = 1;
	int s = 1; 
	int t = 1;
	int m = 2;
	int p = 8;
	SeekPath(Maze, Mark, s, t, s, t, m, p);
	return 0;
}







