#include <bits/stdc++.h>
using namespace std;

string s[122];
int w, h;
int memm[122][122][2];

int dfs(int row, int col, int state)
{
    // state: 0=left, 1=right
    // mem: -1=initial, 0=@, 1=$
    if (memm[row][col][state] != -1)
    {
        return memm[row][col][state];
    }
    if (col == w - 1)
    {
        state = 0;
    }
    else if (col == 0)
    {
        state = 1;
    }
    if (s[row][col] == '.')
    {
        return memm[row][col][state] = dfs(row + 1, col, state);
    }
    if (s[row][col] == '@')
    {
        return memm[row][col][state] = 0;
    }
    if (s[row][col] == '$')
    {
        return memm[row][col][state] = 1;
    }
    if (state == 0)
    {
        return memm[row][col][state] = dfs(row, col - 1, state);
    }
    if (state == 1)
    {
        return memm[row][col][state] = dfs(row, col + 1, state);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ans1 = 0, ans2 = 0, tmp = 0;
    cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    memset(memm, -1, sizeof(memm));
    for (int i = 0; i < w; i++)
    {
        ans1 += dfs(0, i, 1); // go right first
        ans1 += dfs(0, i, 0); // go left first
    }
    cout << ans1 << ' ';
    for (int i = 0; i < h - 1; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
            {
                s[i][j] = '.';
                memset(memm, -1, sizeof(memm));
                for (int k = 0; k < w; k++)
                {
                    tmp += dfs(0, k, 1); // go right first
                    tmp += dfs(0, k, 0); // go left first
                }
                s[i][j] = '#';
                ans2 = max(tmp, ans2);
                tmp = 0;
            }
        }
    }
    cout << ans2;
}