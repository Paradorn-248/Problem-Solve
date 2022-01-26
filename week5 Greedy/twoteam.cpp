#include <bits/stdc++.h>
using namespace std;

int color[111111];
int par[111111];
int g[111111];
vector<int> v[111111];

int findParent(int a)
{
    if (a == par[a])
    {
        return par[a] = a;
    }
    return par[a] = findParent(par[a]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, ans = 0, chk = 0, tmp = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        par[i] = i;
    }

    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
        int parA = findParent(a);
        int parB = findParent(b);

        if (color[a])
        {
            int tmp1 = a;
            a = b;
            b = tmp1;
        }

        if (color[a])
        {
            if (parA == parB)
            {
                if (color[a] == color[b])
                {
                    chk = 1;
                }
            }
            else if (color[a] == color[b])
            {
                tmp++;
                color[b] = 3 - color[a];
                queue<int> q;
                q.push(b);
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    g[u] = tmp;
                    for (int i = 0; i < v[u].size(); ++i)
                    {
                        color[v[u][i]] = 3 - color[u];
                        if (g[v[u][i]] == tmp)
                            q.push(v[u][i]);
                    }
                }
            }
        }
        else if (color[b])
        {
            color[a] = 3 - color[b];
        }
        else
        {
            color[a] = 1;
            color[b] = 2;
        }
        if (!chk)
            ans++;

        par[parB] = parA;
        parA = findParent(a);
        parB = findParent(b);
    }

    cout << ans;
}