#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> v;
int par[222222];

int findParent(int a)
{
    if (a == par[a])
    {
        return par[a] = a;
    }
    return par[a] = findParent(par[a]);
}

int main()
{
    int sum, n, m, sum_z;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
        sum = 0, sum_z = 0;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            sum_z += z;
            v.emplace_back(make_tuple(z, x, y));
        }
        sort(v.begin(), v.end());
        for (auto it : v)
        {
            if (findParent(get<1>(it)) != findParent(get<2>(it)))
            {
                sum += get<0>(it);
                par[findParent(get<1>(it))] = findParent(get<2>(it));
            }
        }
        v.clear();
        cout << sum_z - sum << '\n';
    }
}