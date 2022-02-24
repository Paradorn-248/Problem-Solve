#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> a; // <stop,start,weight>
vector<int> v[1111];
int n, dp[1111];

int main()
{
    cin >> n;
    int start, stop, weight;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> stop >> weight;
        a.emplace_back(make_tuple(stop, start, weight));
    }
    sort(a.begin(), a.end());
    int ind = -1;
    for (int i = 0; i < n; i++)
    {
        ind = -1;
        for (int j = i - 1; j > -1; j--)
        {
            if (get<0>(a[j]) <= get<1>(a[i]))
            {
                ind = j;
                break;
            }
        }
        if (dp[ind] + get<2>(a[i]) > dp[i-1]) //เลือกว่าจะใช้ตัวนี้หรือตัวก่อนหน้า
        {
            dp[i] = dp[ind] + get<2>(a[i]);
            if (ind != -1)
            {
                v[i] = v[ind];
            }
            v[i].emplace_back(i);
        }
        else
        {
            v[i] = v[i-1];
            dp[i] = dp[i-1];
        }
    }
    printf("%d\n%d\n",dp[n-1],v[n-1].size());
    for(auto it:v[n-1])
    {
        cout << it << ' ';
    }
}