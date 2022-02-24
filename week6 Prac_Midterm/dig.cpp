#include <bits/stdc++.h>
using namespace std;

char mapp[2222][2222];
int dis[5555][5555];
int sx, sy, tx, ty,n,m;

int solve(int x, int y, int summ)
{
    for (int k = 1; k <= n; k++)
    {
        for (int l = 1; l <= m; l++)
        {
            cout << dis[k][l] << ' ';
        }
        cout << endl;
    }
    cout << "------------------------------------\n";
    if (dis[x][y] < summ)
        return 0;
    // up
    if (mapp[x - 1][y] != '#' && dis[x - 1][y] > summ + 1)
    {
        if (mapp[x - 1][y] == '.')
        {
            dis[x - 1][y] = min(dis[x - 1][y], summ + 1);
            solve(x - 1, y, summ + 1);
        }
        else if (mapp[x - 2][y] == '.' && mapp[x - 1][y] == '|')
        {
            dis[x - 2][y] = min(dis[x - 2][y], summ + 2);
            solve(x - 2, y, summ + 2);
        }
    }
    // down
    if (mapp[x + 1][y] != '#' && dis[x + 1][y] > summ + 1)
    {
        if (mapp[x + 1][y] == '.')
        {
            dis[x + 1][y] = min(dis[x + 1][y], summ + 1);
            solve(x + 1, y, summ + 1);
        }
        else if (mapp[x + 2][y] == '.' && mapp[x + 1][y] == '|')
        {
            dis[x + 2][y] = min(dis[x + 2][y], summ + 2);
            solve(x + 2, y, summ + 2);
        }
    }
    // left
    if (mapp[x][y - 1] != '#' && dis[x][y - 1] > summ + 1)
    {
        if (mapp[x][y - 1] == '.')
        {
            dis[x][y - 1] = min(dis[x][y - 1], summ + 1);
            solve(x, y - 1, summ + 1);
        }
        else if (mapp[x][y - 2] == '.' && mapp[x][y - 1] == '-')
        {
            dis[x][y - 2] = min(dis[x][y - 2], summ + 2);
            solve(x, y - 2, summ + 2);
        }
    }
    // right
    if (mapp[x][y + 1] != '#' && dis[x][y + 1] > summ + 1)
    {
        if (mapp[x][y + 1] == '.')
        {
            dis[x][y + 1] = min(dis[x][y + 1], summ + 1);
            solve(x, y + 1, summ + 1);
        }
        else if (mapp[x][y + 2] == '.' && mapp[x][y + 1] == '-')
        {
            dis[x][y + 2] = min(dis[x][y + 2], summ + 2);
            solve(x, y + 2, summ + 2);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> sx >> sy >> tx >> ty;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mapp[i][j];
        }
    }

    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mapp[i][j] == '*')
            {
                mapp[i][j] = '|';
                for (int k = 1; k <= n; k++)
                {
                    for (int l = 1; l <= m; l++)
                    {
                        dis[k][l] = 1e9;
                    }
                }
                solve(sx, sy, 0);
                ans = min(ans, dis[tx][ty]);

                mapp[i][j] = '-';
                for (int k = 1; k <= n; k++)
                {
                    for (int l = 1; l <= m; l++)
                    {
                        dis[k][l] = 1e9;
                    }
                }
                solve(sx, sy, 0);
                ans = min(ans, dis[tx][ty]);

                mapp[i][j] = '*';
            }
        }
    }
    if(ans==1e9)
        cout << "-1";
    else 
        cout << ans;
}
