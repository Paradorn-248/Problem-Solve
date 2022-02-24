#include <bits/stdc++.h>
using namespace std;

int r[222222], nub[222222];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, maxx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (r[i] <= i)
        {
            nub[i - r[i]]++;
        }
        else
        {
            nub[i + (n - r[i])]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (maxx < nub[i])
            maxx = nub[i];
    }
    cout << maxx;
}