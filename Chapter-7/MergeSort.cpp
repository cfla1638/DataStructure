//归并排序
#include <bits/stdc++.h>
using namespace std;
typedef int ElementType;

//归并排序
void MergeSort(ElementType A[], int N);

static void MSort(ElementType A[], ElementType tempArray[], int left, int right);
//合并两个数组
static void Merge(ElementType A[], ElementType tempArray[], int leftPos, int rightPos, \
int rightEnd);

int main(void)
{
    int A[10] = {5, 6, 2, 10, 66, 3, 58, 100, 54, 87};

    MergeSort(A, 10);

    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";

    return 0;
}

void MergeSort(ElementType A[], int N)
{
    ElementType *tempArray = NULL;

    //为临时数组分配空间
    tempArray = (ElementType*)malloc(N * sizeof(ElementType));

    if (tempArray != NULL)
    {
        //从头排到尾
        MSort(A, tempArray, 0, N - 1);
        free(tempArray);    //释放临时数组的空间
    }
    else
        cout << "Out of space!" << endl;
}

static void MSort(ElementType A[], ElementType tempArray[], int left, int right)
{
    int center;     //中间位置

    if (left < right)   //一定不能是<=,不然函数会卡在这里
    {
        center = (left + right) / 2;
        MSort(A, tempArray, left, center);      //递归地对左半部分进行分组（分）
        MSort(A, tempArray, center + 1, right); //递归地对右半部分进行分组（分）
        Merge(A, tempArray, left, center + 1, right);   //合并左右两部分数组，并同时进行排序（治）
    }
}

static void Merge(ElementType A[], ElementType tempArray[], int leftPos, int rightPos, \
int rightEnd)       //leftPos指左半部分的起始点，rightPos同理，rightEnd指右半部分的最后一个元素的坐标
{
    //从左到右依次是 左半部分的最后一个元素的位置、所有数组元素的个数、第三个（临时）数组的下标
    int leftEnd, elementCount, tempPos;

    leftEnd = rightPos - 1;
    tempPos = leftPos;      //从左边开始，便于最后一步把临时数组的元素拷贝回原数组
    elementCount = rightEnd - leftPos + 1;

    //主循环，负责把两个数组按大小升序合并
    while (leftPos <= leftEnd && rightPos <= rightEnd)
        if (A[leftPos] <= A[rightPos])
            tempArray[tempPos++] = A[leftPos++];
        else
            tempArray[tempPos++] = A[rightPos++];
    
    //将左右部分剩余的元素放到第三个数组的最后
    while (leftPos <= leftEnd)
        tempArray[tempPos++] = A[leftPos++];
    while (rightPos <= rightEnd)
        tempArray[tempPos++] = A[rightPos++];

    //将临时数组的元素拷贝回原数组
    for (int i = 0; i < elementCount; i++, rightEnd--)
        A[rightEnd] = tempArray[rightEnd];
}