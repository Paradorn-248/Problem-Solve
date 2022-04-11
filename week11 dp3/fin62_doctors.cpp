#include <bits/stdc++.h>
using namespace std;

int dis[111111], arr[111111], n;
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
    int m, l, ans = 0, tmp;
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].emplace_back(make_pair(b,c));
        v[b].emplace_back(make_pair(a,c));
    }

    shortest_path(1);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dis[i] << ' ';
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++)
    {
        tmp = min(l, arr[i-1]);
        ans += tmp * dis[i];
    }
    cout << ans << '\n';
}