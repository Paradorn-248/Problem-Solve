#include <bits/stdc++.h>
using namespace std;
int seq[11111], start[11111], endd[11111];
vector<int> v;

int ind(vector<int> v, int a)
{
    return lower_bound(v.begin(), v.end(), a) - v.begin();
}

int main()
{
    int n, index;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> seq[i];
            index = ind(v, seq[i]);
            if (index == v.size())
            {
                v.emplace_back(seq[i]);
            }
            else
            {
                v[index] = seq[i];
            }
            start[i] = v.size();
        }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << start[i] << ' ';
        // }
        // cout << endl;

        v.clear();

        for (int i = n - 1; i >= 0; i--)
        {
            index = ind(v, seq[i]);
            if (index == v.size())
            {
                v.emplace_back(seq[i]);
            }
            else
            {
                v[index] = seq[i];
            }
            endd[i] = v.size();
        }
        v.clear();
        // for (int i = 0; i < n; i++)
        // {
        //     cout << endd[i] << ' ';
        // }
        // cout << endl;
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (start[i] == endd[i])
            {
                ans = max(ans,start[i]+endd[i]-1);
            }
        }
        cout << ans << '\n';
    }
}