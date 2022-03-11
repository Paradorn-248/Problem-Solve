#include <bits/stdc++.h>
using namespace std;

int dp[333][333];

int main()
{
    string x, y;
    cin >> x;
    cin >> y;

    int n = x.size();
    int m = y.size();

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }

    // for (int k = 0; k <= n; k++)
    // {
    //     for (int l = 0; l <= m; l++)
    //     {
    //         printf("%d ", dp[k][l]);
    //     }
    //     cout << endl;
    // }
    // cout << "======================" << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }

            // for (int k = 0; k <= n; k++)
            // {
            //     for (int l = 0; l <= m; l++)
            //     {
            //         printf("%d ", dp[k][l]);
            //     }
            //     cout << endl;
            // }
            // cout << "======================" << endl;
        }
    }
    cout << dp[n][m];
}
