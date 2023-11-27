#pragma once
#include<iostream>
using namespace std;

class Graph
{
	     
public:
	Graph(int vexNum_);
	Graph(){}

	char* vexs;
	int** arcs;
	int vexNum;
	int arcNum;


};




