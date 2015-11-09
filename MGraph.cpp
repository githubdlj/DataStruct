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
//	�������
bool isVisited[MAXSIZE];    //  �������

void visit(VertexType v)
{
    printf("%c\t", v.info);
}

//  �����������
bool DFS(MGraph G, int v);
bool DFSTraverse(MGraph G);

// �����������
bool BFS(MGraph G, int v);
bool BFSTraverse(MGraph G);
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
        G.e[i][i].weight = 0;
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

//////////////////////////////////////////////////////////////////////
/********************************************************************
	Method:    DFS
	Parameter: 
	Returns:   

	Purpose:   ������ȱ���

*********************************************************************/
bool DFS(MGraph G, int v)
{
    visit(G.v[v]);
    isVisited[v] = 1;

    for (int adjvex = 0; adjvex < G.vertexNum; adjvex++)
    {
        //  Ѱ�ҵ��ڽӵ㣬�����ڽӵ�û�б����ʣ������
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
    //	��ÿһ���ڵ����DFS���������ͨͼ����forѭ��ʵ����ֻ��ִ��һ��
    for (int vertexNo = 0; vertexNo < G.vertexNum; vertexNo++)
    {
        if (!isVisited[vertexNo])
        {
            DFS(G, vertexNo);
            //	num++;	//	numΪ��ͨ������Ŀ
        }	
    }
    printf("\n");

    return true;
}

/********************************************************************
	Method:    BFS
	Parameter: 
	Returns:   

	Purpose:   ����������أ�ע�⣬��ӵ�ʱ����з��ʣ������

*********************************************************************/
bool BFS(MGraph G, int v)
{
    //  ��������
    int queue[MAXSIZE];
    int front = 0, rear = 0;

    queue[rear++] = v;    //  ���������
   
    visit(G.v[v]);   //  ���ʣ����
    isVisited[v] = 1;
    
    while (front != rear)   //  ���в���
    {
        v = queue[front++]; //  ������
        
        for (int adjvex = 0; adjvex < G.vertexNum; adjvex++)
        {
            //  Ѱ��û�б����ʹ����ڽӵ�
            if (INF != G.e[v][adjvex].weight && 0 != G.e[v][adjvex].weight && !isVisited[adjvex])
            {
                queue[rear++] = adjvex; //  ��ӣ����ʣ����
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

	Purpose:   ���Ժ���

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

