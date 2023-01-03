//用快速排序对数据进行升序排列
#include<iostream>
using namespace std;

 //交换函数
void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//简单排序函数
void InsertionSort(int A[], int N)
{
    int P, i;
    int temp;
    for(P=1; P<N; P++)
    {
        temp = A[P];        //取出未排序元素中的第一个元素
        for(i=P; i>0&&A[i-1]>temp; i--)
            A[i] = A[i-1];  //依次与已排序序列中的元素比较并右移
        A[i] = temp;        //找到了合适的位置，放进去
    }
}

//确定主元函数
int Median3(int A[], int Left, int Right)
{
    int Center = (Left+Right)/2;
    if(A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if(A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if(A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);
    //此时已满足A[Left]<=A[Center]<=A[Right]

    Swap(&A[Center], &A[Right-1]);   //将基准Pivot藏到右边
    //只需要考虑A[Left+1]...A[Right-2]
    return A[Right-1];              //返回基准Pivot
}

//核心递归函数
void Qsort(int A[], int Left, int Right)
{
    int Pivot, Cutoff = 5;  //Cutoff为阈值
    int Low, High;

    if(Cutoff <= Right-Left)  //如果序列元素充分多，进入快速排序
    {
        Pivot = Median3(A, Left, Right);  //选基准
        Low = Left;
        High = Right -1;
        while(1)  //将序列中比基准小的移到基准左边，大的移到右边
        {
            while(A[++Low] < Pivot);
            while(A[--High] > Pivot);
            if(Low < High)
                Swap(&A[Low], &A[High]);
            else
                break;
        }
        Swap(&A[Low], &A[Right-1]);  //将基准换到正确的位置
        Qsort(A, Left, Low-1);       //递归解决左边
        Qsort(A, Low+1, Right);      //递归解决右边
    }
    else
        InsertionSort(A+Left, Right-Left+1);  //元素太少，用直接插入排序（简单排序）
}

int main()
{
    cout<<"输入样例："<<endl;
    int N;  //待排序的元素数
    cin>>N;
    int A[N];
    for(int i=0; i<N; i++)
        cin>>A[i];

    cout<<"输出样例："<<endl;
    Qsort(A, 0, N-1);  //调用快排函数
    for(int i=0; i<N; i++)
        cout<<A[i]<<" ";
    return 0;
}
/*
输入样例：
10
49 35 68 99 70 13 25 50 111 60
输出样例：
13 25 35 49 50 60 68 70 99 111
*/
