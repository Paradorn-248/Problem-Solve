#include <bits/stdc++.h>
using namespace std;
string mapp[35];
int ans = 0, n, m, visit[35][35];

void dfs(int x, int y)
{
    // printf("x:%d y:%d\n", x, y);
    visit[x][y] = 1;
    if (x == n - 2)
    {
        ans = 1;
        return;
    }
    // if (y == m - 2)
    // {
    //     // go left
    //     if (y - 1 >= 0 && visit[x][y - 1] == 0)
    //     {
    //         if (mapp[x][y - 1] != '#' && mapp[x + 1][y - 1] != '#')
    //             dfs(x, y - 1);
    //     }
    //     // go down
    //     if (x + 2 < n && visit[x + 1][y] == 0)
    //     {
    //         if (mapp[x + 2][y] != '#' && mapp[x + 2][y + 1] != '#')
    //             dfs(x + 1, y);
    //     }
    //     // go up
    //     if (x - 1 >= 0 && visit[x - 1][y] == 0)
    //     {
    //         dfs(x - 1, y);
    //     }
    // }
    // else
    // {
        // go left
        if (y - 1 >= 0 && visit[x][y - 1] == 0)
        {
            if (mapp[x][y - 1] != '#' && mapp[x + 1][y - 1] != '#')
                dfs(x, y - 1);
        }
        // go right
        if (y + 2 <= m && visit[x][y + 1] == 0)
        {
            if (mapp[x][y + 2] != '#' && mapp[x + 1][y + 2] != '#')
                dfs(x, y + 1);
        }
        // go down
        if (x + 2 < n && visit[x + 1][y] == 0)
        {
            if (mapp[x + 2][y] != '#' && mapp[x + 2][y + 1] != '#')
                dfs(x + 1, y);
        }
        // go up
        if (x - 1 >= 0 && visit[x - 1][y] == 0)
        {
            if (mapp[x - 1][y] != '#' && mapp[x - 1][y + 1] != '#')
                dfs(x - 1, y);
        }
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    //ทำถึงแค่n-1,m-1
    for (int i = 0; i < n; i++)
    {
        cin >> mapp[i];
    }
    for (int i = 0; i < m - 1; i++)
    {
        if (mapp[0][i] != '#' && mapp[0][i + 1] != '#' && mapp[1][i] != '#' && mapp[1][i + 1] != '#' && visit[0][i] == 0)
        {
            dfs(0, i);
            if (ans == 1)
            {
                cout << "yes";
                return 0;
            }
        }
    }
    cout << "no";
}