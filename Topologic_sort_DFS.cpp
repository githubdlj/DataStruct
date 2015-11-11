/********************************************************************
	Time:	  2015/11/11
	Filename: Topologic_sort_DFS
	Author:	  dinglj
	
	Purpose:  拓扑排序，有向图
              DFS实现,邻接表
              时间复杂度 O(n + e),也就是邻接表DFS的时间复杂度
              
              拓扑排序可以用DFS实现
              反过来，图的遍历也可以用拓扑排序来实现
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAXSIZE 20
//////////////////////////////////////////////////////////////////////
//   边结构
typedef struct
{
    int weight;
}EdgeType;
typedef struct Node
{
    EdgeType e;
    
    int adjvex;
    struct Node *next;
}ENode;

//  顶点结构
typedef struct
{
    int no;
    char info;
}VertexType;

typedef struct
{
    VertexType v; 
    ENode *firstNode;
}VNode;

//  邻接表
typedef struct
{
    VNode adjList[MAXSIZE];

    int vertexNum;
    int edgeNum;
}AGraph;

/********************************************************************
	Method:    DFS
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
//  辅助存储结构, 标记顶点是否已被访问
bool isVisited[MAXSIZE];

//  辅助存储结构，保存退栈顶点
int stack[MAXSIZE], top = -1;

//////////////////////////////////////////////////////////////////////
void DFS(AGraph G, int v)
{
//    cout << v;
    isVisited[v] = true;

    ENode *pENode = G.adjList[v].firstNode;
    while (NULL != pENode)
    {
        if (false == isVisited[pENode->adjvex])
        {
            DFS(G, pENode->adjvex);
        }
        pENode = pENode->next;
    }

    //  退出DFS时候, 将退站顶点入栈
    top++;
    stack[top] = v;
}

/********************************************************************
	Method:    Topologic_sort
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool Topologic_sort(AGraph G)
{
    for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
    {
        isVisited[vertexNo] =  false;
    }

    for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
    {
        if (false == isVisited[vertexNo])
        {
            DFS(G, vertexNo);
        }
    }

    //  输出序列
    if (top == G.vertexNum - 1)
    {
        while (-1 != top)
        {
            cout << stack[top] << "\t";
            top--;
        }
        return true;
    }
    else    //  有环
    {
        return false;
    }
}

