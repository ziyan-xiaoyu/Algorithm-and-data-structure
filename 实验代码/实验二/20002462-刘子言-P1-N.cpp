//�ж����ö������Ƿ�ͬ��
#include<iostream>
#include <string.h>
using namespace std;

struct TNode{
    char data;   //��������Ϊ�ַ�
    int left;    //���Ӷ�Ӧ���
    int right;  //�Һ��Ӷ�Ӧ���
};
TNode BT1[50],BT2[50];    //������������ö�����
int flag = 0;            //�ж��������Ƿ�ͬ����=0Ŀǰͬ����=1��ͬ��

//�������Һ��ӽ��ı���ҵ����ҽ���data��������
//���޺��ӽ���-1����Ϊ�ַ���0����������ֱ�ӱȽ�
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

//�Ƚ���������ͬ�Ľ������Һ��ӽ���data�Ƿ����
void compare(char L1, char R1, char L2, char R2)
{
    if(L1 == L2)        //1��=2��
    {
        if(R1 != R2)    //1��!=2��
            flag = 1;
    }
    else if(L1 == R2)  //1��=2��
    {
        if(R1 != L2)    //1��!=2��
            flag = 1;
    }
    else               //1���2�����Ҷ�����
        flag = 1;
}

int main()
{
    int N1,N2;         //�ֱ�Ϊ�������Ľڵ���

    cout<<"����������"<<endl;
    //����BT1
    cin>>N1;
    for(int i=0;i<N1;i++)
        cin>>BT1[i].data>>BT1[i].left>>BT1[i].right;
    //����BT2
    cin>>N2;
    for(int i=0;i<N2;i++)
        cin>>BT2[i].data>>BT2[i].left>>BT2[i].right;
    if(N1!=N2) flag = 1;//��������ȿ϶���ͬ��

    if(flag == 0)      //����������ͬ�������ж�
    {
        for(int i=0;i<N1;i++)
        {
            int j=0;
            for(j=0;j<N2;j++)
            {
                if(BT1[i].data == BT2[j].data)//�ҵ���BT2����BT1[i]��Ӧ�Ľ��data
                {
                    //�Ƚ������������Һ��ӽ���data
                    compare(getBT1_childData(BT1[i].left), getBT1_childData(BT1[i].right), getBT2_childData(BT2[j].left) , getBT2_childData(BT2[j].right));
                    break;
                }
            }
            if(j==N2 || flag)//���BT2��û��BT1[i]��Ӧ���Ǹ����,�����Ѿ�����flagΪ1�ˣ��ͽ���ѭ��
            {
                flag = 1;
                break;
            }
        }
    }

    cout<<"���������"<<endl;
    if(flag)
        cout<<"False"<<endl;
    else
        cout<<"True"<<endl;
    return 0;
}
/*
��������
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
