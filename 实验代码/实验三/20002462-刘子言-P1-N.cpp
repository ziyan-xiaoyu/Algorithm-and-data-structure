//输出带权图的邻接矩阵
#include<iostream>
using namespace std;

#define MaxVertexNum 100//最大顶点数为100
#define Infinity 0//邻接矩阵中无边用0代替
//图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode{
int Nv;  //顶点数
int Ne;  //边数
int G[MaxVertexNum][MaxVertexNum];//邻接矩阵
};
typedef PtrToGNode MGraph;//以邻接矩阵的方式存储的图类型

//边的定义
typedef struct ENode *PtrToENode;
struct ENode{
int v1,v2;  //边的顶点
int w;      //权重
};
typedef PtrToENode Edge;

//初始化一个有VertexNum个顶点但没有边的图
MGraph CreateGraph(int VertexNum)
{
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    //初始化邻接矩阵，顶点编号从0开始到Nv-1
    for(int i=0; i<Graph->Nv; i++)
        for(int j=0; j<Graph->Nv; j++)
            Graph->G[i][j] = Infinity;//初始化矩阵为0
    return Graph;
}

//插入边
void InsertEdge(MGraph Graph, Edge E)
{
    //因为是有向图，一次只需插入一条边
    Graph->G[E->v1][E->v2] = E->w;
}

//构建图
MGraph BuildGraph()
{
    int Nv;
    cin>>Nv;
    MGraph Graph;
    Graph = CreateGraph(Nv);
    Edge E;
    E = (Edge)malloc(sizeof(struct ENode));
    for(int i=0; i<10; i++)//10条边
    {
        //读入边，顺序为起点、终点、权重，插入邻接矩阵
        cin>>E->v1>>E->v2>>E->w;
        InsertEdge(Graph, E);//插入边
        Graph->Ne++;
    }
    return Graph;
}

int main()
{
    cout<<"输入样例："<<endl;
    MGraph Graph;
    Graph = BuildGraph();
    cout<<"输出样例："<<endl;
    for(int i=0; i<Graph->Nv; i++)//输出邻接矩阵
    {
        for(int j=0; j<Graph->Nv; j++)
            cout<<Graph->G[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/*
输入样例：
6
0 1 5
0 3 7
1 2 4
2 0 8
2 5 9
3 2 5
3 5 6
4 3 5
5 0 3
5 4 1
*/
