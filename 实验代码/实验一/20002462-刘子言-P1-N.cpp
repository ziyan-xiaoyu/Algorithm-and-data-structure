//������ʽ�ṹ�洢һԪ����ʽ��������
#include<iostream>
using namespace std;

typedef struct PolyNode * PtrToPolyNode;
struct PolyNode{
    int Coef;//ϵ��
    int Expon;//ָ��
    PtrToPolyNode Next;
};
typedef PtrToPolyNode Polynomial;

Polynomial CreatP()  //���������ʾ����ʽ
{
    Polynomial P, Pfront, temp;

    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->Next = NULL;
    Pfront = P;     //��¼����ʽ����ͷ���

    for(int i=0;i<4;i++)  //�ٶ�����Ķ���ʽ��4��
    {
        temp = (Polynomial)malloc(sizeof(struct PolyNode));
        cin>>temp->Coef>>temp->Expon;
        temp->Next = NULL;
        P->Next = temp;
        P = P->Next;
    }
    return Pfront;
}

void derivative(Polynomial P)  //����ʽ��
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
    cout<<"����������"<<endl;
    Polynomial P = CreatP();//���������ʾ����ʽ

    cout<<"���������"<<endl;
    derivative(P);          //�󵼲����
    return 0;
}
/*
����������
3   4
-5  2
6   1
-2  0
���������
12  3
-10  1
6   0
*/
