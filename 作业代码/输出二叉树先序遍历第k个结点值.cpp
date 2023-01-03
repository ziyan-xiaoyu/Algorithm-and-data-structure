//假设二叉树采用二叉链表方式存储
//输出先序遍历中第k个结点的值，k<=n。

#include<iostream>
using namespace std;

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    char Data;//假设数据类型为字符型
    BinTree Left;
    BinTree Right;
};
int i=0;

//采用先序创建的方法,根据输入的数值创建二叉树
void CreatBT(TNode **Node)//此处传递的参数为二重指针
{
	char data;
	cin>>data;

	*Node = (BinTree)malloc(sizeof(TNode));
	if(data == '#')
    {
		*Node = NULL;
	}
	else// if ((data != '#') && (*Node))
    {
		(*Node)->Data = data;
		(*Node)->Left = NULL;
		(*Node)->Right = NULL;
		CreatBT(&(*Node)->Left);
		CreatBT(&(*Node)->Right);
	}
}

//找到先序遍历中第k个值并输出
void PreTra_k(BinTree BT, int k)
{
    if(BT)
    {
        i++;
        if(i==k)
        {
            cout<<BT->Data;
            return;
        }
        if(BT->Left) PreTra_k(BT->Left, k);
        if(BT->Right) PreTra_k(BT->Right, k);
    }
}

int main()
{
    BinTree BT=NULL;
    cout<<"创建一棵二叉树："<<endl;
    CreatBT(&BT);

    int k=0;
    cout<<"想要输出此二叉树第几个结点的值：";
    cin>>k;
    PreTra_k(BT, k);

    return 0;
}


