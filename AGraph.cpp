/********************************************************************
	Time:	  2015/10/09
	Filename: AGraph
	Author:	  dinglj
	
	Purpose:  邻接表实现图
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#define MAXSIZE 20  //  顶点最大数目

//  边元素
typedef struct
{
    int weight;     //  变权值
}EdgeType;

//  边节点
typedef struct ENode
{
    EdgeType e;
    int adjvex;     //  邻接点

    struct ENode *next; //  指向下一条边
}ENode;

//  顶点元素
typedef struct  
{
    int no;     //  编号
    char info;  //  信息
}VertexType;

//  顶点节点结构
typedef struct
{
    VertexType v;
    struct ENode *firstEdge;    //  指向第一条边
}VNode;

//  邻接表
typedef struct  
{
    VNode vArr[MAXSIZE];    //  顶点数组

    int vertexNum, edgeNum;
}AGraph;
//////////////////////////////////////////////////////////////////////
// 基本函数的申明
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

	Purpose:   初始化邻接表

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

	Purpose:   建立邻接表

*********************************************************************/
bool CreateGraph(AGraph &G)
{
    cout << "请输入顶点数" << endl;
    cin >> G.vertexNum;

    cout << "请输入顶点信息" << endl;
    for (int vertexNo = 0; vertexNo < G.vertexNum; vertexNo++)
    {
        cin >> G.vArr[vertexNo].v.info;
    }

    cout << "请输入边的数目" << endl;
    cin >> G.edgeNum;

    for (int edgeNo = 0; edgeNo < G.edgeNum; edgeNo++)
    {
        cout << "请输入起点，终点和边权值" << endl;
        
        char start, end;
        int weight;
        cin >> start >> end >> weight;

        int startNo, endNo;
        startNo = getVertexNo(G, start);
        endNo = getVertexNo(G, end);

        //  新建一个边节点
        ENode *pNewENode = (ENode *)malloc(sizeof(ENode));
        pNewENode->e.weight = weight;
        pNewENode->adjvex = endNo;
        pNewENode->next = NULL;

        //  插入
        pNewENode->next = G.vArr[startNo].firstEdge;
        G.vArr[startNo].firstEdge = pNewENode;
    }
    
    return true;
}

/********************************************************************
	Method:    DestroyGraph
	Parameter: 
	Returns:   

	Purpose:   销毁邻接表

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

	Purpose:   输出每一条边的信息

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
    测试函数
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
    主函数
*/
int main()
{
    OperationTest();
    return true;
}