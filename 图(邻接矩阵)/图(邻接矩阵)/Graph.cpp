#include"Graph.h"



 Graph:: Graph(int vexNum_)
{
	
	vexs = new char[vexNum_];
	arcs = new int* [vexNum_];
	for (int i = 0; i < vexNum_; i++)
	{
		arcs[i] = new int[vexNum_];
	}
	vexNum = vexNum_;
	arcNum = 0;

}










 void createGraph(Graph* g, char* vexs, int** arcs)
 {
	 for (int i = 0; i < g->vexNum; i++)
	 {
		 g->vexs[i] = vexs[i];
		 for (int j = 0; j < g->vexNum; j++)
		 {
			 g->arcs[i][j] = arcs[i][j];
			 if (g->arcs[i][j] != 0) g->arcNum++;
		 }
	 }
	 g->arcNum /= 2;
 }






int main()
{
	Graph* g = new Graph(5);
	int arcs[4][4] = {
		0,1,1,0,
		1,0,1,1,
		1,1,0,0,
		1,0,0,0

	};
	char ca[4] = {'A', 'B' ,'C', 'D'};
	createGraph(g, ca, (int**)arcs);
	return 0;
}