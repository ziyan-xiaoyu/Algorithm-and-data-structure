//寻找祖先节点并输出
#include<iostream>
#include <math.h>
using namespace std;

struct Node{
    int data;   //数据类型为整型
    int num;    //节点编号
    int floor;  //记录数据所在树的层数
};
Node BT[50];                  //定义输入的二叉树
int i=0;                //树的节点编号

void Ancestors(Node BT[], int a, int b)//在BT中寻找a,b的(最近的)公共祖先
{
    Node x,y;
    x.data = a;
    y.data = b;
    for(int j=0;j<i;j++)//先找到a,b在树中的位置
    {
        if(BT[j].data == x.data)
        {
            x.floor = BT[j].floor;
            x.num = j+1;
        }

        if(BT[j].data == y.data)
        {
            y.floor = BT[j].floor;
            y.num = j+1;
        }
    }

    while(x.data != y.data)//再通过自下而上比较父节点的方式寻找最近的祖先节点
    {
        if(x.floor > y.floor)
        {
            x.floor = x.floor - 1;
            x.num = x.num/2;
            x.data = BT[x.num-1].data;
        }
        else if(x.floor < y.floor)
        {
            y.floor = y.floor - 1;
            y.num = y.num/2;
            y.data = BT[y.num-1].data;
        }
        else
        {
            x.floor = x.floor - 1;
            y.floor = y.floor - 1;
            x.num = x.num/2;
            y.num = y.num/2;
            x.data = BT[x.num-1].data;
            y.data = BT[y.num-1].data;
        }
    }
    cout<<x.data<<endl;

}

int main()
{
    cout<<"输入样例："<<endl;
    while(true)
    {
        cin>>BT[i].data;//数据
        BT[i].num = i+1;//编号
        BT[i].floor = int(log(BT[i].num)/log(2))+1;//层数
        i++;
        if(getchar()!=' ')//当按回车键（不再是空格）时，输入结束
            break;
    }
    int a,b;              //记录两个子节点编号
    cin>>a;
    cin>>b;

    cout<<"输出样例："<<endl;
    Ancestors(BT, a, b);       //在BT中寻找a,b的(最近的)公共祖先
    return 0;
}
/*
3 5 1 6 2 0 8 -1 -1 7 4
5
1
3 5 1 6 2 0 8 -1 -1 7 4
5
4
*/
