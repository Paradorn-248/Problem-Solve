#include <bits/stdc++.h>
using namespace std;

int a[1111];
vector<int> v[1111];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ind, maxx, nans = 0, nind;
    for (int i = 0; i < n; i++)
    {
        maxx = 0, ind = -1;
        for (int j = i - 1; j > -1; j--)
        {
            if (a[i] > a[j] && v[j].size() > maxx)
            {
                maxx = v[j].size();
                ind = j;
            }
        }
        if (ind != -1)
        {
            v[i] = v[ind];
        }
        v[i].emplace_back(a[i]);
        
        if (nans < v[i].size())
        {
            nans = v[i].size();
            nind = i;
        }
        // cout << nans << ' ' << nind << ' ' <<  v[i].size() << endl;
        // for (int k = 0; k < n; k++)
        // {
        //     printf("v[%d] : ", k);
        //     for (auto it : v[k])
        //     {
        //         printf("%d ", it);
        //     }
        // }
        // cout << endl << "=================" << endl;
    }
    cout << nans << endl;
    for (auto it : v[nind])
    {
        cout << it << ' ';
    }
}