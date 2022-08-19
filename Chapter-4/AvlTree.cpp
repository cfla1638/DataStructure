//AVL树的C语言实现
#include <bits/stdc++.h>
using namespace std;
typedef int ElementType;                //树的结点元素类型

struct AvlNode;                         //树的结点
typedef struct AvlNode *Position;       //树的结点指针
typedef struct AvlNode *AvlTree;        //Avl树类型

//方法
AvlTree MakeEmpty(AvlTree T);           //清空Avl树
Position Find(ElementType X, AvlTree);  //查找
Position FindMin(AvlTree T);            //查找最大元素
Position FindMax(AvlTree T);            //查找最小元素
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);
void MidTraversal(AvlTree T);           //中序遍历

//辅助函数
static int Height(Position P);
static AvlTree SingleRotateWithLeft(Position K2);    //左单旋转
static AvlTree DoubleRotateWithLeft(Position K3);    //左双旋转
static AvlTree SingleRotateWithRight(AvlTree T);   //右单旋转
static AvlTree DoubleRotateWithRight(AvlTree T);   //右双旋转
static int Max(int num1, int num2);

struct AvlNode
{
    ElementType element;
    AvlTree left;                       //左子树
    AvlTree right;                      //右子树
    int height;                         //高度
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
    //static静态链接，只能再本翻译单元内被调用
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
        //创造一个新节点
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
            //如果左右子树的高度差等于2，AVL树的平衡被打破
            if (X < T->left->element)
                //情况1，插入在树的左子树的左子树
                T = SingleRotateWithLeft(T);    //左单旋
            else
                //情况2，插入在树的左子树的右子树
                T = DoubleRotateWithLeft(T);
        }
    }
    else 
    if (X > T->element)
    {
        T->right = Insert(X, T->right);
        if (Height(T->right) - Height(T->left) == 2)
            if (X > T->right->element)
                //情况3：插入在树的右子树的右子树
                T = SingleRotateWithRight(T);
            else
                //情况4：插入在树的右子树的左子树
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
    //K2为根节点，K1是将要被旋转到根节点上的结点。
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
        printf("%d", T->element);   //与ElementType相对应
        MidTraversal(T->right);
    }
}