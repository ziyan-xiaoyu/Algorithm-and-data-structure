//Ѱ�����Ƚڵ㲢���
#include<iostream>
#include <math.h>
using namespace std;

struct Node{
    int data;   //��������Ϊ����
    int num;    //�ڵ���
    int floor;  //��¼�����������Ĳ���
};
Node BT[50];                  //��������Ķ�����
int i=0;                //���Ľڵ���

void Ancestors(Node BT[], int a, int b)//��BT��Ѱ��a,b��(�����)��������
{
    Node x,y;
    x.data = a;
    y.data = b;
    for(int j=0;j<i;j++)//���ҵ�a,b�����е�λ��
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

    while(x.data != y.data)//��ͨ�����¶��ϱȽϸ��ڵ�ķ�ʽѰ����������Ƚڵ�
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
    cout<<"����������"<<endl;
    while(true)
    {
        cin>>BT[i].data;//����
        BT[i].num = i+1;//���
        BT[i].floor = int(log(BT[i].num)/log(2))+1;//����
        i++;
        if(getchar()!=' ')//�����س����������ǿո�ʱ���������
            break;
    }
    int a,b;              //��¼�����ӽڵ���
    cin>>a;
    cin>>b;

    cout<<"���������"<<endl;
    Ancestors(BT, a, b);       //��BT��Ѱ��a,b��(�����)��������
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
