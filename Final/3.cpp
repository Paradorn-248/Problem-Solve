#include <bits/stdc++.h>
using namespace std;
int n, m, k, ar[222][222], dp[222][222][222];

int solve(int r, int c, int k)
{
    if (r == n + 1 || c == 0 || c == m + 1) // เกินขอบเขต
        return 0;
    if (k > 0)
        return dp[r][c][k] = max(solve(r + 1, c, k) + ar[r][c], max(solve(r + 1, c + 1, k - 1) + ar[r][c], solve(r + 1, c - 1, k - 1) + ar[r][c]));
    return dp[r][c][k] = solve(r + 1, c, k) + ar[r][c];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ar[i][j];
        }
    }
    int ans = -1e9;
    for (int i = 1; i <= m; i++)
    {
        ans = max(ans, solve(1, i, k));
    }
    cout << ans;
}