//将两个升序链表合并为一个升序链表
#include<iostream>
using namespace std;

typedef struct Node * PtrToNode;
struct Node{
    int Data;//数据
    PtrToNode Next;
};
typedef PtrToNode List;

List CreatL()//创建链表
{
    List L, Lfront, temp;

    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    Lfront = L;//记录链表头结点

//方法一
    while(true)//创建任意长度的链表
    {
        temp = (List)malloc(sizeof(struct Node));
        cin>>temp->Data;
        temp->Next = NULL;
        L->Next = temp;
        L = L->Next;
        if(getchar()!=' ')//当按回车键（不再接空格）时，链表创建结束并返回
            return Lfront;
    }
//方法二
//    for(int i=0;i<3;i++)//假定链表长度为3，则可以用for循环代替上面的while循环
//    {
//          temp = (List)malloc(sizeof(struct Node));
//          cin>>temp->Data;
//          temp->Next = NULL;
//          L->Next = temp;
//          L = L->Next;
//    }
//    return Lfront;//返回头结点指针
}

void AddL(List L1, List L2)//合并链表
{

    List L3 = L1;//结果链表在L1基础上
    int d1, d2;
    L1 = L1->Next;
    L2 = L2->Next;

    while(L1&&L2)
    {
        if(L1->Data >= L2->Data)//L2的值偏小
        {
            L3->Next = L2;
            L3 = L3->Next;
            L2 = L2->Next;
        }
        else//L1的值偏小
        {
            L3->Next = L1;
            L3 = L3->Next;
            L1 = L1->Next;
        }
    }
    if(L1)
        L3->Next = L1;
    else
        L3->Next = L2;
}

int main()
{
    cout<<"输入样例："<<endl;
    List L1 = CreatL();//创建链表L1
    List L2 = CreatL();//创建链表L2
    List Lfront = L1;//记录L1头结点

    cout<<"输出样例："<<endl;
    AddL(L1,L2);//合并L1、L2到L1

    while(Lfront->Next)//输出合并的升序链表
    {
        Lfront = Lfront->Next;
        cout<<Lfront->Data<<" ";
    }

    return 0;
}
/*
输入：1 4 5
1 3 6
输出：1 1 3 4 5 6
*/
