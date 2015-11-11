/********************************************************************
	Time:	  2015/11/09
	Filename: MST_prim
	Author:	  dinglj
	
	Purpose:  最小生成树，无向网
              邻接矩阵实现
              复杂度：邻接矩阵O(n ^ 2), 邻接表O(n ^ 2)
*********************************************************************/
#define INF     65536
#define MAXSIZE 20

//////////////////////////////////////////////////////////////////////
//  图的邻接矩阵存储结构
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
//  辅助结构

//  closedge[j].adjvex=k，表明边(vj, vk)是V-U中顶点vj到U中权值最小的边. closedge[j].lowcost存放该边的权值。
//  closedge[j].lowcost = 0表示将j加入到顶点集合U
//  这里closedge[j].lowcost起到了两个作用，当然，可以另外设置一个辅助数组vSet[MAXSIZE]存储顶点集合U
typedef struct  
{
    int adjvex;     
    int lowcost;
}ClosEdge;

//  保存最小生成树的边
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

	Purpose:   prim，邻接矩阵存储

*********************************************************************/
void MST_prim(MGraph G, int v)
{
    ClosEdge closedge[MAXSIZE];
    
    //  初始化closedge
    for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
    {
        closedge[vertexNo].adjvex = v;
        closedge[vertexNo].lowcost = G.e[v][vertexNo].weight;
    }

    closedge[v].lowcost = 0;    //  v加入到顶点集合U

    //  将剩余的n - 1个点加入到集合U
    for (int index = 0; index < G.vertexNum - 1; ++index)
    {
        int minValue = INF;
        int minIndex = 0;
        //  从集合V - U中找到closedge[vertexNo].lowcost最小的值
        for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
        {
            if (0 != closedge[vertexNo].lowcost && closedge[vertexNo].lowcost < minValue)
            {
                minValue = closedge[vertexNo].lowcost;
                minIndex = vertexNo;

            }
        }

        //  将信息保存到MSTEdge
        mstedge[index].vex1 = closedge[minIndex].adjvex;
        mstedge[index].vex2 = minIndex;
        mstedge[index].weight = closedge[minIndex].lowcost;

        //  更新closedge[index]
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

