//堆排序
//1 3 7 15 完全二叉树的前n层的节点数之和，其规律为2n+1，因此buildHeap可以从N/2的地方开始执行
#include <bits/stdc++.h>
#define LeftChild(i) (2 * (i) + 1)
using namespace std;

typedef int ElementType;

void PercDown(ElementType A[], int i, int N);   //下滤函数，i代表结点位置，N代表堆容量
void HeapSort(ElementType A[], int N);

static void Swap(ElementType *a, ElementType *b);

int main(void)
{
    int arr[7] = {97, 53, 59, 26, 41, 58, 31};
    HeapSort(arr, 7);

    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";

    return 0;
}

void PercDown(ElementType A[], int i, int N)
{
    int child;
    ElementType temp;

    for (temp = A[i]; LeftChild(i) < N; i = child)
    {
        child = LeftChild(i);
        if (child != N - 1 && A[child + 1] > A[child])      //child始终是两个孩子中较大的一个孩子
            child++;       
        if (temp < A[child])
            A[i] = A[child];
        else 
            break;
    }
    A[i] = temp;    //此时temp记录的是A[child]，即交换A[i]和A[child];
}

void HeapSort(ElementType A[], int N)
{
    int i;

    for (int i = N / 2; i >= 0; i--)
        PercDown(A, i, N);
    for (i = N - 1; i > 0; i--)
    {
        Swap(&A[0], &A[i]);
        PercDown(A, 0, i);          //容量逐渐减少
    }
}

static void Swap(ElementType *a, ElementType *b)
{
    ElementType temp;
    temp = *a;
    *a = *b; 
    *b = temp;
}