#include <bits/stdc++.h>
using namespace std;

int summ[55555];
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, longg, want;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> longg;
        for(int j=0;j<=i;j++)
        {
            summ[j] += longg;
            v.emplace_back(summ[j]);
        }
    }
    sort(v.begin(),v.end());
    // for(auto it:v)
    // {
    //     cout << it << ' ';
    // }
    // cout << endl;
    for (int i = 0; i < q; i++)
    {
        cin >> want;
        auto it = lower_bound(v.begin(),v.end(),want) - v.begin();
        if(v[it]==want)
        {
            cout << 'Y';
        }
        else
        {
            cout << 'N';
        }
    }
}