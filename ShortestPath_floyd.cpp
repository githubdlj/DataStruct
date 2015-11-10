/********************************************************************
	Time:	  2015/11/10
	Filename: ShortestPath_floyd
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

typedef struct
{
    VertexType v[MAXSIZE];
    EdgeType e[MAXSIZE][MAXSIZE];

    int vertexNum;
    int edgeNum;
}MGraph;

//////////////////////////////////////////////////////////////////////
/********************************************************************
	Method:    ShortestPath_floyd
	Parameter: 
	Returns:   

	Purpose:   ������һ�Զ���֮��ľ���  

*********************************************************************/
//  �����洢�ṹ, �洢����
int dist[MAXSIZE][MAXSIZE];

//  �����洢�ṹ���洢·��
int path[MAXSIZE][MAXSIZE];

//////////////////////////////////////////////////////////////////////
void ShortesPath_floyd(MGraph G)
{
    //  ��ʼ�������洢�ṹ
    for (int i = 0; i < G.vertexNum; ++i)
    {
        for (int j = 0; j < G.vertexNum; ++j)
        {
            dist[i][j] = G.e[i][j].weight;
            path[i][j] = -1;        //  path = -1�ȿ��Ա�ʾֱ�Ҳ�ɱ�ʾ���ɵ��Ҫ��dist�Ƿ�ΪINF
        }
    }

    //  
    for (int k = 0; k < G.vertexNum; ++k)
    {
        for (int i = 0; i < G.vertexNum; ++i)
        {
            for (int j = 0; j < G.vertexNum; ++j)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

//  ���·��<start, end>·��֮��ĵ�
void PrintPath(int start, int end)
{
    if (-1 != path[start][end])
    {
        PrintPath(start, path[start][end]);     //  ���start��k֮��ĵ�
        printf("%d\t", path[start][end]);       //  ���k
        PrintPath(path[start][end], end);       //  ���k��end֮��ĵ�
    }
}
