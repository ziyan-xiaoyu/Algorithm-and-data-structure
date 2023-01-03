//求n个数据中的最大值

#include<iostream>
using namespace std;

void getMax(int n,float num[])
{
    float n_max=num[0];
    for(int i=1;i<n;i++)
    {
        if(num[i]>n_max)n_max=num[i];
    }
    cout<<"这n个数据中的最大值为："<<n_max;
}

int main()
{
    int N;
    cout<<"请输入数据的个数 n=";
    cin>>N;
    float a[N];
    cout<<"请输入这n个数据："<<endl;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    getMax(N,a);

    return 0;
}

//该算法的时间复杂度为：T(n)=O(n)
