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

/********************************************************************
	Method:    getVertexType
	Parameter: 
	Returns:   

	Purpose:   根据顶点信息返回节点编号

*********************************************************************/
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
//  遍历
int isVisited[MAXSIZE];	//	用于标记节点是否被访问

//	访问单个节点
void visit(VNode v)
{
	printf("%c\t", v.v.info);
}

//	深度优先遍历
bool DFS(AGraph G, int v);
bool DFSTraverse(AGraph G);

// 广度优先搜素
bool BFS(AGraph G, int v);
bool BFSTraverse(AGraph G);

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

//////////////////////////////////////////////////////////////////////
/********************************************************************
	Method:    DFS,DFSTraverse
	Parameter: 
	Returns:   

	Purpose:   深度优先遍历

*********************************************************************/
bool DFS(AGraph G, int v)
{
	visit(G.vArr[v]);	//	访问
	isVisited[v] = 1;

	ENode *pENode = G.vArr[v].firstEdge;
	while (pENode)	//	类似于二叉树的先序遍历
	{
		if (!isVisited[pENode->adjvex])
		{
			DFS(G, pENode->adjvex);
		}
		pENode = pENode->next;
	}
	return true;
}

bool DFSTraverse(AGraph G)
{
	for (int vertexNo = 0; vertexNo < G.vertexNum; vertexNo++)
	{
		isVisited[vertexNo] = 0;
	}

//	int num = 0;
	//	对每一个节点进行DFS，如果是连通图，则for循环实际上只会执行一次
	for (int vertexNo = 0; vertexNo < G.vertexNum; vertexNo++)
	{
		if (!isVisited[vertexNo])
		{
			DFS(G, vertexNo);
		//	num++;	//	num为连通分量数目
		}	
	}
	printf("\n");

	return true;
}

/********************************************************************
	Method:    BFS
	Parameter: 
	Returns:   

	Purpose:   广度优先搜素

*********************************************************************/
bool BFS(AGraph G, int v)
{
    ENode *pENode;

    //  辅助队列
    int queue[MAXSIZE];
    int front = 0, rear = 0;

    queue[rear++] = v;    //  顶点入队列
   
    visit(G.vArr[v]);   //  访问，标记
    isVisited[v] = 1;
    
    while (front != rear)   //  队列不空
    {
        v = queue[front++]; //  出队列
        
        pENode = G.vArr[v].firstEdge;   //  pENode指向第一条边
        while (pENode)
        {
            if (!isVisited[pENode->adjvex])
            {
                queue[rear++] = pENode->adjvex; //  入队，访问，标记
                visit(G.vArr[pENode->adjvex]);  
                isVisited[pENode->adjvex] = 1;
            }
            pENode = pENode->next;
        }
    }
    return true;
}

bool BFSTraverse(AGraph G)
{
    for (int vertexNo = 0; vertexNo < G.vertexNum; vertexNo++)
    {
        isVisited[vertexNo] = 0;
    }
    
    for (int vertexNo = 0; vertexNo < G.vertexNum; vertexNo++)
    {
        if (!isVisited[vertexNo])
        {
            BFS(G, vertexNo);
        }
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

	DFSTraverse(G);
    BFSTraverse(G);

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