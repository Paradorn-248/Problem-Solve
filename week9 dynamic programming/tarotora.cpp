#include <bits/stdc++.h>
using namespace std;
int dp[111111][222];

int C, n, k, taro, tora, start, endd;

int main()
{
    cin >> C;
    for (int p = 0; p < C; p++)
    {
        cin >> n >> k;
        start = 100 - k;
        endd = 100 + k;

        for (int i = 0; i <= n; i++)
        {
            for (int j = start - 1; j <= endd + 1; j++)
            {
                dp[i][j] = 1e9;
            }
        }
        dp[0][100] = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> taro >> tora;
            for (int j = start; j <= endd; j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1] + taro, dp[i - 1][j + 1] + tora);
            }
        }

        int ans = 1e9;
        for (int i = start; i <= endd; i++)
        {
            ans = min(ans, dp[n][i]);
        }
        cout << ans << '\n';
    }
    return 0;
}