//�����ڽӱ�洢����ͼ����д����ʵ�ֶ�ͼ�������������
#include<iostream>
using namespace std;

#define MaxVertexNum 100//��󶥵���Ϊ100
bool Visited[MaxVertexNum] = {false};//��¼�ö����Ƿ��Ѿ����ʹ���

//�ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode{
int v1,v2;  //�ߵĶ��㣬��Ȩ��
};
typedef PtrToENode Edge;

//�ڽӵ�Ķ���
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
int AdjV;  //�ڽӵ��±꣬�ޱ�Ȩ��
PtrToAdjVNode Next;  //ָ����һ���ڽӵ��ָ��
};

//�����ͷ���Ķ���
typedef struct Vnode{
PtrToAdjVNode FirstEdge;  //�߱�ͷָ��
char Data;  //�涥�������
}AdjList[MaxVertexNum];

//ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode{
int Nv;  //������
int Ne;  //����
AdjList G;//�ڽӱ�
};
typedef PtrToGNode LGraph;//���ڽӱ�ķ�ʽ�洢��ͼ����

//��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
LGraph CreateGraph(int VertexNum)
{
    LGraph Graph;
    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    //��ʼ���ڽӱ�ͷָ�룬�����Ŵ�0��ʼ��Nv-1
    for(int i=0; i<Graph->Nv; i++)
        Graph->G[i].FirstEdge = NULL;
    return Graph;
}

//�����
void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;
    //����<v1,v2>��Ϊv2�����µ��ڽӵ�
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->v2;
    //��v2����v1�ı�ͷ
    NewNode->Next = Graph->G[E->v1].FirstEdge;
    Graph->G[E->v1].FirstEdge = NewNode;
}

//����ͼ
LGraph BuildGraph()
{
    int Nv;
    cin>>Nv;
    //������ͼ
    LGraph Graph;
    Graph = CreateGraph(Nv);
    //���붥������ݣ�char��
    for(int i=0; i<Graph->Nv; i++)
        cin>>Graph->G[i].Data;
    //������
    Edge E;
    E = (Edge)malloc(sizeof(struct ENode));
    char Vdata[2];
    for(int i=0; i<7; i++)//7����
    {
        //����ߣ�˳��Ϊ��㡢�յ㣬��Ȩ�أ������ڽӱ�
        cin>>Vdata[0]>>Vdata[1];
        for(int j=0; j<Graph->Nv; j++)  //�ҵ�����յ�data��Ӧ�Ķ����±�
        {
            if(Graph->G[j].Data == Vdata[0])
                E->v1 = j;
            if(Graph->G[j].Data == Vdata[1])
                E->v2 = j;
        }
        InsertEdge(Graph, E);//�����
        Graph->Ne++;
    }
    return Graph;
}

//�Ե�v������Ϊ�����㣬����ӱ�洢��ͼGraph���������������
void DFS(LGraph Graph, int v)
{
    PtrToAdjVNode f;
    Visited[v] = true;                              //��Ƕ���v�Ѿ����ʹ���ΪTRUE
    cout<<Graph->G[v].Data<<" ";                    //������ڷ����±�Ϊv�Ķ����data
    for(f = Graph->G[v].FirstEdge; f; f = f->Next)  //����v��ÿһ���ڽӵ�f->AdjV
        if(!Visited[f->AdjV])                       //���fָ��Ľ�㻹û�б����ʹ�
            DFS(Graph, f->AdjV);                     //��ݹ������
}

int main()
{
    cout<<"����������"<<endl;
    LGraph Graph;
    Graph = BuildGraph();

    cout<<"���������"<<endl;
    DFS(Graph, 0);  //�������������ѡ����±�Ϊ0�Ķ��㿪ʼ
    return 0;
}
/*
����������
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



