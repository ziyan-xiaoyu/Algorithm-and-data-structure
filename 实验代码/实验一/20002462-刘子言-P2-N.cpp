//��������������ϲ�Ϊһ����������
#include<iostream>
using namespace std;

typedef struct Node * PtrToNode;
struct Node{
    int Data;//����
    PtrToNode Next;
};
typedef PtrToNode List;

List CreatL()//��������
{
    List L, Lfront, temp;

    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    Lfront = L;//��¼����ͷ���

//����һ
    while(true)//�������ⳤ�ȵ�����
    {
        temp = (List)malloc(sizeof(struct Node));
        cin>>temp->Data;
        temp->Next = NULL;
        L->Next = temp;
        L = L->Next;
        if(getchar()!=' ')//�����س��������ٽӿո�ʱ������������������
            return Lfront;
    }
//������
//    for(int i=0;i<3;i++)//�ٶ�������Ϊ3���������forѭ�����������whileѭ��
//    {
//          temp = (List)malloc(sizeof(struct Node));
//          cin>>temp->Data;
//          temp->Next = NULL;
//          L->Next = temp;
//          L = L->Next;
//    }
//    return Lfront;//����ͷ���ָ��
}

void AddL(List L1, List L2)//�ϲ�����
{

    List L3 = L1;//���������L1������
    int d1, d2;
    L1 = L1->Next;
    L2 = L2->Next;

    while(L1&&L2)
    {
        if(L1->Data >= L2->Data)//L2��ֵƫС
        {
            L3->Next = L2;
            L3 = L3->Next;
            L2 = L2->Next;
        }
        else//L1��ֵƫС
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
    cout<<"����������"<<endl;
    List L1 = CreatL();//��������L1
    List L2 = CreatL();//��������L2
    List Lfront = L1;//��¼L1ͷ���

    cout<<"���������"<<endl;
    AddL(L1,L2);//�ϲ�L1��L2��L1

    while(Lfront->Next)//����ϲ�����������
    {
        Lfront = Lfront->Next;
        cout<<Lfront->Data<<" ";
    }

    return 0;
}
/*
���룺1 4 5
1 3 6
�����1 1 3 4 5 6
*/
