//������������������L1��L2���ҳ����ǵĹ�����㣬������

#define ERROR NULL    //�ÿյ�ַ��ʾ����

Position Find_L1_L2(List L1, List L2)
{
    Position p1=L1;
    Position p2=L2;
    Position p_same[maxsize];//���������ĵ�ַ���������ָ�������У�maxsizeԤ�裬�����㹻��
    i=0;

    while(p1)
    {
        p2=L2;
        while(p2)
        {
            if(p1==p2)
            {
                p_same[i]=p1;
                i++;
            }
            else
                p2=p2->Next;
        }
        p1=p1->Next;
    }

    p_same[i]=p1;
    return p_same;
}
