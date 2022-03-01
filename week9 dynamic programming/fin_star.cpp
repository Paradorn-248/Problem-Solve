#include <bits/stdc++.h>
using namespace std;

int dp[111111][3]; // 0:ไม่ซื้อ 1:cafe 2:bakery

int main()
{
    int n, cafe, bakery;
    cin >> n;
    cin >> cafe >> bakery;
    dp[0][0] = 0;
    dp[0][1] = cafe;
    dp[0][2] = bakery;
    // for (int k = 0; k < n; k++)
    // {
    //     for (int l = 0; l < 3; l++)
    //     {
    //         printf("%d ", dp[k][l]);
    //     }
    //     cout << endl;
    // }
    // cout << "======================" << endl;
    for (int i = 1; i < n; i++)
    {
        cin >> cafe >> bakery;
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + cafe;
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + bakery;
        // for (int k = 0; k < n; k++)
        // {
        //     for (int l = 0; l < 3; l++)
        //     {
        //         printf("%d ", dp[k][l]);
        //     }
        //     cout << endl;
        // }
        // cout << "======================" << endl;
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}