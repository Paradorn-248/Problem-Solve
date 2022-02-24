#include <bits/stdc++.h>
using namespace std;

int summ[55555];
unordered_map<int,int> ans;

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
            ans[summ[j]] = 1;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> want;
        if (ans[want])
            cout << 'Y';
        else
            cout << 'N';
    }
}