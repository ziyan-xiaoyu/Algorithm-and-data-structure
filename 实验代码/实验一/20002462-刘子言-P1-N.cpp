//采用链式结构存储一元多项式并对其求导
#include<iostream>
using namespace std;

typedef struct PolyNode * PtrToPolyNode;
struct PolyNode{
    int Coef;//系数
    int Expon;//指数
    PtrToPolyNode Next;
};
typedef PtrToPolyNode Polynomial;

Polynomial CreatP()  //创建链表表示多项式
{
    Polynomial P, Pfront, temp;

    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->Next = NULL;
    Pfront = P;     //记录多项式链表头结点

    for(int i=0;i<4;i++)  //假定输入的多项式有4项
    {
        temp = (Polynomial)malloc(sizeof(struct PolyNode));
        cin>>temp->Coef>>temp->Expon;
        temp->Next = NULL;
        P->Next = temp;
        P = P->Next;
    }
    return Pfront;
}

void derivative(Polynomial P)  //多项式求导
{
    while(P->Next)
    {
        P = P->Next;
        if(P->Expon > 0)
        {
            P->Coef = P->Coef * P->Expon;
            P->Expon = P->Expon - 1;
            cout<<P->Coef<<" "<<P->Expon<<endl;
        }
    }
}

int main()
{
    cout<<"输入样例："<<endl;
    Polynomial P = CreatP();//创建链表表示多项式

    cout<<"输出样例："<<endl;
    derivative(P);          //求导并输出
    return 0;
}
/*
输入样例：
3   4
-5  2
6   1
-2  0
输出样例：
12  3
-10  1
6   0
*/
