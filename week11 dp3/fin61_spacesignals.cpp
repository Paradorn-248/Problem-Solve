#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    int ans = 0, b=0;
    cin >> s;
    cin >> t;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == s[b])
        {
            b++;
            if (b == s.size())
            {
                b = 0;
                ans++;
            }
        }
    }
    cout << ans;
}
