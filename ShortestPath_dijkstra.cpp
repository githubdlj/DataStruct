/******************************************************************************
	Time:	  2015/11/10
	Filename: ShortestPath_dijkstra
	Author:	  dinglj
	
	Purpose:  
*********************************************************************/
#define INF     65536
#define MAXSIZE 20

//////////////////////////////////////////////////////////////////////
//  �ڽӾ���洢�ṹ
typedef struct  
{
    int no;
    char info;
}VertexType;

typedef struct  
{
    int weight;
}EdgeType;

//
typedef struct
{
    VertexType  v[MAXSIZE];
    EdgeType    e[MAXSIZE][MAXSIZE];

    int vertexNum;
    int edgeNum;
}MGraph;

/********************************************************************
	Method:    ShortestPath_dijkstra
	Parameter: 
	Returns:   

	Purpose:   ��Դ���·�����ڽӾ���

*********************************************************************/
//  �����洢�ṹ, �洢·���������൱��MST_prim�㷨�е�closedge
//  path[j] = {i, d}��ʾ���v��j�ľ���Ϊd����j��ǰ��Ϊi
typedef struct  
{
    int pre;      //    ǰ��
    int dist;     //    �ܾ���
}Path;      
Path path[MAXSIZE];

//  �����洢�ṹ���洢�Ѿ�Ѱ�ҵ��ĵ�U����, �����൱��MST_prim�㷨��closedge.lowcost = 0
//  vSet[i] = true��ʾ�Ѿ���i�����뵽����U
bool vSet[MAXSIZE];    

//////////////////////////////////////////////////////////////////////
void ShortestPath_dijkstra(MGraph G, int v)
{
    //  ��ʼ��path,vSet
    for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
    {
        path[vertexNo].pre = v;
        path[vertexNo].dist = G.e[v][vertexNo].weight;

        vSet[vertexNo] = false;
    }

    //  ��v���뵽���㼯��U
    vSet[v] = true;

    path[v].pre = -1;
    path[v].dist = 0;

    //  ��ʣ��n - 1�������
    for (int index = 0; index < G.vertexNum - 1; ++index)
    {
        int minDist = INF;
        int minIndex = 0;
        //  �ӽ��V - U���ҵ���̵ľ���
        for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
        {
            if (false == vSet[vertexNo] && path[vertexNo].dist < minDist)
            {
                minDist = path[vertexNo].dist;
                minIndex = vertexNo;
            }
        }

        //  ��minIndex����뼯��U
        vSet[minIndex] = true;
        
        //  ����dist
        for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
        {
            //  �˴�����MST_prim�߼��ϵ�����
            //  ���Բ�����vSet�жϣ�������MST_prim
            if ( (false == vSet[vertexNo]) && (path[minIndex].dist + G.e[minIndex][vertexNo].weight < path[vertexNo].dist))
            {
                path[vertexNo].dist = path[minIndex].dist + G.e[minIndex][vertexNo].weight;
                path[vertexNo].pre = minIndex;
            }
        }
    }
}

//  �������·����Ϣ��ʼ��v���յ�end��·����Ϣ
void PrintPath(int end)
{
    printf("%d\n", path[end].dist);
    while (path[end].pre != -1)
    {
        printf("%d\t", end);
        end = path[end].pre;
    }
}
