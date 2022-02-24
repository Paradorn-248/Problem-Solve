#include <bits/stdc++.h>
using namespace std;

vector<int> v[222222];
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k,a,b;
    cin >> n >> m >> k;
    for(int i = 1;i<=n;i++)
    {
        par[i] = i;
    }
    for(int i = 0; i < m ;i++)
    {
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
        int parA = findParent(a);
        int parB = findParent(b);
        par[parB] = parA;
        // cout << par[a] << '-' << par[b] << endl;
    }
    

    for(int i=0;i<k;i++)
    {
        cin >> a >> b;
        a = findParent(a);
        b = findParent(b);
        if(a==b)
        {
            cout << "1\n" ;
        }
        else
        {
            cout << "0\n";
        }
    }
}