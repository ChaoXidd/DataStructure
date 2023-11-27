#pragma once
#include<iostream>
#define SHOW_CONSOLE
#include <graphics.h>
#include<ege/sys_edit.h>

const int maxweight = 65535;

using namespace std;




class graph
{
public:
    graph(int sz);
    ~graph() { delete[]edge; }
    
    int getFirstNeighbor(int v);              //第一个相邻点
    int getNextNeighbor(int v, int w);    //下一个相邻点
    int getWeight(int v1, int v2)
    {
        if (v1 != -1 && v2 != -1) return edge[v1][v2]; else return 0;
    }
    int numedg;               
    int numver;             
    int maxver;              //最大结点数
    string verlist;         //存放点
    int** edge;            //边的邻接矩阵

};
class node
{
public:
    friend graph;
    node() {};
    ~node() {};
    int x;          
    int y;          
    string data;
    int sign = 0;                //标记位
};
graph::graph(int sz)
{
    maxver = sz; numedg = 0; numver = 0;
    int i, j;
    edge = (int**)new int* [maxver];
    for (i = 0; i < maxver; i++)
        edge[i] = new int[maxver];
    for (i = 0; i < maxver; i++)
        for (j = 0; j < maxver; j++)
            edge[i][j] = (i == j) ? 0 : maxweight;
    numver = 10;
    numedg = 17;
    verlist = "ABCDEFGHIJ";
    //edge[0][1] = edge[1][0] = 750;
    //edge[0][2] = edge[2][0] = 680;
    //edge[1][2] = edge[2][1] = 800;
    //edge[1][4] = edge[4][1] = 970;
    //edge[1][3] = edge[3][1] = 650;
    //edge[3][2] = edge[2][3] = 820;
    //edge[3][4] = edge[4][3] = 570;
    //edge[3][6] = edge[6][3] = 530;
    //edge[3][5] = edge[5][3] = 975;
    //edge[4][8] = edge[8][4] = 840;
    //edge[2][5] = edge[5][2] = 960;
    //edge[6][5] = edge[5][6] = 680;
    //edge[9][5] = edge[5][9] = 990;
    //edge[6][7] = edge[7][6] = 900;
    //edge[6][9] = edge[9][6] = 980;
    //edge[7][8] = edge[8][7] = 840;
    //edge[7][9] = edge[9][7] = 985;


    edge[0][1] = edge[1][0] = 2500;
    edge[0][2] = edge[2][0] = 1380;
    edge[0][3] = edge[3][0] = 2600;
    edge[1][4] = edge[4][1] = 340;
    edge[1][2] = edge[2][1] = 900;
    edge[2][6] = edge[6][2] = 530;
    edge[2][3] = edge[3][2] = 680;
    edge[3][6] = edge[6][3] = 1200;
    edge[3][7] = edge[7][3] = 960;
    edge[4][5] = edge[5][4] = 840;
    edge[5][6] = edge[6][5] = 570;
    edge[5][8] = edge[8][5] = 1140;
    edge[6][8] = edge[8][6] = 650;
    edge[6][7] = edge[7][6] = 820;
    edge[7][8] = edge[8][7] = 800;
    edge[7][9] = edge[9][7] = 680;
    edge[8][9] = edge[9][8] = 750;








}
int graph::getFirstNeighbor(int v)
{
    if (v != -1)
    {
        for (int num = 0; num < numver; num++)
            if (edge[v][num] > 0 && edge[v][num] < maxweight)return num;
        return -1;
    }
}
int graph::getNextNeighbor(int v, int w)
{
    if (v != -1 && w != -1)
    {
        for (int num = w + 1; num < numver; num++)
            if (edge[v][num] > 0 && edge[v][num] < maxweight)return num;
    }
    return -1;
}