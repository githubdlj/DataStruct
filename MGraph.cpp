/********************************************************************
	Time:	  2015/09/22
	Filename: MGraph
	Author:	  dinglj
	
	Purpose:  图的顺序存储实现
*********************************************************************/

#include <stdio.h>

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
//	InitGraph(G);	//	初始化图

	printf("请输入顶点数目\n");
//	scanf("%d", &G.vertexNum);

//	printf("请输入顶点信息\n");
//	for (int i = 0; i < G.vertexNum; i++)
//	{
//		scanf("%c", &G.v[i].info);
//	}
//
//	printf("请输入边的数目\n");
//	scanf("%d\n", &G.edgeNum);
//
//	for (int i = 0; i < G.edgeNum; i++)
//	{
//		printf("请输入起点，终点和边权值\n");
//		
//		char start, end;
//		int weight;
//		scanf("%c%c%d", &start, &end, &weight);
//
//		//	获取顶点序号
//		int startNo = -1;
//		int endNo = -1;
//
//		startNo = getVertexNo(G, start);
//		endNo = getVertexNo(G, end);
//
//		G.e[startNo][endNo].weight = weight;
//	}

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

	CreateGraph(G);
//	PrintGraph(G);

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
	printf("hello world\n");
	
	printf("请输入顶点数目\n");
	
	int a = 0;
	scanf("%d", &a);
//	OperationTest();
	
	return true;
}
