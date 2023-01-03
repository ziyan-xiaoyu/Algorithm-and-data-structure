//递归法求最大公因子

#include<iostream>
using namespace std;

int getGCD(int m,int n)
{
    int t,k;
    if(m<n)
    {
        t=m;m=n;n=t;
    }
    k=m%n;
    if(k==0)
        return n;
    else
    {
        m=n;
        n=k;
        return getGCD(m,n);
    }
}

int main()
{
    int x,y,GCD;
    cin>>x>>y;
    GCD=getGCD(x,y);
    cout<<"最大公因子是："<<GCD;

    return 0;
}
