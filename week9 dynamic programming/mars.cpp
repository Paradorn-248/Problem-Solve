#include <bits/stdc++.h>
using namespace std;

int dp[1111][60][60], len, n, ans, now;
string s;

int use(int start, int end)
{
    return min(abs(start - end), 26 - abs(start - end));
}

int main()
{
    cin >> n;
    for (int a = 0; a < n; a++)
    {
        ans = 1e9;
        cin >> s;
        len = s.size();
        for (int i = 0; i <= len; i++)
        {
            for (int j = 0; j <= 26; j++)
            {
                for (int k = 0; k <= 26; k++)
                {
                    dp[i][j][k] = 1e9;
                }
            }
        }
        dp[0][1][1] = 0;
        for (int i = 0; i < len; i++)
        {
            now = s[i] - 'A' + 1;
            for (int j = 1; j <= 26; j++)
            {
                for (int k = 1; k <= 26; k++)
                {
                    dp[i + 1][j][now] = min(dp[i + 1][j][now], dp[i][j][k] + use(k, now));
                    dp[i + 1][now][j] = min(dp[i + 1][now][j], dp[i][k][j] + use(k, now));
                }
            }
        }
        for (int i = 1; i <= 26; i++)
        {
            for (int j = 1; j <= 26; j++)
            {
                ans = min(ans, dp[len][i][j]);
            }
        }
        cout << ans << '\n';
    }
}