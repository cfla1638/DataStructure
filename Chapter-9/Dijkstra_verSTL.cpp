#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

/*
static void debug_arr(array<int, 500> arr,string name, int size)
{
    cout << "---- "<< name <<" ----" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << name <<"[" << i <<"] = " << arr[i] << endl;
    }
    cout << endl;
}
*/

int main(void)
{
    int N, M, S, D;
    cin >> N >> M >> S >> D;

    vector<pair<int, vector<pair<int, int> > > > G;   //在vector中的顺序表示其城市编号，pair表示救援队的数目int以及快速路的信息pair<des, weight>


    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        G.push_back(pair<int, vector<pair<int, int> > >(num, vector<pair<int, int> >(0)));
    }

    for (int i = 0; i < M; i++)
    {
        int start, des, dist;
        cin >> start >> des >> dist;
        G[start].second.push_back(pair<int, int>(des, dist));
        G[des].second.push_back(pair<int, int>(start, dist));
    }

    //Dijkstra

    //配置
    //bool known[500] = {false};
    //int path[500];
    //int dist[500] = {inf};

    //memset(path, -1, sizeof(path)); //初始化path
    array<bool, 500> known;
    array<int, 500> path;
    array<int, 500> dist;

    known.fill(false);
    path.fill(-1);
    dist.fill(inf);

    dist[S] = 0;
    path[S] = -2;   //特殊标记源点的path
    auto cmp = [&](int a, int b) {return dist[a] > dist[b];};
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);

    //算法开始
    q.push(S);
    //cout << "q.push(" << S << ")" << endl;
    int minVertex;

    for (;;)
    {
        //找到最小的仍然未知的顶点
        minVertex = -1;
        while (!q.empty())              //当仍存在未知的顶点
        {
            if (known[q.top()])         //如果此顶点已知
            {    
                q.pop();
                //cout << "q.pop()" << endl;  
            }
            else
            {
                //debug_arr(dist, "dist", 7);
                //cout << "q.top():"<< q.top() << endl;
                minVertex = q.top();
                q.pop();
                //cout << "q.pop()" << endl;
                break;
            }
        }

        if (minVertex == -1)        //判断是否有剩余的顶点
            break;

        known[minVertex] = true;
        for (auto adj : G[minVertex].second)
        {
            if (!known[adj.first])
                if (dist[minVertex] + adj.second < dist[adj.first])
                {
                    dist[adj.first] = dist[minVertex] + adj.second;
                    path[adj.first] = minVertex;
                    q.push(adj.first);              //将更新过的顶点入堆
                    //cout << "q.push(" << adj.first << ")" << endl;
                }
        }
    }
    //算法结束

    //debug_arr(path, "path", 7);

    //回溯沿途结点
    stack<int> s;
    vector<int> ansSeq;
    int rescue = 0;      //救援队数量

    s.push(D);
    while (path[s.top()] != -2)
        s.push(path[s.top()]);

    int roadCount = s.size() - 1;   //快速路的数量
    while (!s.empty())
    {
        ansSeq.push_back(s.top());
        rescue += G[s.top()].first;
        s.pop();
    }
    rescue -= G[D].first;        //减去目的地的救援队数量

    //打印输出结果
    //cout << "output:" << endl;
    cout << roadCount << " " << rescue << endl;
    for (auto i = ansSeq.cbegin(); i != ansSeq.cend(); i++)
        if (i == ansSeq.cbegin())
            cout << *i;
        else
            cout << " " << *i;


    return 0;
}