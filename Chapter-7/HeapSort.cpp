//������
//1 3 7 15 ��ȫ��������ǰn��Ľڵ���֮�ͣ������Ϊ2n+1�����buildHeap���Դ�N/2�ĵط���ʼִ��
#include <bits/stdc++.h>
#define LeftChild(i) (2 * (i) + 1)
using namespace std;

typedef int ElementType;

void PercDown(ElementType A[], int i, int N);   //���˺�����i������λ�ã�N���������
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
        if (child != N - 1 && A[child + 1] > A[child])      //childʼ�������������нϴ��һ������
            child++;       
        if (temp < A[child])
            A[i] = A[child];
        else 
            break;
    }
    A[i] = temp;    //��ʱtemp��¼����A[child]��������A[i]��A[child];
}

void HeapSort(ElementType A[], int N)
{
    int i;

    for (int i = N / 2; i >= 0; i--)
        PercDown(A, i, N);
    for (i = N - 1; i > 0; i--)
    {
        Swap(&A[0], &A[i]);
        PercDown(A, 0, i);          //�����𽥼���
    }
}

static void Swap(ElementType *a, ElementType *b)
{
    ElementType temp;
    temp = *a;
    *a = *b; 
    *b = temp;
}