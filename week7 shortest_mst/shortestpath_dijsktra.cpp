#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairr;
priority_queue<pairr, vector<pairr>, greater<pairr>>  minheap; // popเอาตัวน้อย
//ให้firstเก็บdis, second เก็บnode
//จิงๆใช้set<pairr> แทนpqได้ เพราะเวลาใส่จะเรียงจากน้อยไปมากให้ เราก้แค่ใช้*(s.begin())ในการเข้าถึงตัวน้อยสุด

vector<pair<int, int>> g[111111];

int n,m;
int dis[111111];

void dijsktra()
{
    for(int i=0;i<=n;i++)
    {
        dis[i] = 1e9;
    }
    dis[1] = 0;
    minheap.push(make_pair(dis[1],1));
    while(!minheap.empty())
    {
        auto current = minheap.top();
        minheap.pop();
        for(auto it:g[current.second])
        {
            if(dis[it.first]>current.first+it.second)
            {
                dis[it.first] = current.first+it.second;
                minheap.push(make_pair(dis[it.first],it.first));
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].emplace_back(make_pair(b,w));
        g[b].emplace_back(make_pair(a,w));
    }
    dijsktra();
    cout << dis[n];
}