#include <bits/stdc++.h>
using namespace std;

int c[555555], h[111111], ans[111111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, curmax = 0, maxlong=0;
    cin >> m;
    h[0] = 0;
    for (int i = 1; i <= m + 1; i++)
    {
        if(i!=m+1)
        {
            cin >> h[i];
            // cout << h[i - 1] << endl;
            curmax = max(curmax, h[i]);
            // cout << curmax << endl;
        }
        if (h[i] == 0)
        {
            // cout << 1;
            for (int j = 1; j <= curmax; j++)
            {
                ans[c[j]]++;
                maxlong = max(maxlong,c[j]);
                c[j] = 0;
            }
            curmax = 0;
        }
        if (h[i] >= h[i - 1])
        {
            // cout << 2;
            for (int j = 1; j <= h[i]; j++)
            {
                c[j]++;
            }
        }
        if (h[i] < h[i - 1])
        {
            // cout << 3;
            for (int j = 1; j <= h[i]; j++)
            {
                c[j]++;
            }
            for (int j = h[i] + 1; j <= h[i - 1]; j++)
            {
                ans[c[j]]++;
                maxlong = max(maxlong,c[j]);
                c[j] = 0;
            }
        }
        // cout << "a ";
        // for (int i = 1; i <= 10; i++)
        // {
        //     cout << i << '-' << ans[i] << ' ';
        // }
        // cout << "\nc ";
        // for (int i = 1; i <= 10; i++)
        // {
        //     cout << i << '-' << c[i] << ' ';
        // }

        // cout << "\n--------\n";
    }
    // cout << 4;
    // cout << maxlong << '\n';
    int p=0;
    for (int i = 1; i <= maxlong; i++)
    {
        if (ans[i] != 0)
            p++;
    }
    cout << p << '\n';
    for (int i = 1; i <= maxlong; i++)
    {
        if (ans[i] != 0)
            cout << i << ' ' << ans[i] << '\n';
    }
}