//二叉搜索树中序遍历以后形成递增序列，并生成新树
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

int TreeMdata[50];  //记录中序遍历得到的新树的每个结点的data值（空为-1）；
int j=0;            //统计TreeMdata中有多少元素

//层序遍历，创建二叉搜索树/生成新的递增顺序搜索树
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

//中序遍历二叉搜索树，并将data存进数组Treedata[50]中
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
    cout<<"输入样例："<<endl;
    int TreeNode[50];   //记录输入的二叉搜索树每个结点的data值（空为-1）；
    int i=0;
    while(true)
    {
        cin>>TreeNode[i];
        i++;
        if(getchar()!=' ')//当按回车键（不再是空格）时，输入结束
            break;
    }

    BinTree BST;        //二叉搜索树
    BinTree BSTM;       //中序遍历得到的新的递增序列搜索树
    BST = CreatBinTree(TreeNode);//创建输入的二叉搜索树
    InorderTraversal(BST);//中序遍历，并生成新的递增顺序搜索树

    cout<<"输出样例："<<endl;
    TreeMdata[j-1]=0;//跳过中序遍历得到的最后一个空-1
    BSTM = CreatBinTree(TreeMdata);//创建新的递增排序搜索树
    for(i=1;i<j-1;i++)
        cout<<TreeMdata[i]<<" ";

    return 0;
}
/*
输入样例：5 3 6 2 4 -1 8 1 -1 -1 -1 7 9
输出样例：1 null 2 null 3 null 4 null 5 null 6 null 7 null 8 null 9
注：样例里面的null在实验代码中均由“-1”代替
*/
