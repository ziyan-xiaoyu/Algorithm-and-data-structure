//�����Ȩͼ���ڽӾ���
#include<iostream>
using namespace std;

#define MaxVertexNum 100//��󶥵���Ϊ100
#define Infinity 0//�ڽӾ������ޱ���0����
//ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode{
int Nv;  //������
int Ne;  //����
int G[MaxVertexNum][MaxVertexNum];//�ڽӾ���
};
typedef PtrToGNode MGraph;//���ڽӾ���ķ�ʽ�洢��ͼ����

//�ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode{
int v1,v2;  //�ߵĶ���
int w;      //Ȩ��
};
typedef PtrToENode Edge;

//��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
MGraph CreateGraph(int VertexNum)
{
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    //��ʼ���ڽӾ��󣬶����Ŵ�0��ʼ��Nv-1
    for(int i=0; i<Graph->Nv; i++)
        for(int j=0; j<Graph->Nv; j++)
            Graph->G[i][j] = Infinity;//��ʼ������Ϊ0
    return Graph;
}

//�����
void InsertEdge(MGraph Graph, Edge E)
{
    //��Ϊ������ͼ��һ��ֻ�����һ����
    Graph->G[E->v1][E->v2] = E->w;
}

//����ͼ
MGraph BuildGraph()
{
    int Nv;
    cin>>Nv;
    MGraph Graph;
    Graph = CreateGraph(Nv);
    Edge E;
    E = (Edge)malloc(sizeof(struct ENode));
    for(int i=0; i<10; i++)//10����
    {
        //����ߣ�˳��Ϊ��㡢�յ㡢Ȩ�أ������ڽӾ���
        cin>>E->v1>>E->v2>>E->w;
        InsertEdge(Graph, E);//�����
        Graph->Ne++;
    }
    return Graph;
}

int main()
{
    cout<<"����������"<<endl;
    MGraph Graph;
    Graph = BuildGraph();
    cout<<"���������"<<endl;
    for(int i=0; i<Graph->Nv; i++)//����ڽӾ���
    {
        for(int j=0; j<Graph->Nv; j++)
            cout<<Graph->G[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/*
����������
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
