/********************************************************************
	Time:	  2015/10/09
	Filename: AGraph
	Author:	  dinglj
	
	Purpose:  �ڽӱ�ʵ��ͼ
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#define MAXSIZE 20  //  ���������Ŀ

//  ��Ԫ��
typedef struct
{
    int weight;     //  ��Ȩֵ
}EdgeType;

//  �߽ڵ�
typedef struct ENode
{
    EdgeType e;
    int adjvex;     //  �ڽӵ�

    struct ENode *next; //  ָ����һ����
}ENode;

//  ����Ԫ��
typedef struct  
{
    int no;     //  ���
    char info;  //  ��Ϣ
}VertexType;

//  ����ڵ�ṹ
typedef struct
{
    VertexType v;
    struct ENode *firstEdge;    //  ָ���һ����
}VNode;

//  �ڽӱ�
typedef struct  
{
    VNode vArr[MAXSIZE];    //  ��������

    int vertexNum, edgeNum;
}AGraph;
//////////////////////////////////////////////////////////////////////
// ��������������
bool InitGraph(AGraph &G);

bool CreateGraph(AGraph &G);
bool DestroyGraph(AGraph &G);

bool PrintGraph(AGraph G);

int getVertexNo(AGraph G, char info)
{
    for (int vertexNo = 0; vertexNo < G.vertexNum; vertexNo++)
    {
        if (info == G.vArr[vertexNo].v.info)
        {
            return vertexNo;
        }
    }

    return -1;
}

//////////////////////////////////////////////////////////////////////
/********************************************************************
	Method:    InitGraph
	Parameter: 
	Returns:   

	Purpose:   ��ʼ���ڽӱ�

*********************************************************************/
bool InitGraph(AGraph &G)
{
    for (int vertexNo = 0; vertexNo < MAXSIZE; vertexNo++)
    {
        G.vArr[vertexNo].firstEdge = NULL;
    }

    G.vertexNum = 0;
    G.edgeNum = 0;

    return true;
}

/********************************************************************
	Method:    CreateGraph
	Parameter: 
	Returns:   

	Purpose:   �����ڽӱ�

*********************************************************************/
bool CreateGraph(AGraph &G)
{
    cout << "�����붥����" << endl;
    cin >> G.vertexNum;

    cout << "�����붥����Ϣ" << endl;
    for (int vertexNo = 0; vertexNo < G.vertexNum; vertexNo++)
    {
        cin >> G.vArr[vertexNo].v.info;
    }

    cout << "������ߵ���Ŀ" << endl;
    cin >> G.edgeNum;

    for (int edgeNo = 0; edgeNo < G.edgeNum; edgeNo++)
    {
        cout << "��������㣬�յ�ͱ�Ȩֵ" << endl;
        
        char start, end;
        int weight;
        cin >> start >> end >> weight;

        int startNo, endNo;
        startNo = getVertexNo(G, start);
        endNo = getVertexNo(G, end);

        //  �½�һ���߽ڵ�
        ENode *pNewENode = (ENode *)malloc(sizeof(ENode));
        pNewENode->e.weight = weight;
        pNewENode->adjvex = endNo;
        pNewENode->next = NULL;

        //  ����
        pNewENode->next = G.vArr[startNo].firstEdge;
        G.vArr[startNo].firstEdge = pNewENode;
    }
    
    return true;
}

/********************************************************************
	Method:    DestroyGraph
	Parameter: 
	Returns:   

	Purpose:   �����ڽӱ�

*********************************************************************/
bool DestroyGraph(AGraph &G)
{
    for (int vertexNo = 0; vertexNo < G.vertexNum; vertexNo++)
    {
        ENode *pDeleteENode = G.vArr[vertexNo].firstEdge;
        while (pDeleteENode)
        {
            G.vArr[vertexNo].firstEdge = pDeleteENode->next;
            free(pDeleteENode);
            pDeleteENode = G.vArr[vertexNo].firstEdge;
        }
    }

    G.vertexNum = 0;
    G.edgeNum = 0;

    return true;
}

/********************************************************************
	Method:    PrintGraph
	Parameter: 
	Returns:   

	Purpose:   ���ÿһ���ߵ���Ϣ

*********************************************************************/
bool PrintGraph(AGraph G)
{
    for (int vertexNo = 0; vertexNo < G.vertexNum; vertexNo++)
    {
        ENode *pPrintENode = G.vArr[vertexNo].firstEdge;
        while (pPrintENode)
        {
            printf("%d,%d\t", pPrintENode->adjvex, pPrintENode->e.weight);
        	pPrintENode = pPrintENode->next;
        }
        printf("\n");
    }
    return true;
}

/*
    ���Ժ���
*/
bool OperationTest()
{
    AGraph G;

    InitGraph(G);

    CreateGraph(G);

    PrintGraph(G);

    DestroyGraph(G);

    return true;
}

/*
    ������
*/
int main()
{
    OperationTest();
    return true;
}