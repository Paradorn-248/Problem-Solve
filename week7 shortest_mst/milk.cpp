#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g;

int n, m, par[111111];

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
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int a,b;
        char menu;
        cin >> menu >> a >> b;
        if(menu=='c')
        {
            par[findParent(a)] = findParent(b);
        }
        else
        {
            if(findParent(a)==findParent(b))
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }
}