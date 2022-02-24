#include <bits/stdc++.h>
using namespace std;

// vector<tuple<int, int, int>> g; ถ้าใช้vectorต้องsortก่อน
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
    int ans = 0;
    // sort(g.begin(), g.end());
    for(auto i:g)
    {
        if(findParent(get<1>(i))!=findParent(get<2>(i)))
        {
            ans += get<0>(i);
            par[findParent(get<1>(i))] = findParent(get<2>(i));
        }
        // for(int j=1;j<=n;j++)
        // {
        //     cout << par[j] << ' ';
        // }
        // cout << '\n';
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
        if (i <= n)
        {
            par[i] = i;
        }
    }
    cout << mst();
}