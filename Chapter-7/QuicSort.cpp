//�������򣬻���������ֵ�ָ�
//8 1 4 9 0 3 5 2 7 6
//i               j pivot
//2 1 4 9 0 3 5 8 7 6
//i             j   pivot
//2 1 4 5 0 3 9 8 7 6
//      i     j     pivot
//2 1 4 5 0 3 9 8 7 6
//          j i     pivot
//2 1 4 5 0 3 6 8 7 9
//��һ��QSort
//2 1 4 5 0 3
//��֧һ���ڶ���Qsort
//2 1 4 5 0 3�ָ�
//2 1 4 5 0 3
//i       j pivot
//2 1 0 5 4 3
//    i   j pivot
//2 1 0 5 4 3
//    j i   p
//2 1 0 5 4 3
//2 1 0 3 4 5
//      pivot & i
//insertSort
//0 1 2 3 4 5
//8 7 9
//��֧������������
//7 8 9
/*
��¼����ʱ�̣�
������һ���ϵĿ��������㷨������֣����Լ�֮ǰ͵������������ֱ������֮ǰ�������д��
���������ܶԲ���ʵ������
*/
#include <bits/stdc++.h>
#define Cutoff (3)
using namespace std;
typedef int ElementType;

void QuickSort(ElementType A[], int N);

static void QSort(ElementType A[], int Left, int Right);
static ElementType Median3(ElementType A[], int Left, int Right);
static void Swap(ElementType *, ElementType *);
static void InsertSort(ElementType array[], int Left, int Right);

static void DebugShowArray(ElementType Array[], int n);

int main(void)
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    QuickSort(arr, 10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}

void QuickSort(ElementType A[], int N)
{
    QSort(A, 0, N - 1);
}

static ElementType Median3(ElementType A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;

    //�������ǵ��Լ����ڵ�λ��
    if (A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if (A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if (A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);

    Swap(&A[Center], &A[Right - 1]);
    return A[Right - 1];
}

static void QSort(ElementType A[], int Left, int Right)
{
    int i, j;
    ElementType pivot;

    DebugShowArray(A, 10);  //Debug

    if (Left + Cutoff <= Right)      //ȷ�����п����������������������
    {
        pivot = Median3(A, Left, Right);

        DebugShowArray(A, 10);  //Debug

        i = Left; j = Right - 1;
        for (;;)
        {
            while (A[++i] < pivot){}
            while (A[--j] > pivot){}
            if (i < j)
                Swap(&A[i], &A[j]);
            else 
                break;

            DebugShowArray(A, 10);  //Debug
        }
        Swap(&A[i], &A[Right - 1]);

        DebugShowArray(A, 10);  //Debug
        QSort(A, Left, i - 1);
        QSort(A, i + 1, Right);
    }
    else
    {
        InsertSort(A, Left, Right);
        DebugShowArray(A, 10);  //Debug
    }


}

static void Swap(ElementType *a, ElementType *b)
{
    ElementType temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

static void InsertSort(ElementType array[], int Left, int Right)
{
    for (; Left + 1 <= Right; Left++)
    {
        int i = Left + 1;
        int Elem = array[i];

        while (array[i - 1] > array[i] && i - 1 >= 0)
        {
            array[i] = array[i - 1];
        }
        array[i - 1] = Elem;
    }
}

static void DebugShowArray(ElementType A[], int n)
{
    cout << "  num:" << "\t";
    for (int i = 0; i < n; i++)
        cout << i << "\t";
    cout << endl << "array:\t";
    for (int i = 0; i < n; i++)
        cout << A[i] << "\t";
    cout << endl << endl;
}