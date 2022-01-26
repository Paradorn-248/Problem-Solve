#include <bits/stdc++.h>
using namespace std;

int indegree[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    vector<int> v[n+1];

    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].emplace_back(b);
        indegree[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    if(q.empty())
    {
        cout << "no";
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it = v[node].begin(); it != v[node].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
                q.push(*it);
        }   
        cout << node << '\n';
    }
}