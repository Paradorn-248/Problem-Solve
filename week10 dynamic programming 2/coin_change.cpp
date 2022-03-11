#include <bits/stdc++.h>
using namespace std;

int dp[7890][5];

int main()
{
    int coin[5] = {1, 5, 10, 25, 50};
    for (int i = 0; i < 5; i++)
    {
        dp[0][i] = 1;
        for (int j = 1; j < 7490; j++)
        {
            dp[j][i] = dp[j][i - 1];
            if (j >= coin[i])
            {
                dp[j][i] += dp[j - coin[i]][i];
            }
        }
    }
    // for (int k = 0; k <= 100; k++)
    // {
    //     for (int l = 0; l < 5; l++)
    //     {
    //         printf("%d ", dp[k][l]);
    //     }
    //     cout << endl;
    // }
    // cout << "======================" << endl;
    int want;
    while (cin >> want)
    {
        cout << dp[want][4] << '\n';
    }
}