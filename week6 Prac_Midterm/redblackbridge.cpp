#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[222222];
int dis1[222222],dis2[222222];

void bfs(int s,int t,int color,int dis[])
{
    for(int i=1;i<=200000;i++)
    {
        dis[i] = 1e9;
    }
    dis[s] = 0;

    queue<int> q;
    q.push(s);
    int status=0;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int i=0;i<v[current].size();i++)
        {
            int a = v[current][i].first;
            // cout << a << ' ';
            if(v[current][i].second == 3-color)
            {
                // if (status == 0)
                //     status = 1;
                // else
                //     continue;
                continue;
            }
            if(dis[current]+1 < dis[a])
            {    
                dis[a] = dis[current]+1;
                q.push(a);
            }
        }
        // cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,s,t;
    cin >> n >> m >> s >> t;
    int a,b,c; //c=1 red , c=2 black
    
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        v[a].emplace_back(make_pair(b,c));
        v[b].emplace_back(make_pair(a,c));
    }
    bfs(s,t,1,dis1);
    bfs(s,t,2,dis2);
    int ans = min(dis1[t],dis2[t]);
    if(ans==1e9)
        cout << "-1" ;
    else
        cout << ans;
}

