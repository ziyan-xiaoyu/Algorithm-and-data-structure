//给定两个两个单链表L1、L2，找出它们的公共结点，并返回

#define ERROR NULL    //用空地址表示错误

Position Find_L1_L2(List L1, List L2)
{
    Position p1=L1;
    Position p2=L2;
    Position p_same[maxsize];//将公共结点的地址都存在这个指针数组中，maxsize预设，尽量足够大
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
