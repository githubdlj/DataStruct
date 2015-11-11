/********************************************************************
	Time:	  2015/11/09
	Filename: MST_prim
	Author:	  dinglj
	
	Purpose:  ��С��������������
              �ڽӾ���ʵ��
              ���Ӷȣ��ڽӾ���O(n ^ 2), �ڽӱ�O(n ^ 2)
*********************************************************************/
#define INF     65536
#define MAXSIZE 20

//////////////////////////////////////////////////////////////////////
//  ͼ���ڽӾ���洢�ṹ
typedef struct
{
    int no;
    char info;
}VertexType;

typedef struct
{
    int weight;
}EdgeType;

typedef struct
{
    VertexType  v[MAXSIZE];
    EdgeType    e[MAXSIZE][MAXSIZE];

    int vertexNum;
    int edgeNum;
}MGraph;

//////////////////////////////////////////////////////////////////////
//  �����ṹ

//  closedge[j].adjvex=k��������(vj, vk)��V-U�ж���vj��U��Ȩֵ��С�ı�. closedge[j].lowcost��Ÿñߵ�Ȩֵ��
//  closedge[j].lowcost = 0��ʾ��j���뵽���㼯��U
//  ����closedge[j].lowcost�����������ã���Ȼ��������������һ����������vSet[MAXSIZE]�洢���㼯��U
typedef struct  
{
    int adjvex;     
    int lowcost;
}ClosEdge;

//  ������С�������ı�
typedef struct
{
    int vex1, vex2;
    int weight;
}MSTEdge;
MSTEdge mstedge[MAXSIZE];

/********************************************************************
	Method:    MST_prim
	Parameter: 
	Returns:   

	Purpose:   prim���ڽӾ���洢

*********************************************************************/
void MST_prim(MGraph G, int v)
{
    ClosEdge closedge[MAXSIZE];
    
    //  ��ʼ��closedge
    for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
    {
        closedge[vertexNo].adjvex = v;
        closedge[vertexNo].lowcost = G.e[v][vertexNo].weight;
    }

    closedge[v].lowcost = 0;    //  v���뵽���㼯��U

    //  ��ʣ���n - 1������뵽����U
    for (int index = 0; index < G.vertexNum - 1; ++index)
    {
        int minValue = INF;
        int minIndex = 0;
        //  �Ӽ���V - U���ҵ�closedge[vertexNo].lowcost��С��ֵ
        for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
        {
            if (0 != closedge[vertexNo].lowcost && closedge[vertexNo].lowcost < minValue)
            {
                minValue = closedge[vertexNo].lowcost;
                minIndex = vertexNo;

            }
        }

        //  ����Ϣ���浽MSTEdge
        mstedge[index].vex1 = closedge[minIndex].adjvex;
        mstedge[index].vex2 = minIndex;
        mstedge[index].weight = closedge[minIndex].lowcost;

        //  ����closedge[index]
        for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
        {
            if (G.e[minIndex][vertexNo].weight < closedge[vertexNo].lowcost)
            {
                closedge[vertexNo].lowcost = G.e[minIndex][vertexNo].weight;
                closedge[vertexNo].adjvex = minIndex;
            }
        }
    }
}

