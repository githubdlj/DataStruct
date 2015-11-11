/********************************************************************
	Time:	  2015/11/11
	Filename: Topologic_sort
	Author:	  dinglj
	
	Purpose:  topologic_sort,�޻�����ͼ
              ʱ�临�Ӷȣ��ڽӾ���O(n ^ 2)�� �ڽӱ�O(n + e)
*********************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
//////////////////////////////////////////////////////////////////////
//  �ڽӾ���ʵ��
#define INF     65536
#define MAXSIZE 20

//////////////////////////////////////////////////////////////////////
//  �ڽӾ���

typedef struct
{
    int no;
    char info;

    //  ����� �ڵ����,
    //  Ҳ���Բ��ı�VertexType,�½�һ�������洢�ṹ�洢�ڵ����
    //  �ڵ���ȵļ�������ڴ�������ͼ��ʱ�����,Ҳ���Դ�����ͼ֮���ڼ��㡣
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

	Purpose:   ���������ڽӾ���ʵ��

*********************************************************************/

//  �����洢�ṹ���洢ÿһ���������ȡ�Ҳ���Դ洢��VertexType�С�
//  int inDegree[MAXSIZE];

//  InitGraph,��ʼ��ͼ
void InitGraph(MGraph &G)
{
    for (int i = 0; i < MAXSIZE; ++i)
    {
        for (int j = 0; j < MAXSIZE; ++j)
        {
            G.e[i][j].weight = 0;
        }
        G.v[i].inDegree = 0;    //  ��ʼ�����
    }
}

//  CreateGraph,����ͼ��ʱ��ͳ�ƶ�������
void CreateGraph(MGraph &G)
{
    cin >> G.vertexNum;
    cin >> G.edgeNum;

    for (int edgeNo = 0; edgeNo < G.edgeNum; ++edgeNo)
    {
        int start, end;
        int weight = 1;     //  ����ͼ�ı�ȨֵΪ1
		cin >> start >> end;
		
        G.e[start][end].weight = weight;
        G.v[end].inDegree++;    //  �������
    }
}

//////////////////////////////////////////////////////////////////////
//  Topologic_sort
bool Topologic_sort(MGraph G)
{
    int vertexNum = 0;  //  �������vertexNum == G.vertexNum��˵���޻�����vertexNum < G.vertexNum,���л�

    int stack[MAXSIZE], top = -1;   //  �����洢�ṹ����ʱ�洢���Ϊ0�Ķ��㣻Ҳ���ö��У��������ȵ�

    //  �洢���Ϊ0�Ķ���
    for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
    {
        if (0 == G.v[vertexNo].inDegree)
        {
            top++;
            stack[top] = vertexNo;
        }
    }

    //  �洢�ṹ����
    while (-1 != top)
    {
        //  �ҳ�һ�����Ϊ0�Ķ���
        int vertex = stack[top];
        top--;
        cout << vertex;
        vertexNum++;    //  

        //  �����ڽӵ����ȼ�ȥ1
        //  �ڽӾ�����ڽӱ�ʵ�ֲ����Ҫ�����forѭ��
        for (int adjvex = 0; adjvex < G.vertexNum; ++adjvex)
        {
            if (1 == G.e[vertex][adjvex].weight)
            {
                G.v[adjvex].inDegree--;

                //  �洢���Ϊ0�Ķ���
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
    else    //  ���л�����vertexNum < G.vertexNum
    {
        return false;
    }
}

