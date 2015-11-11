/********************************************************************
	Time:	  2015/11/11
	Filename: Topologic_sort_DFS
	Author:	  dinglj
	
	Purpose:  ������������ͼ
              DFSʵ��,�ڽӱ�
              ʱ�临�Ӷ� O(n + e),Ҳ�����ڽӱ�DFS��ʱ�临�Ӷ�
              
              �������������DFSʵ��
              ��������ͼ�ı���Ҳ����������������ʵ��
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAXSIZE 20
//////////////////////////////////////////////////////////////////////
//   �߽ṹ
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

//  ����ṹ
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

//  �ڽӱ�
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
//  �����洢�ṹ, ��Ƕ����Ƿ��ѱ�����
bool isVisited[MAXSIZE];

//  �����洢�ṹ��������ջ����
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

    //  �˳�DFSʱ��, ����վ������ջ
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

    //  �������
    if (top == G.vertexNum - 1)
    {
        while (-1 != top)
        {
            cout << stack[top] << "\t";
            top--;
        }
        return true;
    }
    else    //  �л�
    {
        return false;
    }
}

