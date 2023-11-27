#include"Graph.h"

void Graph::InitGraph()
{
	MaxVertices = Default_Vertices_Size;
	numVertices = numEdges = 0;
	VerticesList = new char[MaxVertices];
	Edge = new int* [MaxVertices];
	for (int i = 0; i < MaxVertices; i++)
	{
		Edge[i] = new int[MaxVertices];
	}
	for (int j = 0; j < MaxVertices; j++)
	{
		for (int k = 0; k < MaxVertices; k++)
		{
			if (k == j)
			{
				Edge[j][k] = 0;
			}
			else Edge[j][k] = MAX_COST;
		}
	}
}


void  Graph::showGraph()
{
	cout << "  ";
	for (int i = 0; i < numVertices; i++)
	{
		cout << VerticesList[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < numVertices; i++)
	{
		cout << VerticesList[i] << " ";
		for (int j = 0; j < numVertices; j++)
		{
			if (Edge[i][j] == MAX_COST)
			{
				cout << "@" << " ";
			}
			else
			{
				cout << Edge[i][j] << " ";
			}
		}
		cout << endl;
	}


}


void Graph::InsertVertex(char v)
{
	if (numVertices >= MaxVertices) return;
	VerticesList[numVertices++] = v;

}


int Graph::GetVertexPos(char v)
{
	for (int i = 0; i < numVertices; i++)
	{
		if (VerticesList[i] == v)
			return i;
	}
	return -1;
}



void Graph::InsertEdge(char v1, char v2, int cost)
{
	int p1 = GetVertexPos(v1);
	int p2 = GetVertexPos(v2);
	if (p1 == -1 || p2 == -1) return;

	Edge[p1][p2] = cost;
	numEdges++;

}


void Graph::RemoveVertex(char v)
{
	int p = GetVertexPos(v);
	if (p == -1) return;

	int numedges = 0;

	for (int i = p; i < numVertices - 1; i++)
	{
		VerticesList[i] = VerticesList[i + 1];
	}

	for (int i = 0; i < numVertices; i++)
	{
		if (Edge[p][i] != 0)
		{
			numedges++;
		}
	}



	for (int j = p; j < numVertices - 1; j++)
	{
		for (int k = 0; k < numVertices - 1; k++)
		{
			Edge[j][k] = Edge[j + 1][k];
		}
	}

	for (int j = p; j < numVertices - 1; j++)
	{
		for (int k = 0; k < numVertices - 1; k++)
		{
			Edge[k][j] = Edge[k][j + 1];
		}
	}
	numVertices--;
	numEdges -= numedges;
}


void Graph::RemoveEdge(char v1, char v2)
{
	int p1 = GetVertexPos(v1);
	int p2 = GetVertexPos(v2);
	if (p1 == -1 || p2 == -1) return;
	if (Edge[p1][p2] == 0) return;
	Edge[p1][p2] = Edge[p2][p1] = 0;
	numEdges--;
}



int Graph::GetFirstNeighbor(char v)
{
	int p = GetVertexPos(v);
	if (p == -1) return -1;

	for (int i = 0; i < numVertices; i++)
	{
		if (Edge[p][i] == 1)
			return i;
	}


	return -1;
}


int Graph::GetNextNeighbor(char v, char w)
{
	int pv = GetVertexPos(v);
	int pw = GetVertexPos(w);
	if (pv == -1 || pw == -1)
		return -1;
	for (int i = pw + 1; i < numVertices; i++)
	{
		if (Edge[pv][pw] == 1)
			return i;
	}
	return -1;
}


int  Graph::GetWeight(int v1, int v2)
{
	if (v1 == -1 || v2 == -1)
		return MAX_COST;
	return Edge[v1][v2];
}


























int main()
{
	Graph g;
	g.InitGraph();
	g.InsertVertex('A');
	g.InsertVertex('B');
	g.InsertVertex('C');
	g.InsertVertex('D');
	g.InsertVertex('E');
	g.InsertVertex('F');


	g.InsertEdge('A', 'B', 6);
	g.InsertEdge('A', 'C', 1);
	g.InsertEdge('A', 'D', 5);
	g.InsertEdge('B', 'E', 3);
	g.InsertEdge('B', 'C', 5);
	g.InsertEdge('D', 'C', 5);
	g.InsertEdge('E', 'C', 6);
	g.InsertEdge('E', 'F', 6);
	g.InsertEdge('D', 'F', 2);
	g.InsertEdge('F', 'C', 4);
	g.showGraph();

	int n = g.numVertices;
	int* dist = new int[n];
	int* path = new int[n];



	return 0;
}