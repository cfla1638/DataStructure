//PrimÀ„∑®
#include <bits/stdc++.h>
using namespace std;

typedef int Vertex;
vector<pair<Vertex, int>> G[100];
const int inf = 1e9+7;
bool known[100];
int dist[100];
Vertex path[100];

void inti()
{
    memset(path, -1, sizeof(path));
    for (int i = 0; i < 100; i++)
    {
        dist[i] = inf;
    }
}

void Prim()
{
    auto cmp = [](Vertex a, Vertex b){return dist[a] > dist[b];};
    priority_queue<Vertex, vector<Vertex>, decltype(cmp)> heap(cmp);
    dist[0] = 0;
    heap.push(0);

    for(;;)
    {
        Vertex minVertex = -1;

        while (!heap.empty())
        {
            if (known[heap.top()])
                heap.pop();
            else
            {
                minVertex = heap.top();
                heap.pop();
                break;
            }
        }

        if (minVertex == -1)
            break;

        known[minVertex] = true;
        for (auto adj : G[minVertex])
        {
            if (!known[adj.first])
                if (dist[adj.first] > adj.second)
                {
                    dist[adj.first] = adj.second;
                    path[adj.first] = minVertex;
                    heap.push(adj.first);
                }
        }
    }
}

int main(void)
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        Vertex u, v, weight;
        cin >> u >> v >> weight;
        G[u].push_back(pair<Vertex, int>(v, weight));
        G[v].push_back(pair<Vertex, int>(u, weight));
    }
    
    inti();
    Prim();

    for (auto i : path)
        cout << i << " ";

    return 0;
}

/*
7 12
0 1 2
0 2 4
0 3 1
1 3 3
1 4 10
2 3 2
3 4 7
2 5 5
3 5 8
3 6 4
4 6 6
5 6 1
*/