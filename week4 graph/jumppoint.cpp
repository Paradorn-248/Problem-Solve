#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[1005];
vector<int> graph[1005];
int n, r, weight = 1;
int d[1005];

// int ind(int f,int s)
// {
//     for(int i=0;i<=n+1;i++)
//         if(g[i].first==f&&g[i].second==s)
//             return i;
// }

void shortestpath()
{
    d[0] = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        d[i] = 1e9;
    }
    // index = ind(f,s);
    queue <int> q;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (d[v] > d[u] + weight)
            {
                d[v] = d[u] + weight;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r;
    g[0].emplace_back(make_pair(0, 0));
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[i].emplace_back(make_pair(x, y));
    }
    g[n + 1].emplace_back(make_pair(100, 100));
    // for(int i=0 ;i<=n;i++)
    // {
    //     for(int j=0;j<g[i].size();j++)
    //     {
    //         printf("(%d,%d) ",g[i][j].first,g[i][j].second);
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            if (i != j && pow(g[i][0].first - g[j][0].first, 2) + pow(g[i][0].second - g[j][0].second, 2) <= r * r)
                graph[i].emplace_back(j);
        }
    }
    // for(int i=0 ;i<=n+1;i++)
    // {
    //     for(int j=0;j<graph[i].size();j++)
    //     {
    //         printf("%d ",graph[i][j]);
    //     }
    //     printf("\n");
    // }
    shortestpath();
    // for(int i = 0;i<=n+1;i++)
    // {
    //     printf("%d ",d[i]);
    // }
    if(d[n+1]==1e9)
        cout << "-1";
    else
        cout << d[n+1];
}