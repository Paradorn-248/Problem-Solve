#include <bits/stdc++.h>
#include "traffic.h"
using namespace std;

int n, k, ans[10], nub = 0;

void bsearch(int a1, int b1, int a2, int b2)
{
    if (a2 - a1 == 1 || b2 - b1 == 1)
    {
        ans[nub] = a1;
        nub++;
        ans[nub] = b1;
        nub++;
        ans[nub] = a2;
        nub++;
        ans[nub] = b2;
        nub++;
        return;
    }
    int mid1 = a1 + (a2 - a1) / 2;
    int mid2 = b1 + (b2 - b1) / 2;
    if (traffic_query(a1, b1, mid1, mid2) != abs(a1 - mid1) + abs(b1 - mid2))
    {
        bsearch(a1, b1, mid1, mid2);
    }
    if (traffic_query(mid1, mid2, a2, b2) != abs(a2 - mid1) + abs(b2 - mid2))
    {
        bsearch(mid1, mid2, a2, b2);
    }
}

int main()
{
    traffic_init(&n, &k);

    for (int i = 1; i <= n; i++)
    {
        // for (int i = 0; i <= 7; i++)
        // {
        //     cout << ans[i] << ' ';
        // }
        // cout << "\n1\n";
        if (ans[7] != 0)
        {
            break;
        }
        if (traffic_query(i, 1, i, n) > n - 1)
        {
            bsearch(i, 1, i, n);
        }
    }
    // cout << "----\n";
    for (int i = 1; i <= n; i++)
    {
        // for (int i = 0; i <= 7; i++)
        // {
        //     cout << ans[i] << ' ';
        // }
        // cout << "\n1\n";
        if (ans[7] != 0)
        {
            break;
        }
        if (traffic_query(1, i, n, i) > n - 1)
        {
            bsearch(1, i, n, i);
        }
    }

    traffic_report(ans[0], ans[1], ans[2], ans[3], ans[4], ans[5], ans[6], ans[7]);
}