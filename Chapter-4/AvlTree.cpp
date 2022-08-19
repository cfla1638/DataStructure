//AVL����C����ʵ��
#include <bits/stdc++.h>
using namespace std;
typedef int ElementType;                //���Ľ��Ԫ������

struct AvlNode;                         //���Ľ��
typedef struct AvlNode *Position;       //���Ľ��ָ��
typedef struct AvlNode *AvlTree;        //Avl������

//����
AvlTree MakeEmpty(AvlTree T);           //���Avl��
Position Find(ElementType X, AvlTree);  //����
Position FindMin(AvlTree T);            //�������Ԫ��
Position FindMax(AvlTree T);            //������СԪ��
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);
void MidTraversal(AvlTree T);           //�������

//��������
static int Height(Position P);
static AvlTree SingleRotateWithLeft(Position K2);    //����ת
static AvlTree DoubleRotateWithLeft(Position K3);    //��˫��ת
static AvlTree SingleRotateWithRight(AvlTree T);   //�ҵ���ת
static AvlTree DoubleRotateWithRight(AvlTree T);   //��˫��ת
static int Max(int num1, int num2);

struct AvlNode
{
    ElementType element;
    AvlTree left;                       //������
    AvlTree right;                      //������
    int height;                         //�߶�
};


int main(void)
{
    AvlTree T;

    MakeEmpty(T);
    T = Insert(8, T);
    T = Insert(2, T);
    T = Insert(3, T);
    T = Insert(4, T);
    T = Insert(5, T);
    T = Insert(6, T);
    MidTraversal(T);

    return 0;
}

static int Height(Position P)
{
    //static��̬���ӣ�ֻ���ٱ����뵥Ԫ�ڱ�����
    if (P == NULL)
        return -1;
    else
        return P->height;
}

AvlTree MakeEmpty(AvlTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
        T = NULL;
    }
    return T;
}


AvlTree Insert(ElementType X, AvlTree T)
{
    if (T == NULL)
    {
        //����һ���½ڵ�
        T = (AvlNode*)malloc(sizeof(struct AvlNode));
        if (T == NULL)
        {
            printf("Out of space!\n");
            return 0;
        }
        else
        {
            T->element = X;
            T->height = 0;
            T->left = T->right = NULL;
        }
    }
    else
    if (X < T->element)
    {
        T->left = Insert(X, T->left);
        if (Height(T->left) - Height(T->right) == 2)
        {
            //������������ĸ߶Ȳ����2��AVL����ƽ�ⱻ����
            if (X < T->left->element)
                //���1��������������������������
                T = SingleRotateWithLeft(T);    //����
            else
                //���2��������������������������
                T = DoubleRotateWithLeft(T);
        }
    }
    else 
    if (X > T->element)
    {
        T->right = Insert(X, T->right);
        if (Height(T->right) - Height(T->left) == 2)
            if (X > T->right->element)
                //���3��������������������������
                T = SingleRotateWithRight(T);
            else
                //���4��������������������������
                T = DoubleRotateWithRight(T);
    }

    T->height = Max(Height(T->left), Height(T->right)) + 1;
    return T;
}

static int Max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

static AvlTree SingleRotateWithLeft(Position K2)
{   
    //K2Ϊ���ڵ㣬K1�ǽ�Ҫ����ת�����ڵ��ϵĽ�㡣
    Position K1;

    K1 = K2->left;
    K2->left = K1->right;
    K1->right = K2;

    K2->height = Max(Height(K2->left), Height(K2->right)) + 1;
    K1->height = Max(Height(K1->left), Height(K1->right)) + 1;

    return K1;
}

static AvlTree DoubleRotateWithLeft(Position K3)
{
    K3->left =  SingleRotateWithRight(K3->left);
    return SingleRotateWithLeft(K3);
}

static AvlTree SingleRotateWithRight(Position K2)
{
    Position K1;

    K1 = K2->right;
    K2->right = K1->left;
    K1->left = K2;

    K2->height = Max(Height(K2->left), Height(K2->right)) + 1;
    K1->height = Max(Height(K1->left), Height(K1->right)) + 1;

    return K1;
}

static AvlTree DoubleRotateWithRight(Position K3)
{
    K3->right = SingleRotateWithLeft(K3->right);
    return SingleRotateWithRight(K3);
}

void MidTraversal(AvlTree T)
{
    if (T != NULL)
    {
        MidTraversal(T->left);
        printf("%d", T->element);   //��ElementType���Ӧ
        MidTraversal(T->right);
    }
}