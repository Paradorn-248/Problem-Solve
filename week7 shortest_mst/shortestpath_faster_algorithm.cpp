#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[111111];

int n, m, current, dis[111111];

void shortestpath_faster_algorithm()
{
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 1e9;
    }
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (auto it : g[current])
        {
            if (dis[it.first] > dis[current] + it.second)
            {
                dis[it.first] = dis[current] + it.second;
                q.push(it.first);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].emplace_back(make_pair(b, w));
        g[b].emplace_back(make_pair(a, w));
    }
    shortestpath_faster_algorithm();
    cout << dis[n];
}