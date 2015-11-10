/********************************************************************
	Time:	  2015/11/09
	Filename: MST_kruskal
	Author:	  dinglj
	
	Purpose:  最小生成树,kruskal
*********************************************************************/
#define INF     65536
#define MAXSIZE 20

//////////////////////////////////////////////////////////////////////
//  邻接矩阵结构

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

	Purpose:   采用邻接矩阵更方便，邻接表效率可能更高

*********************************************************************/
typedef struct  
{
    int vex1, vex2;
    int weight;
}Edge;

Edge mstedge[MAXSIZE];        //  辅助存储结构，保存最小生成树

//  将邻接矩阵的边保存到数组edge中
void storeEdge(MGraph G, Edge edge[])
{
    int edgeNo = 0;
    for (int i = 0; i < G.edgeNum; ++i)
    {
        for (int j = i; j < G.edgeNum; ++j)     //  注意j的下标从i + 1开始，避免存储相同边
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

//  对边进行冒泡排序，
void sortEdge(Edge edge[], int edgeNum)
{
    for (int i = 0; i < edgeNum; ++i)
    {
    //    for (int j = edgeNum - 1; j > i; j--)       //  尾部冒泡
        for (int j = 1; j < edgeNum - i; ++j)       //  头部冒泡
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
    int vSet[MAXSIZE];  //  辅助结构，vSet[i] == vSet[j] 表示i,j属于同一个连通分量
    for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
    {
        vSet[vertexNo] = vertexNo;      //  初始时，所有的顶点均属于不同的连通分量
    }
    
    //    处理边
    Edge *edge = (Edge*)malloc(G.edgeNum * sizeof(Edge));      //  辅助存储结构，存储所有边
    storeEdge(G, edge);
    sortEdge(edge, G.edgeNum);

    //  找n - 1条边
    int edgeNo = 0;
    int index = 0;
    while (index < G.vertexNum - 1)
    {
        int s1 = vSet[edge[edgeNo].vex1];
        int s2 = vSet[edge[edgeNo].vex2];

        if (s1 != s2)   //  该边的顶点不属于同一个连通分量
        {
            mstedge[index] = edge[edgeNo];  //  将该边保存到最小生成树

            //  将s2所属的连通分量加入到s1所属的连通分量
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
