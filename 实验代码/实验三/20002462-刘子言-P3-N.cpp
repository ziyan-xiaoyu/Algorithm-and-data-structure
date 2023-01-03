//��һ���罻����ͼ����ÿ���ڵ������ϡ����ȿռ䡱���۵Ľ��ռ��������İٷֱ�
//����˼·�ǣ����� �ڽӱ�洢ͼ + ����������� + ���е�ʵ�ֹ���
#include<iostream>
#include<queue>
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
int AdjV;            //�ڽӵ��±꣬�ޱ�Ȩ��
PtrToAdjVNode Next;  //ָ����һ���ڽӵ��ָ��
};

//�����ͷ���Ķ���
typedef struct Vnode{
PtrToAdjVNode FirstEdge;  //�߱�ͷָ�룬�޶�������
}AdjList[MaxVertexNum];

//ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode{
int Nv;   //������
int Ne;   //����
AdjList G; //�ڽӱ�
};
typedef PtrToGNode LGraph;  //���ڽӱ�ķ�ʽ�洢��ͼ����

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

//����ߣ�ע�⣺�罻����ͼΪ����ͼ��
void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;
    //����<v1,v2>��Ϊv2�����µ��ڽӵ�
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->v2;
    //��v2����v1�ı�ͷ
    NewNode->Next = Graph->G[E->v1].FirstEdge;
    Graph->G[E->v1].FirstEdge = NewNode;

    //����<v2,v1>��Ϊv1�����µ��ڽӵ�
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->v1;
    //��v1����v2�ı�ͷ
    NewNode->Next = Graph->G[E->v2].FirstEdge;
    Graph->G[E->v2].FirstEdge = NewNode;
}

//����ͼ
LGraph BuildGraph()
{
    int Nv,Ne,Vdata[2];
    cin>>Nv>>Ne;
    //������ͼ
    LGraph Graph;
    Graph = CreateGraph(Nv);
    //������
    Edge E;
    E = (Edge)malloc(sizeof(struct ENode));
    for(int i=0; i<Ne; i++)
    {
        //����ߣ�˳��Ϊ��㡢�յ㣬��Ȩ�أ������ڽӱ�
        cin>>Vdata[0]>>Vdata[1];//�ѽ����ת��Ϊ�±꣬-1����
        E->v1 = Vdata[0]-1;
        E->v2 = Vdata[1]-1;
        InsertEdge(Graph, E);//�����
    }
    return Graph;
}

//��SΪ�����㣬��ͼGraph����6���BFS�����������
int SDS_BFS(LGraph Graph, int S)
{
    queue<int>Q;
    int V,Last,Tail;
    PtrToAdjVNode F;        //����һ��ָ���ڽӱ����ָ��
    int Count, Level;

    Visited[S] = true;     //��Ƕ���v�Ѿ����ʹ���ΪTRUE
    Count = 1;              //ͳ�Ʒ��ϡ����ȿռ䡱���۵���������1��ʼ
    Level = 0;              //��ʼ�㶨��Ϊ��0��
    Last = S;               //�ò�ֻ��Sһ�����㣬�Ǹò㱻���ʵ����һ������
    Q.push(S);              //��S�����

    while(!Q.empty())
    {
        V = Q.front();
        Q.pop();
        for(F = Graph->G[V].FirstEdge; F; F = F->Next)//����V��ÿһ���ڽӵ�F->AdjV
        {
            if(!Visited[F->AdjV])             //���Fָ��Ľ�㻹û�б�����
            {
                Visited[F->AdjV] = true;     //���F->AdjV�ѱ�����
                Count++;                     //������1
                Tail = F->AdjV;              //�ı��β
                Q.push(F->AdjV);             //��F->AdjV�����
            }
        }
        if(V == Last)           //�����һ������һ�����㵯����
        {
            Level++;            //��������
            Last = Tail;        //���µ�ǰ��βΪ�ò㱻���ʵ����һ������
        }
        if(Level == 6) break;  //���6������������˳�����
    }
    if(!Q.empty()) Q.pop();//�ͷŶ�������Ԫ��
    return Count;//����ͳ�Ƶ�����
}

void InitializeVisited(int Nv)  //һ����������ȿռ���������Ժ�Ҫ���³�ʼ��ĳЩ�����Visited[]ֵ
{
    for(int i=0; i<Nv; i++)
        Visited[i] = false;
}

//���ڽӱ�洢ͼ����ÿ������������ȿռ�����
void Six_Degrees_of_Separation(LGraph Graph)
{
    int Count;
    for(int i=0; i<Graph->Nv; i++)              //��ͼ�е�ÿ�����㶼����һ�����ȿռ�����
    {
        InitializeVisited(Graph->Nv);           //��ʼ��Visited[]ֵ
        Count = SDS_BFS(Graph, i);              //BFS��������������������ȿռ�
        printf("%d��%.2f%%\n", i+1, 100.0*(double)Count/(double)Graph->Nv);
    }
}

int main()
{
    cout<<"����������"<<endl;
    LGraph Graph;                      //���ڽӱ�洢ͼ
    Graph = BuildGraph();

    cout<<"���������"<<endl;
    Six_Degrees_of_Separation(Graph);  //��ͼ��ÿ������������ȿռ�����
    return 0;
}
/*
��������
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
