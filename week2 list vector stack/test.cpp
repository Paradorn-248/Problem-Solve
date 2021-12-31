#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[125][125][2];
char s[125][125];

int dfs(int row, int col, int state)
{
  //
  if (dp[row][col][state] != -1)
    return dp[row][col][state];
  if (col == 0)
  {
    state = 1;
  }
  if (col == m - 1)
  {
    state = 0;
  }
  if (s[row][col] == '.')
    return dp[row][col][state] = dfs(row + 1, col, state);
  if (s[row][col] == '$')
    return dp[row][col][state] = 1;
  if (s[row][col] == '@')
    return dp[row][col][state] = 0;
  if(state==0)
    return dp[row][col][state] = dfs(row, col - 1, state);
  if(state==1)
    return dp[row][col][state] = dfs(row, col + 1, state);

}

int main()
{
  scanf("%d %d", &m, &n);
  for (int a = 0; a < n; a++)
  {
    scanf("%s", s[a]);
  }
  int cnt = 0, ans1 = 0, ans2 = 0;
  memset(dp, -1, sizeof(dp));
  for (int a = 0; a < m; a++)
  {
    cnt += dfs(0, a, 0);
    cnt += dfs(0, a, 1);
  }
  ans1 = cnt;
  for (int a = 0; a < n - 1; a++)
  {
    for (int b = 0; b < m; b++)
    {
      if (s[a][b] == '#')
      {
        s[a][b] = '.';
        cnt = 0;
        memset(dp, -1, sizeof(dp));
        for (int c = 0; c < m; c++)
        {
          cnt += dfs(0, c, 0);
          cnt += dfs(0, c, 2);
        }
        ans2 = max(ans2, cnt);
        s[a][b] = '#';
      }
    }
  }
  printf("%d %d", ans1, ans2);
  return 0;
}