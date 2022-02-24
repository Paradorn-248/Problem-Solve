#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> g[111111];

typedef tuple<int, int, int> tuplee;
priority_queue<tuplee, vector<tuplee>, greater<tuplee>>  minheap; // popเอาตัวน้อย
//ให้0เก็บnode, 1เก็บweight, 2เก็บทางด่วน

//จิงๆใช้set<pairr> แทนpqได้ เพราะเวลาใส่จะเรียงจากน้อยไปมากให้ เราก้แค่ใช้*(s.begin())ในการเข้าถึงตัวน้อยสุด

int n,m;
int dis[111111][2];

void dijsktra()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            dis[i][j] = 1e9;
    }
    dis[1][0] = 0;
    minheap.push(make_tuple(dis[1][0],1,0));
    while(!minheap.empty())
    {
        auto current = minheap.top();
        minheap.pop();
        for(auto next:g[get<1>(current)])
        {
            if(get<2>(current)==1 && get<2>(next) == 1)
            { 
                continue;
            }
            int tmp = get<2>(current);
            if(get<2>(next)==1)
            {
                tmp = 1;
            }
            if(dis[get<0>(next)][tmp] > get<0>(current) + get<1>(next))
            {
                dis[get<0>(next)][tmp] = get<0>(current) + get<1>(next);
                minheap.push(make_tuple(dis[get<0>(next)][tmp],get<0>(next),tmp));
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c ,s;
        cin >> a >> b >> c >> s;
        g[a].emplace_back(make_tuple(b,c,s));
        g[b].emplace_back(make_tuple(a,c,s));
    }
    dijsktra();
    int ans = min(dis[n][0],dis[n][1]);
    if(ans==1e9)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}