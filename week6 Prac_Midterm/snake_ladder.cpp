#include <bits/stdc++.h>
using namespace std;

int mapp[1111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a,m, now = 0, chk = 0;
    cin >> n >> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> mapp[i];
    }
    for (int i = 1; i <= a; i++)
    {
        cin >> m;
        now += m;
        if (mapp[now]!=0)
            now += mapp[now];
        if(now>=n)
            now = n;
        if(now<=0)
            now = 0;
    }
    cout << now << endl;
}