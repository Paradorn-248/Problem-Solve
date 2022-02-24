#include <bits/stdc++.h>
using namespace std;

int ispr(int a)
{
    if (a == 1)
        return 1;
    for (int i = 2; i <= sqrt(a) ; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r, ans = 0, prev = 0, tmp;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (ispr(i))
        {
            prev = i;
            tmp = i;
            break;
        }
    }
    // cout << prev << tmp;
    for (int i = tmp + 1; i <= r; i++)
    {
        if (ispr(i))
        {
            if (abs(prev - i) == 2)
            {
                ans++;
            }
            prev = i;
        }
    }
    cout << ans;
}