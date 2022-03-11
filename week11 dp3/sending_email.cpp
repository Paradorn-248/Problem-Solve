#include <bits/stdc++.h>
using namespace std;

int dis[111111], n, m, s, t;
vector<pair<int, int>> v[111111];

void shortest_path(int s)
{
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 1e9;
    }
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < v[current].size(); i++)
        {
            auto a = v[current][i];
            if (dis[current] + a.second < dis[a.first])
            {
                dis[a.first] = dis[current] + a.second;
                q.push(a.first);
            }
        }
    }
}

int main()
{
    int a, b, c, N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> n >> m >> s >> t;
        for (int j = 0; j < m; j++)
        {
            cin >> a >> b >> c;
            v[a].emplace_back(make_pair(b, c));
            v[b].emplace_back(make_pair(a, c));
        }
        shortest_path(s);
        // cout << "==== ";
        // for (int i = 0; i <= n; i++)
        // {
        //     cout << dis[i] << ' ';
        // }
        // cout << endl;
        if (dis[t] == 1e9)
        {
            printf("Case #%d: unreachable\n", i);
        }
        else
        {
            printf("Case #%d: %d\n", i, dis[t]);
        }
        for(int i=0;i<n;i++)
        {
            v[i].clear();
        }
    }
}