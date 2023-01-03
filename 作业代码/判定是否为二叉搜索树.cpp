//判别给定的二叉树是否为二叉搜索树

//方法一:二叉搜索树中序遍历得到升序排列（假设数据为整型）
//若函数IsBST()的返回值为1，则是二叉搜索树；为0则不是。
int TreeNode[50];
int i=0;
bool IsBST(BinTree BT)
{   //判断该二叉树是否为二叉搜索树
    InorderTraversal(BT);//调用中序遍历函数
    bool flag=1;
    int k=0;
    while(TreeNode[k+1]!=Null)
    {   //判断二叉树中序遍历的序列是否为升序
        if(TreeNode[k]>=TreeNode[k+1])
        {
            flag=0;
            break;
        }
        k++;
    }
    return flag;
}
void InorderTraversal(BinTree BT)
{   //中序遍历二叉树，并将data存进数组TreeNode[100]中
    If(BT)
    {
        InorderTraversal(BT->Left);
        TreeNode[i]=BT->Data;
        i++;
        InorderTraversal(BT->Right);
    }
}


//方法二:递归法（缺点是无法越层判断结点data大小）
bool IsBST(BinTree BT)
{
    bool flag=1;

    //判断左孩子data是否小于BT的data
    if(BT->Lchild)
    {
        if(BT->Lchild->data >= BT->data)
        {
            flag = 0;
            return flag;
        }
        flag = IsBST(BT->Lchild);
    }
    if(!flag)return flag;

    //判断右孩子data是否大于BT的data
    if(BT->Rchild)
    {
        if(BT->Rchild->data <= BT->data)
        {
            flag = 0;
            return flag;
        }
        flag = IsBST(BT->Rchild);
    }
    return flag;
}
