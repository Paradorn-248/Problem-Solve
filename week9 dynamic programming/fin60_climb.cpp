#include <bits/stdc++.h>
using namespace std;

char mapp[111][111];
int dis[111][111];
int sx, sy, tx, ty, n, m;

int solve(int x, int y, int summ)
{
    // for (int k = 1; k <= n; k++)
    // {
    //     for (int l = 1; l <= m; l++)
    //     {
    //         cout << dis[k][l] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << "------------------------------------\n";
    if (dis[x][y] < summ)
        return 0;
    // up
    if (mapp[x - 1][y] != 'X' && dis[x - 1][y] > summ + 5)
    {

        dis[x - 1][y] = min(dis[x - 1][y], summ + 5);
        solve(x - 1, y, summ + 5);
    }
    // down
    if (mapp[x + 1][y] != 'X' && dis[x + 1][y] > summ)
    {

        dis[x + 1][y] = min(dis[x + 1][y], summ);
        solve(x + 1, y, summ);
    }
    // left
    if (mapp[x][y - 1] != 'X' && dis[x][y - 1] > summ + 1)
    {

        dis[x][y - 1] = min(dis[x][y - 1], summ + 1);
        solve(x, y - 1, summ + 1);
    }
    // right
    if (mapp[x][y + 1] != 'X' && dis[x][y + 1] > summ + 1)
    {
        dis[x][y + 1] = min(dis[x][y + 1], summ + 1);
        solve(x, y + 1, summ + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    sx = n, sy = 1, tx = 1, ty = m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mapp[i][j];
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int l = 1; l <= m; l++)
        {
            dis[k][l] = 1e9;
        }
    }
    int ans = 1e9;
    solve(sx, sy, 0);
    ans = dis[tx][ty];
    if (ans == 1e9)
        cout << "-1";
    else
        cout << ans;
}
