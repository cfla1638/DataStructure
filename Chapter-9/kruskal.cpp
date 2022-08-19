#include <bits/stdc++.h>
using namespace std;
//²¢²é¼¯
#define MAX_N 1000
int Rank[MAX_N];
int par[MAX_N];

void inti(int n)
{
    for (int i = 0; i < n; i++)
    {
        Rank[i] = 0;
        par[i] = i;
    }
}

int find(int x)
{
    if (par[x] = x)
        return x;
    else
        return par[x] = find(x);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return ;
    if (Rank[x] < Rank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (Rank[x] == Rank[y])
            Rank[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}


int main(void)
{
    inti(100);

    return 0;
}