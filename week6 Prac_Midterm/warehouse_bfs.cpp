#include <bits/stdc++.h>
using namespace std;

vector<int> v[222222];
int visit[222222];

int bfs(int s,int t)
{
    queue<int> q;
    q.push(s);
    visit[s] = 1;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(int i=0;i<v[top].size();i++)
        {
            if(visit[v[top][i]])
                continue;
            visit[v[top][i]] = 1;
            if(v[top][i]==t) 
                return 1;
            q.push(v[top][i]);
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k,a,b;
    cin >> n >> m >> k;
    for(int i = 0; i < m ;i++)
    {
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for(int i=0;i<k;i++)
    {
        cin >> a >> b;
        cout << bfs(a,b) << '\n';
        for(int j=0;j<=n;j++)
            visit[j] = 0;
    }
}