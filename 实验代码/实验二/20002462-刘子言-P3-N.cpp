//判断一颗二叉树是否为 二叉搜索树
#include<iostream>
#include<queue>
using namespace std;

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    int Data;//假设数据类型为整型
    BinTree Left;
    BinTree Right;
};

int TreeMdata[50];  //记录中序遍历得到的每个结点的data值（空为-1）；
int j=0;            //统计TreeMdata中有多少元素

//层序遍历，创建二叉树
BinTree CreatBinTree(int Treedata[])
{
    int Data;
    int i=0;
    BinTree BT, T;
    queue<BinTree>Q;

    //建立第一个结点，即根结点
    if(Treedata[i]==-1)i++;//跳过中序遍历得到的第一个空-1
    Data = Treedata[i];
    i++;
    if(Data != -1)
    {
        //分配根节点单元，并将结点地址入队
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->Data = Data;
        BT->Left = BT->Right = NULL;
        Q.push(BT);
    }
    else return NULL;//否则返回树为空

    while(!Q.empty()&&Treedata[i])
    {
        T = Q.front();
        Q.pop();

        Data = Treedata[i];//读入T的左孩子
        i++;
        if(Data == -1)
            T->Left = NULL;
        else
        {
            //分配新结点，作为出队结点的左孩子；再将新结点入队
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = Data;
            T->Left->Left = T->Left->Right = NULL;
            Q.push(T->Left);
        }

        Data = Treedata[i];//读入T的右孩子
        i++;
        if(Data == -1)
            T->Right = NULL;
        else
        {
            //分配新结点，作为出队结点的右孩子；再将新结点入队
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = Data;
            T->Right->Left = T->Right->Right = NULL;
            Q.push(T->Right);
        }
    }
    return BT;
}

//中序遍历二叉树，并将data存进数组Treedata[50]中
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

//判断得到的TreeMdata[]中的值是否为升序序列，由此判断是否为二叉搜索树，
void IsBST(int Treedata[])
{
    int k=0;
    while(Treedata[k+1])
    {
        if(Treedata[k] >= Treedata[k+1])  //不是升序
        {
            cout<<"False"<<endl;
            break;
        }
        k++;
    }
    if(k+1 == j)  //全部是升序
        cout<<"True"<<endl;
}

int main()
{
    cout<<"输入样例："<<endl;
    int TreeNode[50];   //记录输入的二叉树每个结点的data值（空为-1）；
    int i=0;
    while(true)
    {
        cin>>TreeNode[i];
        i++;
        if(getchar()!=' ')//当按回车键（不再是空格）时，输入结束
            break;
    }

    cout<<"输出样例："<<endl;
    BinTree BT;                 //二叉树
    BT = CreatBinTree(TreeNode);//创建输入的二叉树
    InorderTraversal(BT);       //中序遍历，得到遍历结果，存入数组TreeMdata[j]
    IsBST(TreeMdata);           //判断中序遍历结果是否为升序
    return 0;
}
//2 1 3  true
//5 1 4 -1 -1 3 6   false
