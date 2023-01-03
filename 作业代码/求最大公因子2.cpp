//辗转相除法求最大公因子

#include<iostream>
using namespace std;

void getGCD(int m,int n)
{
    int t,k;
    if(m<n)
    {
        t=m;m=n;n=t;
    }
    do
    {
        k=m%n;
        m=n;
        n=k;
    }while(n>0);
    cout<<"最大公因子是："<<m;
}

int main()
{
    int x,y;
    cin>>x>>y;
    getGCD(x,y);

    return 0;
}
