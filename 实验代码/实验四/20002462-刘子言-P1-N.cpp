//�����������򷽷�������������
#include<iostream>
using namespace std;

void PercDown(int A[], int p, int N)  //��N��Ԫ�ص������У���A[p]Ϊ�����Ӷѵ���Ϊ����
{
    int Parent, Child;
    int X;
    X = A[p];  //ȡ��������ŵ�ֵ
    for(Parent = p; (2*Parent+1)<N; Parent = Child)
    {
        Child = 2*Parent+1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;               //Childָ�������ӽ���еĽϴ���
        if(X >= A[Child]) break;  //���ҵ��˺��ʵ�λ��
        else
            A[Parent] = A[Child];  //����
    }
    A[Parent] = X;
}

void Swap(int *a, int *b)  //��������Ԫ�صĺ���
{
    int t = *a;
    *a = *b;
    *b = t;
}

void HeapSort(int A[], int N)  //������
{
    int i;
    for(i=N/2-1; i>=0; i--)  //��������
        PercDown(A, i, N);
    for(i=N-1; i>0; i--)
    {
        Swap(&A[0], &A[i]);  //������������һ����㽻��
        PercDown(A, 0, i);   //���µĶ����µ���Ϊ����
    }
}

void BubbleSort(int A[], int N)  //ð������
{
    int P, i;
    bool flag;
    for(P=N-1; P>=0; P--)
    {
        flag = false;       //��Ǹô�ѭ�����Ƿ������������ޣ���˵��������������
        for(i=0; i<P; i++)  //��Ϊһ��ð��
        {                   //ÿ��ѭ���ҳ�һ�����Ԫ�أ������������Ҷ�
            if(A[i]>A[i+1])
            {
                Swap(&A[i], &A[i+1]);
                flag = true;  //��Ƿ����˽���
            }
        }
        if(flag == false) break;    //��ȫ���޽�����������ѭ��
    }
}

void InsertionSort(int A[], int N)  //ֱ�Ӳ�������
{
    int P, i;
    int temp;
    for(P=1; P<N; P++)
    {
        temp = A[P];        //ȡ��δ����Ԫ���еĵ�һ��Ԫ��
        for(i=P; i>0&&A[i-1]>temp; i--)
            A[i] = A[i-1];  //�����������������е�Ԫ�رȽϲ�����
        A[i] = temp;        //�ҵ��˺��ʵ�λ�ã��Ž�ȥ
    }
}

void ShellSort(int A[], int N)  //ϣ������
{
    int Si, D, P, i;
    int temp;
    int Sedgewick[] = {5, 3, 1, 0};  //�г�һ��������
    for(Si=0; Sedgewick[Si]>=N; Si++)
        ;  //��ʼ������Sedgewick[Si]���ܳ�������������г���N
    for(D=Sedgewick[Si]; D>0; D=Sedgewick[++Si])
        for(P=D; P<N; P++)  //��������
        {
            temp = A[P];
            for(i=P; i>=D && A[i-D]>temp; i-=D)
                A[i] = A[i-D];
            A[i] = temp;
        }
}

int main()
{
    cout<<"����������"<<endl;
    int Numb;//ѡ����㷨���
    int N;//������Ԫ�صĸ���
    cin>>Numb;
    cin>>N;
    int A[N];
    for(int i=0; i<N; i++)
        cin>>A[i];

    cout<<"���������"<<endl;
    switch(Numb)
    {
        case 1:  //������
            HeapSort(A, N);
            break;
        case 2:  //ð������
            BubbleSort(A, N);
            break;
        case 3:  //ֱ�Ӳ�������
            InsertionSort(A, N);
            break;
        case 4:  //ϣ������
            ShellSort(A, N);
            break;
        default: break;
    }
    for(int i=0; i<N; i++)
        cout<<A[i]<<" ";
    return 0;
}
/*
����������
1
12
57 40 38 11 13 34 48 75 6 19 9 7
*/

