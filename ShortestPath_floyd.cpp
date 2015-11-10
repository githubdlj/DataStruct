/********************************************************************
	Time:	  2015/11/10
	Filename: ShortestPath_floyd
	Author:	  dinglj
	
	Purpose:  
*********************************************************************/
#define INF     65536
#define MAXSIZE 20

//////////////////////////////////////////////////////////////////////
//  邻接矩阵存储结构
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

	Purpose:   求任意一对顶点之间的距离  

*********************************************************************/
//  辅助存储结构, 存储距离
int dist[MAXSIZE][MAXSIZE];

//  辅助存储结构，存储路径
int path[MAXSIZE][MAXSIZE];

//////////////////////////////////////////////////////////////////////
void ShortesPath_floyd(MGraph G)
{
    //  初始化辅助存储结构
    for (int i = 0; i < G.vertexNum; ++i)
    {
        for (int j = 0; j < G.vertexNum; ++j)
        {
            dist[i][j] = G.e[i][j].weight;
            path[i][j] = -1;        //  path = -1既可以表示直达，也可表示不可到达，要看dist是否为INF
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

//  输出路径<start, end>路径之间的点
void PrintPath(int start, int end)
{
    if (-1 != path[start][end])
    {
        PrintPath(start, path[start][end]);     //  输出start到k之间的点
        printf("%d\t", path[start][end]);       //  输出k
        PrintPath(path[start][end], end);       //  输出k到end之间的点
    }
}
