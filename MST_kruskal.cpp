/********************************************************************
	Time:	  2015/11/09
	Filename: MST_kruskal
	Author:	  dinglj
	
	Purpose:  ��С������,kruskal
*********************************************************************/
#define INF     65536
#define MAXSIZE 20

//////////////////////////////////////////////////////////////////////
//  �ڽӾ���ṹ

typedef struct  
{
    int      no;
    char    info;
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
/********************************************************************
	Method:    MST_kruskal
	Parameter: 
	Returns:   

	Purpose:   �����ڽӾ�������㣬�ڽӱ�Ч�ʿ��ܸ���

*********************************************************************/
typedef struct  
{
    int vex1, vex2;
    int weight;
}Edge;

Edge mstedge[MAXSIZE];        //  �����洢�ṹ��������С������

//  ���ڽӾ���ı߱��浽����edge��
void storeEdge(MGraph G, Edge edge[])
{
    int edgeNo = 0;
    for (int i = 0; i < G.edgeNum; ++i)
    {
        for (int j = i; j < G.edgeNum; ++j)     //  ע��j���±��i + 1��ʼ������洢��ͬ��
        {
            if (G.e[i][j].weight != INF && G.e[i][j].weight != 0)
            {
                edge[edgeNo].vex1 = i;
                edge[edgeNo].vex2 = j;
                edge[edgeNo].weight = G.e[i][j].weight;

                edgeNo++;
            }
        }
    }
}

//  �Ա߽���ð������
void sortEdge(Edge edge[], int edgeNum)
{
    for (int i = 0; i < edgeNum; ++i)
    {
    //    for (int j = edgeNum - 1; j > i; j--)       //  β��ð��
        for (int j = 1; j < edgeNum - i; ++j)       //  ͷ��ð��
        {
            if (edge[j - 1].weight > edge[j].weight)
            {
                Edge temp = edge[j - 1];
                edge[j - 1] = edge[j];
                edge[j] = temp;
            }
        }
    }
}

//  MST_kruskal
void MST_kruskal(MGraph G)
{
    int vSet[MAXSIZE];  //  �����ṹ��vSet[i] == vSet[j] ��ʾi,j����ͬһ����ͨ����
    for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
    {
        vSet[vertexNo] = vertexNo;      //  ��ʼʱ�����еĶ�������ڲ�ͬ����ͨ����
    }
    
    //    �����
    Edge *edge = (Edge*)malloc(G.edgeNum * sizeof(Edge));      //  �����洢�ṹ���洢���б�
    storeEdge(G, edge);
    sortEdge(edge, G.edgeNum);

    //  ��n - 1����
    int edgeNo = 0;
    int index = 0;
    while (index < G.vertexNum - 1)
    {
        int s1 = vSet[edge[edgeNo].vex1];
        int s2 = vSet[edge[edgeNo].vex2];

        if (s1 != s2)   //  �ñߵĶ��㲻����ͬһ����ͨ����
        {
            mstedge[index] = edge[edgeNo];  //  ���ñ߱��浽��С������

            //  ��s2��������ͨ�������뵽s1��������ͨ����
            for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
            {
                if (s2 == vSet[vertexNo])
                {
                    vSet[vertexNo] = s1;
                }
            }
            index++;
        }

        edgeNo++;
    }

    free(edge);
}
