//LΪ˳���ɾ���±�i��j������Ԫ��

void Delete_i_j(List L, int i, int j)
{
    for(int k=1;k<=j-i+1;k++)
    {
        for(int t=i; t<L->last; t++)
            L->Data[t]=L->Data[t+1];
        L->Last--;
    }
}
