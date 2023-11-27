#pragma once
#include<iostream>
using namespace std;


#define maxVertices 30
#define maxEdges 40
#define maxWeight 999

template<class T, class E>
struct Edge {
	int dest;  //另一顶点位置
	E cost;
	Edge<T, E>* link;
	Edge(){}
	Edge(int num, E weight) :dest(num), cost(weight), link(NULL)
	{

	}

	bool operator != (Edge<T, E>& R) const {
		return (dest != R.dest) ? true : false;
	}


};

template<class T, class E>
struct Vertex {
	T data;
	Edge<T, E>* adj; //边链表头指针

};



template<class T, class E>
class Graphlnk {
public:
	Graphlnk();
	Graphlnk(int sz);
	~Graphlnk();

	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	int getVertexPos(T vertex);
	E getWeight(int v1, int v2);
	bool insertVertex(T vertex);
	bool removeVertex(int v, T& vertex);
	bool insertEdge(int v1, int v2, E weight);
	bool removeEdge(int v1, int v2, E & cost);
	void DFS_recur(int v, bool visited[]);
	void DFS_recur(T v);




private:
	int numEdges;
	int numVertices;
	Vertex<T, E> NodeTable[maxVertices];

};



