#include<bits/stdc++.h>
using namespace std;

vector<int> v[222222];
queue<pair<int,int>> q;
int visit[222222];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,s,t,start,stop;
    cin >> n >> m >> s >> t;
    for(int i=1;i<=m;i++)
    {
        cin >> start >> stop;
        v[start].emplace_back(stop);
        v[stop].emplace_back(start);
    }
    int l;
    for(int i=0;i<=222221;i++)
    {
        visit[i] = -1;
    }
    for(int i=1;i<=s;i++)
    {
        cin >> l;
        q.push(make_pair(l,0));
        visit[l] = 0;
    }
    int current,next;
    while(!q.empty())
    {
        current = q.front().first;
        next = q.front().second;
        q.pop();
        for(int it=0;it<v[current].size();it++)
        {
            if(visit[v[current][it]]!=-1)
                continue;
            visit[v[current][it]] = next+1;
            q.push({v[current][it],next+1});
        }
    }
    int want;
    for(int i=1;i<=t;i++)
    {
        cin >> want;
        cout << visit[want] << '\n';
    }
}