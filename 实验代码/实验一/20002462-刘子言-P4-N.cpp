//������е�Ԫ�ظ������Լ������е�Ԫ��
//��������Ԫ�ش�С��������
#include<iostream>
#include<queue>
#include<string>
using namespace std;

queue<int>q;

void sort_q(queue<int>q, int n)//����
{
    int a,b,c,t;
    for(int i=0; i<n-1 ; i++)
    {
        a=q.front();
        q.pop();
        for(int j=0; j<n-1-i; j++)
        {
            b=q.front();
            q.pop();
            if(a<b)
            {
                q.push(a);
                a=b;
            }
            else
                q.push(b);
        }
        q.push(a);
        for(int k=0; k<i; k++)
        {
            c=q.front();
            q.pop();
            q.push(c);
        }
    }

    for(int i=0; i<n; i++) //���
    {
        t=q.front();
        q.pop();
        cout<<t<<" ";
    }
}

int main()
{
    int n;
    int k;
    cout<<"����������"<<endl;
    cin>>n;
    for(int i=0; i<n; i++) //����
    {
        cin>>k;
        q.push(k);
    }
    cout<<"���������"<<endl;
    sort_q(q,n);            //���������

    return 0;
}
/*
����������10
9 4 6 1 8 3 7 0 2 5
���������
0   1   2  3  4  5  6  7  8   9
*/
