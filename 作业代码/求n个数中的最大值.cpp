//��n�������е����ֵ

#include<iostream>
using namespace std;

void getMax(int n,float num[])
{
    float n_max=num[0];
    for(int i=1;i<n;i++)
    {
        if(num[i]>n_max)n_max=num[i];
    }
    cout<<"��n�������е����ֵΪ��"<<n_max;
}

int main()
{
    int N;
    cout<<"���������ݵĸ��� n=";
    cin>>N;
    float a[N];
    cout<<"��������n�����ݣ�"<<endl;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    getMax(N,a);

    return 0;
}

//���㷨��ʱ�临�Ӷ�Ϊ��T(n)=O(n)
