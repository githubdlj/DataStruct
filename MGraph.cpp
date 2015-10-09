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

