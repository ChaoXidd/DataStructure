#include"Graphlnk.h"
#include<vector>

vector<int> vc;



template<class T, class E>
Graphlnk<T, E>::Graphlnk()
{
	numVertices = 0;
	numEdges = 0;
	for (int i = 0; i < maxVertices; i++)
		NodeTable[i].adj = NULL;
}

template<class T, class E>
Graphlnk<T, E>::Graphlnk(int sz)
{

}

template<class T, class E>
Graphlnk<T, E>::~Graphlnk()
{

}



template<class T, class E>
int Graphlnk<T, E>::getFirstNeighbor(int v)
{
	if (v != -1)
	{
		Edge<T, E>* p = NodeTable[v].adj;
		if (p != NULL) return p->dest;
	}

	return -1;
}

template<class T, class E>
int Graphlnk<T, E>::getNextNeighbor(int v, int w)
{
	if (v != -1)
	{
		Edge<T, E>* p = NodeTable[v].adj;
		while (p != NULL && p->dest != w)
			p = p->link;
		if (p != NULL && p->link != NULL)
			return p->link->dest;
	}
	return -1;

}


template<class T, class E>
int Graphlnk<T, E>::getVertexPos(T vertex)
{

	for (int i = 0; i < numVertices; i++)
	{
		if (NodeTable[i].data == vertex) return i;
	}
	return -1;
}









template<class T, class E>
E Graphlnk<T, E>::getWeight(int v1, int v2)
{
	if (v1 != -1 && v2 != -1)
	{
		Edge<T, E>* p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
			p = p->link;
		if (p != NULL) return p->cost;
	}
	return 0;
}



template<class T, class E>
bool Graphlnk<T, E>::insertVertex(T vertex)
{
	if (numVertices == maxVertices) return false;
	NodeTable[numVertices].data = vertex;
	NodeTable[numVertices].adj = NULL;
	numVertices++;
	return true;
}


template<class T, class E>
bool Graphlnk<T, E>::removeVertex(int v, T& vertex)
{
	if (numVertices == 1 || v < 0 || v >= numVertices) return false;

	Edge<T, E>* p, * s, * t;
	int i, k;
	while (NodeTable[v].adj != NULL)
	{
		p = NodeTable[v].adj;
		k = p->dest;
		s = NodeTable[k].adj;
		t = NULL;
		while (s != NULL && s->dest != v)
		{
			t = s;
			s = s->link;
		}
		if (s != NULL)
		{
			if (t == NULL) NodeTable[k].adj = s->link;
			else t->link = s->link;
			delete s;
		}
		NodeTable[v].adj = p->link;
		delete p;
		numEdges--;


	}
	vertex = NodeTable[v].data;
	numVertices--;


	NodeTable[v].data = NodeTable[numVertices].data;    //填补
	p = NodeTable[v].adj = NodeTable[numVertices].adj; 
	while (p != NULL)
	{
		s = NodeTable[p->dest].adj;
		while (s != NULL)
		{
			if (s->dest == numVertices)
			{
				s->dest = v;
				break;
			}
			else
			{
				s = s->link;
			}

		}
		p = p->link;
	}

	return true;

}



template<class T, class E>
bool Graphlnk<T, E>::insertEdge(int v1, int v2, E weight)
{
	if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices)
	{
		Edge<T, E>* q, * p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
			p = p->link;
		if (p != NULL) return false;    //找到此边，不输入

		p = new Edge<T, E>; q = new Edge<T, E>;

		p->dest = v2; p->cost = weight;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;

		q->dest = v1; q->cost = weight;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;

		numEdges++;
		return true;

	}

	else return false;

}


template<class T, class E>
bool Graphlnk<T, E>::removeEdge(int v1, int v2, E& cost)
{
	if (v1 != -1 && v2 != -1)
	{
		Edge<T, E>* p = NodeTable[v1].adj;
		Edge<T, E>* q = NULL;
		Edge<T, E>* s = p;
		while (p != NULL && p->dest != v2)
		{
			q = p;
			p = p->link;
		}
		if (p != NULL)
		{
			if (p == s) NodeTable[v1].adj = p->link;
			else q->link = p->link;
			cost = p->cost;
			delete p;
		}
		else return false;



		p = NodeTable[v2].adj;
		q = NULL;
		s = p;
		while (p->dest != v1)
		{
			q = p;
			p = p->link;
		}
		if (p == s) NodeTable[v2].adj = p->link;
		else q->link = p->link;
		delete p;
		return true;
	}

	return false;

}

template<class T, class E>
void Graphlnk<T, E>::DFS_recur(int v, bool visited[])
{
	//cout << NodeTable[v].data<<" ";
	visited[v] = true;
	int w = getFirstNeighbor(v);
	while (w != -1)
	{
		
		if (visited[w] == false)
		{ 
			cout << NodeTable[v].data << "-> " << NodeTable[w].data;
			DFS_recur(w, visited);
			
		}			
		w = getNextNeighbor(v, w);
	}



}


template<class T, class E>
void Graphlnk<T, E>::DFS_recur(T v)
{
	int i, loc, n = numVertices;
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	loc = getVertexPos(v);
	DFS_recur(loc, visited);
	delete[]visited;
}



















int main()
{
	Graphlnk<char, int> g = Graphlnk<char, int>();
	g.insertVertex('A');
	g.insertVertex('B');
	g.insertVertex('C');
	g.insertVertex('D');
	g.insertEdge(g.getVertexPos('A'), g.getVertexPos('D'), 10);
	g.insertEdge(g.getVertexPos('A'), g.getVertexPos('B'), 10);
	g.insertEdge(g.getVertexPos('B'), g.getVertexPos('D'), 10);
	g.insertEdge(g.getVertexPos('B'), g.getVertexPos('C'), 10);
	g.DFS_recur('A');
	return 0;
}