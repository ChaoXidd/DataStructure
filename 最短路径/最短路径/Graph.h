#pragma once
#pragma once
#include<iostream>
using namespace std;

#define Default_Vertices_Size 10
#define MAX_COST 0xFFFFFFF

class Graph
{
public:
	Graph() {}
	~Graph() {}
	void InitGraph();
	void showGraph();
	int GetVertexPos(char v);
	void InsertVertex(char v);
	void InsertEdge(char v1, char v2, int cost);
	void RemoveVertex(char v);
	void RemoveEdge(char v1, char v2);

	int GetFirstNeighbor(char v);
	int GetNextNeighbor(char v, char w);
	int GetWeight(int v1, int v2);

	//void MinSpanTree_Prim(char vertex);

	void ShortestPath();

	int numVertices;
	int numEdges;
	int MaxVertices;

	char* VerticesList;
	int** Edge;
};
