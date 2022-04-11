#include <bits/stdc++.h>
using namespace std;

int par[111111], ranks[111111], bud[111111];

int findParent(int a)
{
    if (a == par[a])
    {
        return par[a] = a;
    }
    return par[a] = findParent(par[a]);
}

int unions(int a, int b)
{
    int ha = findParent(a);
    int hb = findParent(b);
    if (ha == hb)
    {
        return 0;
    }
    if (ranks[ha] > ranks[hb])
    {
        par[hb] = ha;
    }
    else if (ranks[ha] < ranks[hb])
    {
        par[ha] = hb;
    }
    else
    {
        par[hb] = ha;
        ranks[ha]++;
    }
    return 1;
}

int main()
{
    int n, m, tmp;
    cin >> n;
    tmp = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> bud[i];
        par[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (unions(i, bud[i]))
        {
            tmp--;
        }
    }
    cout << tmp;
}