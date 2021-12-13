#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,i,j;
    char work;
    list<int> l[100001];
    cin >> n;
    for(int a=0;a<n;a++)
    {
        cin >> work;
        if(work=='N')
        {
            cin >> x >> i;
            l[i].emplace_back(x);
        }
        if(work=='M')
        {
            cin >> i >> j;
            l[j].splice(l[j].end(),l[i]);
        }
    }
    for(int i=0;i<100001;i++)
    {
        for(auto it=l[i].begin();it!=l[i].end();it++)
            cout << *it << '\n';
    }
}