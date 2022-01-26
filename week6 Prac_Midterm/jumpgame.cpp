#include<bits/stdc++.h>
using namespace std;

int m[1000][1000];
int visit[1000][1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,power;
    cin >> n >> power;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> m[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(1,1));
    int chk = 0;
    while(!q.empty())
    {
        pair<int,int> pairr = q.front();
        q.pop();
        int x = pairr.first;
        int y = pairr.second;
        if(visit[x][y]==1)
        {
            continue;
        }
        visit[x][y] = 1;
        if(x==n&&y==n)
        {
            chk = 1;
            break;
        }
        //up
        if(m[x-1][y] != 0 && m[x-1][y] - m[x][y] <= power)
        {
            q.push(make_pair(x-1,y));
        }
        //down
        if(m[x+1][y] != 0 && m[x+1][y] - m[x][y] <= power)
        {
            q.push(make_pair(x+1,y));
        }
        //left
        if(m[x][y-1] != 0 && m[x][y-1] - m[x][y] <= power)
        {
            q.push(make_pair(x,y-1));
        }
        //right
        if(m[x][y+1] != 0 && m[x][y+1] - m[x][y] <= power)
        {
            q.push(make_pair(x,y+1));
        }
    }
    if(chk)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}