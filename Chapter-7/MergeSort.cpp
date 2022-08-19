//�鲢����
#include <bits/stdc++.h>
using namespace std;
typedef int ElementType;

//�鲢����
void MergeSort(ElementType A[], int N);

static void MSort(ElementType A[], ElementType tempArray[], int left, int right);
//�ϲ���������
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

    //Ϊ��ʱ�������ռ�
    tempArray = (ElementType*)malloc(N * sizeof(ElementType));

    if (tempArray != NULL)
    {
        //��ͷ�ŵ�β
        MSort(A, tempArray, 0, N - 1);
        free(tempArray);    //�ͷ���ʱ����Ŀռ�
    }
    else
        cout << "Out of space!" << endl;
}

static void MSort(ElementType A[], ElementType tempArray[], int left, int right)
{
    int center;     //�м�λ��

    if (left < right)   //һ��������<=,��Ȼ�����Ῠ������
    {
        center = (left + right) / 2;
        MSort(A, tempArray, left, center);      //�ݹ�ض���벿�ֽ��з��飨�֣�
        MSort(A, tempArray, center + 1, right); //�ݹ�ض��Ұ벿�ֽ��з��飨�֣�
        Merge(A, tempArray, left, center + 1, right);   //�ϲ��������������飬��ͬʱ���������Σ�
    }
}

static void Merge(ElementType A[], ElementType tempArray[], int leftPos, int rightPos, \
int rightEnd)       //leftPosָ��벿�ֵ���ʼ�㣬rightPosͬ��rightEndָ�Ұ벿�ֵ����һ��Ԫ�ص�����
{
    //������������ ��벿�ֵ����һ��Ԫ�ص�λ�á���������Ԫ�صĸ���������������ʱ��������±�
    int leftEnd, elementCount, tempPos;

    leftEnd = rightPos - 1;
    tempPos = leftPos;      //����߿�ʼ���������һ������ʱ�����Ԫ�ؿ�����ԭ����
    elementCount = rightEnd - leftPos + 1;

    //��ѭ����������������鰴��С����ϲ�
    while (leftPos <= leftEnd && rightPos <= rightEnd)
        if (A[leftPos] <= A[rightPos])
            tempArray[tempPos++] = A[leftPos++];
        else
            tempArray[tempPos++] = A[rightPos++];
    
    //�����Ҳ���ʣ���Ԫ�طŵ���������������
    while (leftPos <= leftEnd)
        tempArray[tempPos++] = A[leftPos++];
    while (rightPos <= rightEnd)
        tempArray[tempPos++] = A[rightPos++];

    //����ʱ�����Ԫ�ؿ�����ԭ����
    for (int i = 0; i < elementCount; i++, rightEnd--)
        A[rightEnd] = tempArray[rightEnd];
}