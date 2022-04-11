#include <bits/stdc++.h>
using namespace std;

double ans = 0;
int n, m, par[5555], x[5555], y[5555];
vector<tuple<double, int, int>> graph;

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double dis;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        for (int j = 1; j < i; j++)
        {
            dis = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            graph.emplace_back(make_tuple(dis, i, j));
        }
    }
    sort(graph.begin(), graph.end());

    for (int i = 0; i <= n; i++)
    {
        par[i] = i;
    }

    int a, b;
    for (auto i : graph)
    {
        a = findParent(get<1>(i));
        b = findParent(get<2>(i));
        if (a != b)
        {
            par[a] = b;
            ans += get<0>(i);
            n--;
        }
        if (n == 2)
            break;
    }
    printf("%.5f", ans);
}