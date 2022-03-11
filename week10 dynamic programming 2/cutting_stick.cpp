#include <bits/stdc++.h>
using namespace std;

int l, dp[55][55], n, cut[55];

int solve(int start, int endd)
{
    if (endd - start == 1)
        return 0;
    if (dp[start][endd] != -1)
        return dp[start][endd];
    int high = 1e9;
    for (int mid = start + 1; mid < endd; mid++)
    {
        high = min(high, solve(start, mid) + solve(mid, endd) + cut[endd] - cut[start]);
    }
    return dp[start][endd] = high;
}

int main()
{
    while (1)
    {
        cin >> l;
        if (l == 0)
        {
            break;
        }
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> cut[i];
        }
        cut[n + 1] = l;
        printf("The minimum cutting is %d.\n", solve(0, n + 1));
    }
}