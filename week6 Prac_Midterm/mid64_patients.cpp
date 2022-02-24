#include <bits/stdc++.h>
using namespace std;

int ans[1111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, b, l;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l;
        if (l == 0)
            continue;
        for (int j = 0; j < l; j++)
        {
            cin >> a >> b;
            // b = b+1;
            for(int k=i;k<b+i;k++)
            {
                ans[k] += a;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << ans[i] << '\n';
    }
}