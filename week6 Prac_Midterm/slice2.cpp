#include <bits/stdc++.h>
using namespace std;

int s[555555], ans[111111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, prev = 0;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int h;
        cin >> h;

        for (int j = h + 1; j <= prev; j++)
        {
            ans[i - s[j]]++;
        }
        for (int j = prev + 1; j <= h; j++)
        {
            s[j] = i;
        }
        prev = h;

        if (i == m)
        {
            for (int j = 1; j <= h; j++)
            {
                ans[i - s[j] + 1]++;
            }
        }
    }
    int p = 0;
    for (int i = 1; i <= 111110; i++)
    {
        if (ans[i] > 0)
            p++;
    }
    cout << p << '\n';
    for (int i = 1; i <= 111110; i++)
    {
        if (ans[i] > 0)
            cout << i << " " << ans[i] << '\n';
    }
}