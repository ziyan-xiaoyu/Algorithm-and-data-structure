//�ж�һ�Ŷ������Ƿ�Ϊ ����������
#include<iostream>
#include<queue>
using namespace std;

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    int Data;//������������Ϊ����
    BinTree Left;
    BinTree Right;
};

int TreeMdata[50];  //��¼��������õ���ÿ������dataֵ����Ϊ-1����
int j=0;            //ͳ��TreeMdata���ж���Ԫ��

//�������������������
BinTree CreatBinTree(int Treedata[])
{
    int Data;
    int i=0;
    BinTree BT, T;
    queue<BinTree>Q;

    //������һ����㣬�������
    if(Treedata[i]==-1)i++;//������������õ��ĵ�һ����-1
    Data = Treedata[i];
    i++;
    if(Data != -1)
    {
        //������ڵ㵥Ԫ����������ַ���
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->Data = Data;
        BT->Left = BT->Right = NULL;
        Q.push(BT);
    }
    else return NULL;//���򷵻���Ϊ��

    while(!Q.empty()&&Treedata[i])
    {
        T = Q.front();
        Q.pop();

        Data = Treedata[i];//����T������
        i++;
        if(Data == -1)
            T->Left = NULL;
        else
        {
            //�����½�㣬��Ϊ���ӽ������ӣ��ٽ��½�����
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = Data;
            T->Left->Left = T->Left->Right = NULL;
            Q.push(T->Left);
        }

        Data = Treedata[i];//����T���Һ���
        i++;
        if(Data == -1)
            T->Right = NULL;
        else
        {
            //�����½�㣬��Ϊ���ӽ����Һ��ӣ��ٽ��½�����
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = Data;
            T->Right->Left = T->Right->Right = NULL;
            Q.push(T->Right);
        }
    }
    return BT;
}

//�������������������data�������Treedata[50]��
void InorderTraversal(BinTree BT)
{
    if(BT)
    {
        InorderTraversal(BT->Left);
        TreeMdata[j] = BT->Data;
        j++;
        InorderTraversal(BT->Right);
    }
}

//�жϵõ���TreeMdata[]�е�ֵ�Ƿ�Ϊ�������У��ɴ��ж��Ƿ�Ϊ������������
void IsBST(int Treedata[])
{
    int k=0;
    while(Treedata[k+1])
    {
        if(Treedata[k] >= Treedata[k+1])  //��������
        {
            cout<<"False"<<endl;
            break;
        }
        k++;
    }
    if(k+1 == j)  //ȫ��������
        cout<<"True"<<endl;
}

int main()
{
    cout<<"����������"<<endl;
    int TreeNode[50];   //��¼����Ķ�����ÿ������dataֵ����Ϊ-1����
    int i=0;
    while(true)
    {
        cin>>TreeNode[i];
        i++;
        if(getchar()!=' ')//�����س����������ǿո�ʱ���������
            break;
    }

    cout<<"���������"<<endl;
    BinTree BT;                 //������
    BT = CreatBinTree(TreeNode);//��������Ķ�����
    InorderTraversal(BT);       //����������õ������������������TreeMdata[j]
    IsBST(TreeMdata);           //�ж������������Ƿ�Ϊ����
    return 0;
}
//2 1 3  true
//5 1 4 -1 -1 3 6   false
