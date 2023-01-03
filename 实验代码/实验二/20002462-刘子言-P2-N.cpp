//������������������Ժ��γɵ������У�����������
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

int TreeMdata[50];  //��¼��������õ���������ÿ������dataֵ����Ϊ-1����
int j=0;            //ͳ��TreeMdata���ж���Ԫ��

//�����������������������/�����µĵ���˳��������
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

//�����������������������data�������Treedata[50]��
void InorderTraversal(BinTree BT)
{
    if(BT)
    {
        InorderTraversal(BT->Left);
        TreeMdata[j] = BT->Data;
        j++;
        InorderTraversal(BT->Right);
    }
    else
    {
        TreeMdata[j] = -1;
        j++;
    }
}

int main()
{
    cout<<"����������"<<endl;
    int TreeNode[50];   //��¼����Ķ���������ÿ������dataֵ����Ϊ-1����
    int i=0;
    while(true)
    {
        cin>>TreeNode[i];
        i++;
        if(getchar()!=' ')//�����س����������ǿո�ʱ���������
            break;
    }

    BinTree BST;        //����������
    BinTree BSTM;       //��������õ����µĵ�������������
    BST = CreatBinTree(TreeNode);//��������Ķ���������
    InorderTraversal(BST);//����������������µĵ���˳��������

    cout<<"���������"<<endl;
    TreeMdata[j-1]=0;//������������õ������һ����-1
    BSTM = CreatBinTree(TreeMdata);//�����µĵ�������������
    for(i=1;i<j-1;i++)
        cout<<TreeMdata[i]<<" ";

    return 0;
}
/*
����������5 3 6 2 4 -1 8 1 -1 -1 -1 7 9
���������1 null 2 null 3 null 4 null 5 null 6 null 7 null 8 null 9
ע�����������null��ʵ������о��ɡ�-1������
*/
