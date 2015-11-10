/******************************************************************************
	Time:	  2015/11/10
	Filename: ShortestPath_dijkstra
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

	Purpose:   单源最短路径，邻接矩阵

*********************************************************************/
//  辅助存储结构, 存储路径，作用相当于MST_prim算法中的closedge
//  path[j] = {i, d}表示起点v到j的距离为d，且j的前驱为i
typedef struct  
{
    int pre;      //    前驱
    int dist;     //    总距离
}Path;      
Path path[MAXSIZE];

//  辅助存储结构，存储已经寻找到的点U集合, 作用相当于MST_prim算法中closedge.lowcost = 0
//  vSet[i] = true表示已经将i点纳入到集合U
bool vSet[MAXSIZE];    

//////////////////////////////////////////////////////////////////////
void ShortestPath_dijkstra(MGraph G, int v)
{
    //  初始化path,vSet
    for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
    {
        path[vertexNo].pre = v;
        path[vertexNo].dist = G.e[v][vertexNo].weight;

        vSet[vertexNo] = false;
    }

    //  将v加入到顶点集合U
    vSet[v] = true;

    path[v].pre = -1;
    path[v].dist = 0;

    //  将剩余n - 1个点加入
    for (int index = 0; index < G.vertexNum - 1; ++index)
    {
        int minDist = INF;
        int minIndex = 0;
        //  从结合V - U中找到最短的距离
        for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
        {
            if (false == vSet[vertexNo] && path[vertexNo].dist < minDist)
            {
                minDist = path[vertexNo].dist;
                minIndex = vertexNo;
            }
        }

        //  将minIndex点加入集合U
        vSet[minIndex] = true;
        
        //  更新dist
        for (int vertexNo = 0; vertexNo < G.vertexNum; ++vertexNo)
        {
            //  此处是与MST_prim逻辑上的区别！
            //  可以不进行vSet判断，类似于MST_prim
            if ( (false == vSet[vertexNo]) && (path[minIndex].dist + G.e[minIndex][vertexNo].weight < path[vertexNo].dist))
            {
                path[vertexNo].dist = path[minIndex].dist + G.e[minIndex][vertexNo].weight;
                path[vertexNo].pre = minIndex;
            }
        }
    }
}

//  逆序输出路径信息起始点v到终点end的路径信息
void PrintPath(int end)
{
    printf("%d\n", path[end].dist);
    while (path[end].pre != -1)
    {
        printf("%d\t", end);
        end = path[end].pre;
    }
}
