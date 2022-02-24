#include <bits/stdc++.h>
using namespace std;

char mapp[222][222];
int visit[222][222][2];
int sx, sy, tx, ty, ans = 0;

void solve(int x, int y, int key)
{
    visit[x][y][key] = 1;
    if (x == tx && y == ty)
    {
        ans = 1;
    }
    // up
    if (mapp[x - 1][y] != '#' && visit[x - 1][y][key] == 0)
    {
        if (mapp[x - 1][y] == 'O' && key == 0)
        {
            solve(x - 1, y, 1);
        }
        else if(mapp[x - 1][y] != 'O')
            solve(x - 1, y, key);
    }
    // down
    if (mapp[x + 1][y] != '#' && visit[x + 1][y][key] == 0)
    {
        if (mapp[x + 1][y] == 'O' && key == 0)
        {
            solve(x + 1, y, 1);
        }
        else if(mapp[x + 1][y] != 'O')
            solve(x + 1, y, key);
    }
    // left
    if (mapp[x][y - 1] != '#' && visit[x][y - 1][key] == 0)
    {
        if (mapp[x][y - 1] == 'O' && key == 0)
        {
            solve(x, y - 1, 1);
        }
        else if(mapp[x][y - 1] != 'O')
            solve(x, y - 1, key);
    }
    // right
    if (mapp[x][y + 1] != '#' && visit[x][y + 1][key] == 0)
    {
        if (mapp[x][y + 1] == 'O' && key == 0)
        {
            solve(x, y + 1, 1);
        }
        else if(mapp[x][y + 1] != 'O')
            solve(x, y + 1, key);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            mapp[i][j] = '#';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mapp[i][j];
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> sx >> sy >> tx >> ty;
        solve(sx, sy, 0);
        if (ans)
            cout << "yes\n";
        else
            cout << "no\n";
        ans = 0;
        for (int k = 0; k <= n + 1; k++)
        {
            for (int j = 0; j <= n + 1; j++)
            {
                for(int l=0;l<2;l++)
                    visit[k][j][l] = 0;
            }
        }
    }
}
