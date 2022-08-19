//������к�
/*
2021.9.18�ܽ�һ�½���ĸ�bug���飺
    ����
    1�߽�ֲ������ȷ������ʱ��ʲô�ط���ʼɨ��ģ����ֲ���Ҳ�ǣ��Ѿ�ɨ����ĵط��Ͳ�Ҫɨ����
    ע�⣬�����±�ʱ��0��ʼ��
    2 �����ide����ı�������Ҫ��������
*/
#include <stdio.h>
#define MAXIMUN 100000

int Solve1(int list[], int K);  //�����㷨
int Solve2(int *list, int K);   //�ݹ��㷨
int Max3(int a, int b, int c);  //�����������ֵ

int main(void)
{
    int K;
    int list[MAXIMUN];
    int i, j, k;

    //�����û�����
    scanf("%d", &K);
    for (i = 0; i < K; i++)
        scanf("%d", &list[i]);

    //������
    printf("%d", Solve2(list, K));
    return 0;
}

int Solve1(int list[], int K)
{
    int thisSum, maxSum;
    int i;

    maxSum = 0;
    thisSum = list[0];
    for (i = 1; i <= K; i++)
    {
        if (thisSum < 0)
            thisSum = 0;
        thisSum += list[i];
        if (thisSum > maxSum)
            maxSum = thisSum;
    }
    return maxSum;
}

int Solve2(int *list, int K)
{
    
    int maxSum, half;
    int leftSum, rightSum, midSum;
    int leftBorderSum, rightBorderSum;
    int maxLeftBorderSum, maxRightBorderSum;    //���м俪ʼ��������к�
    int i;
    half = K / 2;
    
    //��׼����
    if (K == 1)
    {
        if (*list > 0)
            return *list;
        else  
            return 0;  
    }

    leftSum = Solve2(list, K / 2);
    rightSum = Solve2(&list[K / 2], K / 2);
    
    //��������
    maxLeftBorderSum = leftBorderSum = 0;
    for (i = half - 1; i >= 0; i--)
    {
        leftBorderSum += list[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    if (maxLeftBorderSum < 0)
        maxLeftBorderSum = 0;

    //���ұ����
    maxRightBorderSum = rightBorderSum = 0;
    for (i = half; i < K; i++)
    {
        rightBorderSum += list[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    if (maxRightBorderSum < 0)
        maxRightBorderSum = 0;

    //�м����
    midSum = maxLeftBorderSum + maxRightBorderSum;

    return Max3(midSum, leftSum, rightSum);
}

int Max3(int a, int b, int c)
{
    int max;
    max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}