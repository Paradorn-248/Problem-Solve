#include <bits/stdc++.h>
using namespace std;

set<tuple<int, int, int>> g;

int n, m, par[111111];

int findParent(int a)
{
    if (a == par[a])
    {
        return par[a] = a;
    }
    return par[a] = findParent(par[a]);
}

int mst()
{
    int ans = 0,c=0;
    for (auto i : g)
    {
        if (findParent(get<1>(i)) != findParent(get<2>(i)))
        {
            ans += get<0>(i);
            par[findParent(get<1>(i))] = findParent(get<2>(i));
            c++;
        }
        // for(int j=1;j<=n;j++)
        // {
        //     cout << par[j] << ' ';
        // }
        // cout << '\n';
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (findParent(1) != findParent(i)) // checkว่าสุดท้ายทุกตัวจะมีพ่อแม่เหมือนกันมั้ย
    //     {
    //         ans = -1;
    //         break;
    //     }
    // }
    if(c<n-1)
    {
        ans = -1;
    }
    return ans;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g.insert(make_tuple(w, a, b));
        // if
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }
        cout << mst() << '\n';
    }
}
