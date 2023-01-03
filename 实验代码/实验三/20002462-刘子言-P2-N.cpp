//利用邻接表存储有向图，编写程序实现对图的深度优先搜索
#include<iostream>
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
int AdjV;  //邻接点下标，无边权重
PtrToAdjVNode Next;  //指向下一个邻接点的指针
};

//顶点表头结点的定义
typedef struct Vnode{
PtrToAdjVNode FirstEdge;  //边表头指针
char Data;  //存顶点的数据
}AdjList[MaxVertexNum];

//图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode{
int Nv;  //顶点数
int Ne;  //边数
AdjList G;//邻接表
};
typedef PtrToGNode LGraph;//以邻接表的方式存储的图类型

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

//插入边
void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;
    //插入<v1,v2>，为v2建立新的邻接点
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->v2;
    //将v2插入v1的表头
    NewNode->Next = Graph->G[E->v1].FirstEdge;
    Graph->G[E->v1].FirstEdge = NewNode;
}

//构建图
LGraph BuildGraph()
{
    int Nv;
    cin>>Nv;
    //创建空图
    LGraph Graph;
    Graph = CreateGraph(Nv);
    //读入顶点的数据（char）
    for(int i=0; i<Graph->Nv; i++)
        cin>>Graph->G[i].Data;
    //创建边
    Edge E;
    E = (Edge)malloc(sizeof(struct ENode));
    char Vdata[2];
    for(int i=0; i<7; i++)//7条边
    {
        //读入边，顺序为起点、终点，无权重，插入邻接表
        cin>>Vdata[0]>>Vdata[1];
        for(int j=0; j<Graph->Nv; j++)  //找到起点终点data对应的顶点下标
        {
            if(Graph->G[j].Data == Vdata[0])
                E->v1 = j;
            if(Graph->G[j].Data == Vdata[1])
                E->v2 = j;
        }
        InsertEdge(Graph, E);//插入边
        Graph->Ne++;
    }
    return Graph;
}

//以第v个顶点为出发点，对领接表存储的图Graph进行深度优先搜索
void DFS(LGraph Graph, int v)
{
    PtrToAdjVNode f;
    Visited[v] = true;                              //标记顶点v已经访问过了为TRUE
    cout<<Graph->G[v].Data<<" ";                    //输出正在访问下标为v的顶点的data
    for(f = Graph->G[v].FirstEdge; f; f = f->Next)  //对于v的每一个邻接点f->AdjV
        if(!Visited[f->AdjV])                       //如果f指向的结点还没有被访问过
            DFS(Graph, f->AdjV);                     //则递归访问它
}

int main()
{
    cout<<"输入样例："<<endl;
    LGraph Graph;
    Graph = BuildGraph();

    cout<<"输出样例："<<endl;
    DFS(Graph, 0);  //深度优先搜索，选择从下标为0的顶点开始
    return 0;
}
/*
输入样例：
6
a b c d e f
a b
a c
a e
b e
e d
d f
e f
*/



