/********************************************************************
	Time:	  2015/09/22
	Filename: MGraph
	Author:	  dinglj
	
	Purpose:  图的顺序存储实现
*********************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXSIZE 20	//	最大顶点数目
#define INF 65535	//	不可达标志

//	顶点结构
typedef struct
{
	int no;		//	顶点编号
	char info;	//	顶点信息
}VertexType;

//	边结构
typedef struct  
{
	int weight;	//	边权值，0表示相同点，INF表示不可达
}EdgeType;

//	图结构
typedef struct
{
	VertexType v[MAXSIZE];	//	顶点
	EdgeType e[MAXSIZE][MAXSIZE];	//	边

	//	顶点数、边数
	int vertexNum;
	int edgeNum;

}MGraph;


//	基本函数申明
//////////////////////////////////////////////////////////////////////
bool Initgraph(MGraph &G);

bool CreateGraph(MGraph &G);
bool DestroyGraph(MGraph &G);

bool PrintGraph(MGraph G);

int getVertexNo(MGraph G, char info);		//	根据顶点信息得到其编号

//////////////////////////////////////////////////////////////////////
//	遍历相关
bool isVisited[MAXSIZE];    //  标记数组

void visit(VertexType v)
{
    printf("%c\t", v.info);
}

//  深度优先搜索
bool DFS(MGraph G, int v);
bool DFSTraverse(MGraph G);

// 广度优先搜素
bool BFS(MGraph G, int v);
bool BFSTraverse(MGraph G);
 //////////////////////////////////////////////////////////////////////
/********************************************************************
	Method:    InitGraph
	Parameter: 
	Returns:   

	Purpose:   初始化图

*********************************************************************/
bool InitGraph(MGraph &G)
{
	G.vertexNum = 0;
	G.edgeNum = 0;

	for (int i = 0; i < MAXSIZE; i++)
	{
		for (int j = 0; j < MAXSIZE; j++)
		{	
            G.e[i][j].weight = INF;
            G.e[j][i].weight = INF;
		}
        G.e[i][i].weight = 0;
	}
	return true;
}
/********************************************************************
	Method:    getVertexNo
	Parameter: 
	Returns:   

	Purpose:   根据节点信息得到节点编号

*********************************************************************/
int getVertexNo(MGraph G, char info)
{
	for (int i = 0; i < G.vertexNum; i++)
	{
		if (info == G.v[i].info)
		{
			return i;
		}
	}

	return -1;	//	没有找到
}

/********************************************************************
	Method:    CreateGraph
	Parameter: 
	Returns:   

	Purpose:   创建有向网

*********************************************************************/
bool CreateGraph(MGraph &G)
{
	cout << "输入定点数目" << endl;
	cin >> G.vertexNum;

	cout << "请输入顶点信息" << endl;
	for (int i = 0; i < G.vertexNum; i++)
	{
		cin >> G.v[i].info;
	}

	cout << "请输入边的数目" << endl;
	cin >> G.edgeNum;

	for (int i = 0; i < G.edgeNum; i++)
	{
		cout << "请输入起点，终点和边权值" << endl;
		
		char start, end;
		int weight;
		cin >> start >> end >> weight;

		//	获取顶点序号
		int startNo = -1;
		int endNo = -1;

		startNo = getVertexNo(G, start);
		endNo = getVertexNo(G, end);

		G.e[startNo][endNo].weight = weight;
	}

	return true;
}

/********************************************************************
	Method:    PrintGraph
	Parameter: 
	Returns:   

	Purpose:   输出图信息

*********************************************************************/
bool PrintGraph(MGraph G)
{
	for (int i = 0; i < G.vertexNum; i++)
	{
		for (int j = 0; j < G.vertexNum; j++)
		{
			printf("%d\t", G.e[i][j].weight);
		}
		printf("\n");
	}
	return true;
}

//////////////////////////////////////////////////////////////////////
/********************************************************************
	Method:    DFS
	Parameter: 
	Returns:   

	Purpose:   深度优先遍历

*********************************************************************/
bool DFS(MGraph G, int v)
{
    visit(G.v[v]);
    isVisited[v] = 1;

    for (int adjvex = 0; adjvex < G.vertexNum; adjvex++)
    {
        //  寻找到邻接点，并且邻接点没有被访问，则访问
        if ( 0 != G.e[v][adjvex].weight && INF != G.e[v][adjvex].weight && !isVisited[adjvex])
        {
            DFS(G, adjvex);
        }
    }
    
    return true;
}

bool DFSTraverse(MGraph G)
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

	Purpose:   广度优先搜素，注意，入队的时候进行访问，并标记

*********************************************************************/
bool BFS(MGraph G, int v)
{
    //  辅助队列
    int queue[MAXSIZE];
    int front = 0, rear = 0;

    queue[rear++] = v;    //  顶点入队列
   
    visit(G.v[v]);   //  访问，标记
    isVisited[v] = 1;
    
    while (front != rear)   //  队列不空
    {
        v = queue[front++]; //  出队列
        
        for (int adjvex = 0; adjvex < G.vertexNum; adjvex++)
        {
            //  寻找没有被访问过的邻接点
            if (INF != G.e[v][adjvex].weight && 0 != G.e[v][adjvex].weight && !isVisited[adjvex])
            {
                queue[rear++] = adjvex; //  入队，访问，标记
                visit(G.v[adjvex]);  
                isVisited[adjvex] = 1;
            }
        }
    }
    return true;
}

bool BFSTraverse(MGraph G)
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
/********************************************************************
	Method:    OperationTest
	Parameter: 
	Returns:   

	Purpose:   测试函数

*********************************************************************/
bool OperationTest()
{
	MGraph G;
	
	InitGraph(G);
	CreateGraph(G);
	PrintGraph(G);

    DFSTraverse(G);
    BFSTraverse(G);

	return true;
}

/********************************************************************
	Method:    main
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
int main()
{
	OperationTest();
	
	return true;
}

