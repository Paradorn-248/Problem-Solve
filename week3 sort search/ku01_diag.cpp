#include <bits/stdc++.h>
using namespace std;
int dir[4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<pair<int, int>> coor;
    vector<int> x, y;
    int xx, yy, tmpx, tmpy;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> xx >> yy;
        tmpx = xx + yy;
        tmpy = yy - xx;
        coor.emplace_back(make_pair(tmpx, tmpy));
        x.emplace_back(tmpx);
        y.emplace_back(tmpy);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int medx, medy;
    long long ans=0;
    if (n % 2 != 0)
    {
        medx = x[n / 2];
        medy = y[n / 2];
    }
    else
    {
        medx = (x[n / 2 - 1] + x[n / 2]) / 2;
        medy = (y[n / 2 - 1] + y[n / 2]) / 2;
    }
    for (auto it=coor.begin();it!=coor.end();it++)
    {
        ans += abs(it->first - medx) + abs(it->second - medy);
    }
    cout << ans;
}