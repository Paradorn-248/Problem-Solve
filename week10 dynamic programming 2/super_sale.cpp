#include <bits/stdc++.h>
using namespace std;

int dp[1111][33], item[1111][2];
int t, n, ans = 0, g, mw;

int main()
{
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> item[i][0] >> item[i][1];
        }
        memset(dp, 0, sizeof(dp));
        ans = 0;
        cin >> g;
        for (int i = 0; i < g; i++)
        {
            cin >> mw;
            for (int j = 1; j <= n; j++)
            {
                for (int remain = 0; remain <= mw; remain++)
                {
                    if (item[j][1] <= remain)
                    {
                        dp[j][remain] = max(dp[j - 1][remain], dp[j - 1][remain - item[j][1]] + item[j][0]);
                    }
                    else
                    {
                        dp[j][remain] = dp[j - 1][remain];
                    }
                    // for (int k = 1; k <= n; k++)
                    // {
                    //     for (int l = 0; l <= mw; l++)
                    //     {
                    //         printf("%d ", dp[k][l]);
                    //     }
                    //     cout << endl;
                    // }
                    // cout << "======================" << endl;
                }
            }
            int maxx = 0;
            ans += dp[n][mw];

            for (int k = 1; k <= n; k++)
            {
                for (int l = 0; l <= mw; l++)
                {
                    printf("%d ", dp[k][l]);
                }
                cout << endl;
            }
            cout << "======================" << endl;
        }

        cout << ans << '\n';
    }
}