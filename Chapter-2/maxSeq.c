//最大子列和
/*
2021.9.18总结一下今天的改bug经验：
    错误：
    1边界分不清楚，确定数组时从什么地方开始扫描的，二分查找也是，已经扫描过的地方就不要扫描了
    注意，数组下标时从0开始的
    2 看清楚ide联想的变量，不要输入错变量
*/
#include <stdio.h>
#define MAXIMUN 100000

int Solve1(int list[], int K);  //联机算法
int Solve2(int *list, int K);   //递归算法
int Max3(int a, int b, int c);  //三个数求最大值

int main(void)
{
    int K;
    int list[MAXIMUN];
    int i, j, k;

    //接受用户输入
    scanf("%d", &K);
    for (i = 0; i < K; i++)
        scanf("%d", &list[i]);

    //输出结果
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
    int maxLeftBorderSum, maxRightBorderSum;    //求中间开始的最大序列和
    int i;
    half = K / 2;
    
    //基准情形
    if (K == 1)
    {
        if (*list > 0)
            return *list;
        else  
            return 0;  
    }

    leftSum = Solve2(list, K / 2);
    rightSum = Solve2(&list[K / 2], K / 2);
    
    //求左边最大
    maxLeftBorderSum = leftBorderSum = 0;
    for (i = half - 1; i >= 0; i--)
    {
        leftBorderSum += list[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    if (maxLeftBorderSum < 0)
        maxLeftBorderSum = 0;

    //求右边最大
    maxRightBorderSum = rightBorderSum = 0;
    for (i = half; i < K; i++)
    {
        rightBorderSum += list[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    if (maxRightBorderSum < 0)
        maxRightBorderSum = 0;

    //中间最大
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