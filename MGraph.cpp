/********************************************************************
	Time:	  2015/09/22
	Filename: MGraph
	Author:	  dinglj
	
	Purpose:  ͼ��˳��洢ʵ��
*********************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXSIZE 20	//	��󶥵���Ŀ
#define INF 65535	//	���ɴ��־

//	����ṹ
typedef struct
{
	int no;		//	������
	char info;	//	������Ϣ
}VertexType;

//	�߽ṹ
typedef struct  
{
	int weight;	//	��Ȩֵ��0��ʾ��ͬ�㣬INF��ʾ���ɴ�
}EdgeType;

//	ͼ�ṹ
typedef struct
{
	VertexType v[MAXSIZE];	//	����
	EdgeType e[MAXSIZE][MAXSIZE];	//	��

	//	������������
	int vertexNum;
	int edgeNum;

}MGraph;


//	������������
//////////////////////////////////////////////////////////////////////
bool Initgraph(MGraph &G);

bool CreateGraph(MGraph &G);
bool DestroyGraph(MGraph &G);

bool PrintGraph(MGraph G);

int getVertexNo(MGraph G, char info);		//	���ݶ�����Ϣ�õ�����
//////////////////////////////////////////////////////////////////////
/********************************************************************
	Method:    InitGraph
	Parameter: 
	Returns:   

	Purpose:   ��ʼ��ͼ

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

	Purpose:   ���ݽڵ���Ϣ�õ��ڵ���

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

	return -1;	//	û���ҵ�
}

/********************************************************************
	Method:    CreateGraph
	Parameter: 
	Returns:   

	Purpose:   ����������

*********************************************************************/
bool CreateGraph(MGraph &G)
{
	cout << "���붨����Ŀ" << endl;
	cin >> G.vertexNum;

	cout << "�����붥����Ϣ" << endl;
	for (int i = 0; i < G.vertexNum; i++)
	{
		cin >> G.v[i].info;
	}

	cout << "������ߵ���Ŀ" << endl;
	cin >> G.edgeNum;

	for (int i = 0; i < G.edgeNum; i++)
	{
		cout << "��������㣬�յ�ͱ�Ȩֵ" << endl;
		
		char start, end;
		int weight;
		cin >> start >> end >> weight;

		//	��ȡ�������
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

	Purpose:   ���ͼ��Ϣ

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

	Purpose:   ���Ժ���

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

