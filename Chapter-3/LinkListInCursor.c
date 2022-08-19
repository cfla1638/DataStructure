//������α�ʵ��(��ͷ���)
#include <stdio.h>
#define SpaceSize 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    ElementType element;
    Position next;
};

//CursorSpace�����пռ����ʹ�ã�������һ����
struct Node CursorSpace[SpaceSize];

Status IntiCursorSpace(void);
static Position CursorAlloc(void);
static Status CursorFree(Position P);


List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position Find(ElementType X, const List L);
Status Delete(ElementType X, List L);
Position FindPrevious(ElementType X, const List L);
Status Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(const List L);
Position Advance(const Position P);
ElementType Retrieve(const Position P);
Status Traversal(const List L);
Status Add(ElementType X, List L);

int main(void)
{
    List L = 0;
    IntiCursorSpace();
    L = MakeEmpty(L);
    Add(1, L);
    Add(2, L);
    Add(3, L);
    Insert(4, L, FindPrevious(2, L));
    Traversal(L);

    return 0;
}

Status IntiCursorSpace(void)
{
    int i;

    for (i = 0; i < SpaceSize - 1; i++)
    {
        CursorSpace[i].next = i + 1; 
    }
    CursorSpace[SpaceSize - 1].next = 0;

    return OK;
}

static Position CursorAlloc(void)
{
    Position P;

    //��ȡ��һ��δ��ʹ�õĿռ䣬�����P
    P = CursorSpace[0].next;
    CursorSpace[0].next = CursorSpace[P].next;  //����ָ����һ��δ��ʹ�õĿռ�

    return P;   //������ֵΪ0ʱ����־�����޿ռ�ʹ��
}

static Status CursorFree(Position P)
{
    //��P��Ϊδʹ�ÿռ䲢��ʣ�µ�δʹ�ÿռ�
    CursorSpace[P].next = CursorSpace[0].next;  
    CursorSpace[0].next = P;
    return OK;
}

List MakeEmpty(List L)
{
    
    L = CursorAlloc();
    CursorSpace[L].next = 0;
    return L;
}

int IsEmpty(const List L)
{
    return CursorSpace[L].next == 0;
}

int IsLast(const Position P, const List L)
{
    Position temp;

    temp = L;
    while (CursorSpace[temp].next != P)
    {
        //�����λ�ò��ڱ����򷵻�-1
        if (CursorSpace[temp].next == 0)
            return -1;
        temp = CursorSpace[temp].next;
    }

    return CursorSpace[P].next == 0;
}

Position Find(ElementType X, const List L)
{
    //�ҵ�����Pos����֮����0
    Position P;

    P = CursorSpace[L].next;
    while (P && CursorSpace[P].element != X)
        P = CursorSpace[P].next;

    return P;
}

Status Delete(ElementType X, List L)
{
    Position P, TempCell;

    P = FindPrevious(X, L);

    if (!IsLast(P, L))
    {
        TempCell = CursorSpace[P].next;
        CursorSpace[P].next = CursorSpace[TempCell].next;
        CursorFree(TempCell);
    }
    else 
        return ERROR;

    return OK;
}

Position FindPrevious(ElementType X, const List L)
{
    Position Prev;

    Prev = L;
    while(CursorSpace[CursorSpace[Prev].next].element != X && CursorSpace[Prev].next)
    {
        Prev = CursorSpace[Prev].next;
    }

    return Prev;
}

Status Insert(ElementType X, List L, Position P)
{
    Position TempCell;

    TempCell = CursorAlloc();
    if (TempCell == 0)
    {
        printf("Error: out of space!\n");
        return ERROR;
    }

    CursorSpace[TempCell].element = X;
    CursorSpace[TempCell].next = CursorSpace[P].next;
    CursorSpace[P].next = TempCell;

    return OK;
}

Status Traversal(const List L)
{
    Position P = CursorSpace[L].next;
    while (P)
    {
        printf("%d ", CursorSpace[P].element);
        P = CursorSpace[P].next;
    }
    return OK;
}

Status Add(ElementType X, List L)
{
    Position P;
    P = CursorAlloc();

    CursorSpace[P].element = X;
    CursorSpace[P].next = CursorSpace[L].next;
    CursorSpace[L].next = P;
    
    return OK;
}