//给一个社交网络图，对每个节点计算符合“六度空间”理论的结点占结点总数的百分比
//总体思路是：采用 邻接表存储图 + 广度优先搜索 + 队列的实现过程
#include<iostream>
#include<queue>
using namespace std;

#define MaxVertexNum 100//最大顶点数为100
bool Visited[MaxVertexNum] = {false};//记录该顶点是否已经访问过了

//边的定义
typedef struct ENode *PtrToENode;
struct ENode{
int v1,v2;  //边的顶点，无权重
};
typedef PtrToENode Edge;

//邻接点的定义
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
int AdjV;            //邻接点下标，无边权重
PtrToAdjVNode Next;  //指向下一个邻接点的指针
};

//顶点表头结点的定义
typedef struct Vnode{
PtrToAdjVNode FirstEdge;  //边表头指针，无顶点数据
}AdjList[MaxVertexNum];

//图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode{
int Nv;   //顶点数
int Ne;   //边数
AdjList G; //邻接表
};
typedef PtrToGNode LGraph;  //以邻接表的方式存储的图类型

//初始化一个有VertexNum个顶点但没有边的图
LGraph CreateGraph(int VertexNum)
{
    LGraph Graph;
    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    //初始化邻接表头指针，顶点编号从0开始到Nv-1
    for(int i=0; i<Graph->Nv; i++)
        Graph->G[i].FirstEdge = NULL;
    return Graph;
}

//插入边（注意：社交网络图为无向图）
void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;
    //插入<v1,v2>，为v2建立新的邻接点
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->v2;
    //将v2插入v1的表头
    NewNode->Next = Graph->G[E->v1].FirstEdge;
    Graph->G[E->v1].FirstEdge = NewNode;

    //插入<v2,v1>，为v1建立新的邻接点
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->v1;
    //将v1插入v2的表头
    NewNode->Next = Graph->G[E->v2].FirstEdge;
    Graph->G[E->v2].FirstEdge = NewNode;
}

//构建图
LGraph BuildGraph()
{
    int Nv,Ne,Vdata[2];
    cin>>Nv>>Ne;
    //创建空图
    LGraph Graph;
    Graph = CreateGraph(Nv);
    //创建边
    Edge E;
    E = (Edge)malloc(sizeof(struct ENode));
    for(int i=0; i<Ne; i++)
    {
        //读入边，顺序为起点、终点，无权重，插入邻接表
        cin>>Vdata[0]>>Vdata[1];//把结点编号转化为下标，-1即可
        E->v1 = Vdata[0]-1;
        E->v2 = Vdata[1]-1;
        InsertEdge(Graph, E);//插入边
    }
    return Graph;
}

//以S为出发点，对图Graph进行6层的BFS广度优先搜索
int SDS_BFS(LGraph Graph, int S)
{
    queue<int>Q;
    int V,Last,Tail;
    PtrToAdjVNode F;        //定义一个指向邻接表结点的指针
    int Count, Level;

    Visited[S] = true;     //标记顶点v已经访问过了为TRUE
    Count = 1;              //统计符合“六度空间”理论的人数，从1开始
    Level = 0;              //起始点定义为第0层
    Last = S;               //该层只有S一个顶点，是该层被访问的最后一个顶点
    Q.push(S);              //将S入队列

    while(!Q.empty())
    {
        V = Q.front();
        Q.pop();
        for(F = Graph->G[V].FirstEdge; F; F = F->Next)//对于V的每一个邻接点F->AdjV
        {
            if(!Visited[F->AdjV])             //如果F指向的结点还没有被访问
            {
                Visited[F->AdjV] = true;     //标记F->AdjV已被访问
                Count++;                     //人数加1
                Tail = F->AdjV;              //改变层尾
                Q.push(F->AdjV);             //将F->AdjV入队列
            }
        }
        if(V == Last)           //如果上一层的最后一个顶点弹出了
        {
            Level++;            //层数递增
            Last = Tail;        //更新当前层尾为该层被访问的最后一个顶点
        }
        if(Level == 6) break;  //如果6层遍历结束，退出搜索
    }
    if(!Q.empty()) Q.pop();//释放队列所有元素
    return Count;//返回统计的人数
}

void InitializeVisited(int Nv)  //一个顶点的六度空间搜索完毕以后，要重新初始化某些顶点的Visited[]值
{
    for(int i=0; i<Nv; i++)
        Visited[i] = false;
}

//用邻接表存储图，对每个顶点检验六度空间理论
void Six_Degrees_of_Separation(LGraph Graph)
{
    int Count;
    for(int i=0; i<Graph->Nv; i++)              //对图中的每个顶点都检验一遍六度空间理论
    {
        InitializeVisited(Graph->Nv);           //初始化Visited[]值
        Count = SDS_BFS(Graph, i);              //BFS广度优先搜索，检验六度空间
        printf("%d：%.2f%%\n", i+1, 100.0*(double)Count/(double)Graph->Nv);
    }
}

int main()
{
    cout<<"输入样例："<<endl;
    LGraph Graph;                      //用邻接表存储图
    Graph = BuildGraph();

    cout<<"输出样例："<<endl;
    Six_Degrees_of_Separation(Graph);  //对图的每个顶点检验六度空间理论
    return 0;
}
/*
输入样例
10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/
