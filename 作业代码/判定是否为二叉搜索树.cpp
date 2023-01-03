//�б�����Ķ������Ƿ�Ϊ����������

//����һ:������������������õ��������У���������Ϊ���ͣ�
//������IsBST()�ķ���ֵΪ1�����Ƕ�����������Ϊ0���ǡ�
int TreeNode[50];
int i=0;
bool IsBST(BinTree BT)
{   //�жϸö������Ƿ�Ϊ����������
    InorderTraversal(BT);//���������������
    bool flag=1;
    int k=0;
    while(TreeNode[k+1]!=Null)
    {   //�ж϶�������������������Ƿ�Ϊ����
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
{   //�������������������data�������TreeNode[100]��
    If(BT)
    {
        InorderTraversal(BT->Left);
        TreeNode[i]=BT->Data;
        i++;
        InorderTraversal(BT->Right);
    }
}


//������:�ݹ鷨��ȱ�����޷�Խ���жϽ��data��С��
bool IsBST(BinTree BT)
{
    bool flag=1;

    //�ж�����data�Ƿ�С��BT��data
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

    //�ж��Һ���data�Ƿ����BT��data
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
