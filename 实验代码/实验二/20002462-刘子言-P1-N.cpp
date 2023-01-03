//判断两棵二叉树是否同构
#include<iostream>
#include <string.h>
using namespace std;

struct TNode{
    char data;   //数据类型为字符
    int left;    //左孩子对应编号
    int right;  //右孩子对应编号
};
TNode BT1[50],BT2[50];    //定义输入的两棵二叉树
int flag = 0;            //判断两棵树是否同构，=0目前同构，=1不同构

//根据左右孩子结点的编号找到左右结点的data，并传回
//将无孩子结点的-1都改为字符‘0’，更方便直接比较
char getBT1_childData(int num)
{
    if(num != -1)
        return BT1[num].data;
    else
        return '0';
}
char getBT2_childData(int num)
{
    if(num != -1)
        return BT2[num].data;
    else
        return '0';
}

//比较两棵树相同的结点的左右孩子结点的data是否相等
void compare(char L1, char R1, char L2, char R2)
{
    if(L1 == L2)        //1左=2左
    {
        if(R1 != R2)    //1右!=2右
            flag = 1;
    }
    else if(L1 == R2)  //1左=2右
    {
        if(R1 != L2)    //1右!=2左
            flag = 1;
    }
    else               //1左和2的左右都不等
        flag = 1;
}

int main()
{
    int N1,N2;         //分别为两棵树的节点数

    cout<<"输入样例："<<endl;
    //输入BT1
    cin>>N1;
    for(int i=0;i<N1;i++)
        cin>>BT1[i].data>>BT1[i].left>>BT1[i].right;
    //输入BT2
    cin>>N2;
    for(int i=0;i<N2;i++)
        cin>>BT2[i].data>>BT2[i].left>>BT2[i].right;
    if(N1!=N2) flag = 1;//结点数不等肯定不同构

    if(flag == 0)      //如果结点数相同，继续判断
    {
        for(int i=0;i<N1;i++)
        {
            int j=0;
            for(j=0;j<N2;j++)
            {
                if(BT1[i].data == BT2[j].data)//找到了BT2中与BT1[i]对应的结点data
                {
                    //比较它们俩的左右孩子结点的data
                    compare(getBT1_childData(BT1[i].left), getBT1_childData(BT1[i].right), getBT2_childData(BT2[j].left) , getBT2_childData(BT2[j].right));
                    break;
                }
            }
            if(j==N2 || flag)//如果BT2中没有BT1[i]对应的那个结点,或者已经检测出flag为1了，就结束循环
            {
                flag = 1;
                break;
            }
        }
    }

    cout<<"输出样例："<<endl;
    if(flag)
        cout<<"False"<<endl;
    else
        cout<<"True"<<endl;
    return 0;
}
/*
输入样例
8
A 1 2
B 3 4
C 5 -1
D -1 -1
E 6 -1
G 7 -1
F -1 -1
H -1 -1
8
G -1 4
B 7 6
F -1 -1
A 5 1
H -1 -1
C 0 -1
D -1 -1
E 2 -1
*/
