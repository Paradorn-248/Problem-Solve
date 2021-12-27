#include <bits/stdc++.h>
using namespace std;

vector<int> v[100010];
int color[100010]; // 1แดง 2เขียว

int isbipartite()
{
    queue<int> q;
    q.push(1);
    color[1] = 1;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (auto i = 0; i < v[head].size(); i++)
        {
            if (color[v[head][i]] == 0)
            {
                if (color[head] == 1)
                    color[v[head][i]] = 2;
                if (color[head] == 2)
                    color[v[head][i]] = 1;
                q.push(v[head][i]);
            }
            else
            {
                if (color[head] == color[v[head][i]])
                    return 0;
            }
            
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ng;
    cin >> ng;
    for (int a = 0; a < ng; a++)
    {
        int n, m, d1, d2;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> d1 >> d2;
            v[d1].emplace_back(d2);
            v[d2].emplace_back(d1);
        }
        if (isbipartite())
        {
            cout << "yes" << "\n";
        }
        else
        {
            cout << "no" << "\n";
        }
        for(int i=1;i<=n;i++)
        {
            color[i] = 0;
            v[i].clear();
        }
    }
}