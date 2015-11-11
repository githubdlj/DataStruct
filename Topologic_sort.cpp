/********************************************************************
	Time:	  2015/11/11
	Filename: Topologic_sort
	Author:	  dinglj
	
	Purpose:  topologic_sort,无环有向图
              时间复杂度：邻接矩阵O(n ^ 2)， 邻接表O(n + e)
*********************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
//////////////////////////////////////////////////////////////////////
//  邻接矩阵实现
#define INF     65536
#define MAXSIZE 20

//////////////////////////////////////////////////////////////////////
//  邻接矩阵

typedef struct
{
    int no;
    char info;

    //  新添加 节点入度,
    //  也可以不改变VertexType,新建一个辅助存储结构存储节点入度
    //  节点入度的计算可以在创建有向图的时候计算,也可以创建好图之后在计算。
    int inDegree;  
}VertexType;

typedef struct
{
    int weight;
}EdgeType;

typedef struct  
{
    VertexType v[MAXSIZE];
    EdgeType e[MAXSIZE][MAXSIZE];

    int vertexNum;
    int edgeNum;
}MGraph;
//////////////////////////////////////////////////////////////////////
/********************************************************************
	Method:    Topologic_sort
	Parameter: 
	Returns:   

	Purpose:   拓扑排序，邻接矩阵实现

*********************************************************************/

//  辅助存储结构，存储每一个顶点的入度。也可以存储在VertexType中。
//  int inDegree[MAXSIZE];

//  InitGraph,初始化图
void InitGraph(MGraph &G)
{
    for (int i = 0; i < MAXSIZE; ++i)
    {
        for (int j = 0; j < MAXSIZE; ++j)
        {
            G.e[i][j].weight = 0;
        }
        G.v[i].inDegree = 0;    //  初始化入度
    }
}

//  CreateGraph,建立图的时候统计顶点的入度
void CreateGraph(MGraph &G)
{
    cin >> G.vertexNum;
    cin >> G.edgeNum;

    for (int edgeNo = 0; edgeNo < G.edgeNum; ++edgeNo)
    {
        int start, end;
        int weight = 1;     //  有向图的边权值为1
		cin >> start >> end;
		
        G.e[start][end].weight = weight;
        G.v[end].inDegree++;    //  计算入度
    }
}

//////////////////////////////////////////////////////////////////////
//  Topologic_sort
bool Topologic_sort(MGraph G)
{
    int vertexNum = 0;  //  如果最终vertexNum == G.vertexNum，说明无环；若vertexNum < G.vertexNum,则有环

    int stack[MAXSIZE], top = -1;   //  辅助存储结构，暂时存储入度为0的顶点；也可用队列，随机数组等等

    //  存储入度为0的顶点
    for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
    {
        if (0 == G.v[vertexNo].inDegree)
        {
            top++;
            stack[top] = vertexNo;
        }
    }

    //  存储结构不空
    while (-1 != top)
    {
        //  找出一个入度为0的顶点
        int vertex = stack[top];
        top--;
        cout << vertex;
        vertexNum++;    //  

        //  将其邻接点的入度减去1
        //  邻接矩阵和邻接表实现差别主要在这个for循环
        for (int adjvex = 0; adjvex < G.vertexNum; ++adjvex)
        {
            if (1 == G.e[vertex][adjvex].weight)
            {
                G.v[adjvex].inDegree--;

                //  存储入度为0的顶点
                if (0 == G.v[adjvex].inDegree)
                {
                    top++;
                    stack[top] = adjvex;
                }
            }
        }
    }

    if (vertexNum == G.vertexNum)
    {
	    return true;
    }
    else    //  若有环，则vertexNum < G.vertexNum
    {
        return false;
    }
}

