//利用四种排序方法进行升序排序
#include<iostream>
using namespace std;

void PercDown(int A[], int p, int N)  //将N个元素的数组中，以A[p]为根的子堆调整为最大堆
{
    int Parent, Child;
    int X;
    X = A[p];  //取出根结点存放的值
    for(Parent = p; (2*Parent+1)<N; Parent = Child)
    {
        Child = 2*Parent+1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;               //Child指向左右子结点中的较大者
        if(X >= A[Child]) break;  //即找到了合适的位置
        else
            A[Parent] = A[Child];  //下滤
    }
    A[Parent] = X;
}

void Swap(int *a, int *b)  //交换两个元素的函数
{
    int t = *a;
    *a = *b;
    *b = t;
}

void HeapSort(int A[], int N)  //堆排序
{
    int i;
    for(i=N/2-1; i>=0; i--)  //建立最大堆
        PercDown(A, i, N);
    for(i=N-1; i>0; i--)
    {
        Swap(&A[0], &A[i]);  //将根结点与最后一个结点交换
        PercDown(A, 0, i);   //将新的堆重新调整为最大堆
    }
}

void BubbleSort(int A[], int N)  //冒泡排序
{
    int P, i;
    bool flag;
    for(P=N-1; P>=0; P--)
    {
        flag = false;       //标记该次循环中是否发生交换，若无，则说明整个序列有序
        for(i=0; i<P; i++)  //此为一趟冒泡
        {                   //每次循环找出一个最大元素，被交换到最右端
            if(A[i]>A[i+1])
            {
                Swap(&A[i], &A[i+1]);
                flag = true;  //标记发生了交换
            }
        }
        if(flag == false) break;    //若全程无交换，则跳出循环
    }
}

void InsertionSort(int A[], int N)  //直接插入排序
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

void ShellSort(int A[], int N)  //希尔排序
{
    int Si, D, P, i;
    int temp;
    int Sedgewick[] = {5, 3, 1, 0};  //列出一部分增量
    for(Si=0; Sedgewick[Si]>=N; Si++)
        ;  //初始的增量Sedgewick[Si]不能超过待排序的序列长度N
    for(D=Sedgewick[Si]; D>0; D=Sedgewick[++Si])
        for(P=D; P<N; P++)  //插入序列
        {
            temp = A[P];
            for(i=P; i>=D && A[i-D]>temp; i-=D)
                A[i] = A[i-D];
            A[i] = temp;
        }
}

int main()
{
    cout<<"输入样例："<<endl;
    int Numb;//选择的算法编号
    int N;//待排序元素的个数
    cin>>Numb;
    cin>>N;
    int A[N];
    for(int i=0; i<N; i++)
        cin>>A[i];

    cout<<"输出样例："<<endl;
    switch(Numb)
    {
        case 1:  //堆排序
            HeapSort(A, N);
            break;
        case 2:  //冒泡排序
            BubbleSort(A, N);
            break;
        case 3:  //直接插入排序
            InsertionSort(A, N);
            break;
        case 4:  //希尔排序
            ShellSort(A, N);
            break;
        default: break;
    }
    for(int i=0; i<N; i++)
        cout<<A[i]<<" ";
    return 0;
}
/*
输入样例：
1
12
57 40 38 11 13 34 48 75 6 19 9 7
*/

