//Ï£¶ûÅÅÐò
#include <bits/stdc++.h>
using namespace std;

void ShellSort(int (&array)[13], int N);

int main(void)
{
    int array[13] = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};

    ShellSort(array, 13);
    for (int i = 0; i < 13; i++)
        cout << array[i] << " ";

    return 0;
}

void ShellSort(int (&array)[13], int N)
{
    int i, j, increment;
    int temp;

    for (increment = N / 2; increment > 0; increment /= 2)
        for (i = increment; i < N; i++)
        {
            temp = array[i];
            for (j = i; j >= increment; j -=increment)
                if (temp < array[j - increment])
                    array[j] = array[j - increment];
                else
                    break;
            array[j] = temp;
        }
}