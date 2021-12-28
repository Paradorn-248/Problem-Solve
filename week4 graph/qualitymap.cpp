#include <bits/stdc++.h>
using namespace std;

string mapp[35];
int visit[35][35], n, m;
int state=0; // 0คือไม่เจอไร 1คือเจอป่า* 2คือเจอแร่$

void dfs(int x, int y)
{
    // printf("x:%d y:%d state:%d\n");
    if (state == 3)
        return;
    visit[x][y] = 1;
    if (mapp[x][y] == '#')
        return;
    else if (mapp[x][y] == '*' && state == 0)
        state = 1;
    else if (mapp[x][y] == '$' && state == 0)
        state = 2;
    else if ((mapp[x][y] == '$' && state == 1) || (mapp[x][y] == '*' && state == 2))
    {
        state = 3;
        return;
    }
    // go left
    if (x - 1 >= 0 && visit[x - 1][y] == 0)
    {
        dfs(x - 1, y);
    }
    // go right
    if (x + 1 < n && visit[x + 1][y] == 0)
    {
        dfs(x + 1, y);
    }
    // go up
    if (y - 1 >= 0 && visit[x][y - 1] == 0)
    {
        dfs(x, y - 1);
    }
    // go down
    if (y + 1 < m && visit[x][y + 1] == 0)
    {
        dfs(x, y + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a1 = 0, a2 = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> mapp[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dfs(i, j);
            if (state == 1 || state == 2)
                a1 += 1;
            else if (state == 3)
                a2 += 1;
            // clear visit=0 && state=0
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    visit[i][j] = 0;
                }
            }
            state = 0;
        }
    }
    cout << a2 << ' ' << a1;
}