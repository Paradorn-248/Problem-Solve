#include <bits/stdc++.h>
using namespace std;

vector<int> v[100010];
int visit[100010];

void dfs(int ind)
{
    for(int i=0;i<v[ind].size();i++)
    {
        if(visit[v[ind][i]]==0)
        {
            visit[v[ind][i]] = 1;
            dfs(v[ind][i]);
        }
    } 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, ans=0;
    cin >> n >> m;
    int d1, d2;
    for (int i = 0; i < m; i++)
    {
        cin >> d1 >> d2;
        v[d1].emplace_back(d2);
        v[d2].emplace_back(d1);
    }
    // for(int i=1;i<=n;i++)
    // {
    //     if(v[i].size()!=0)
    //     for(auto it=v[i].begin();it!=v[i].begin()+v[i].size();it++)
    //     {
    //         cout << *it << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++)
    {
        if(visit[i]==0)
        {
            dfs(i);
            ans++;
        }
    }
    cout << ans;
}