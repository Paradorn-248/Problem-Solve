#include <bits/stdc++.h>
using namespace std;

int notprime[222222], prev;

int Sieve_of_Eratosthenes(int n)
{
    notprime[0] = 1;
    notprime[1] = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (notprime[i] == 0)
        {
            for (int j = 2; j <= n/i ; j++)
            {
                notprime[i*j] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r, ans = 0, prev = 0, tmp;
    cin >> l >> r;
    Sieve_of_Eratosthenes(r);
    for (int i = l; i <= r; i++)
    {
        if (notprime[i] == 0)
        {
            if (notprime[i + 2] == 0 && i + 2 <= r)
                ans++;
        }
        // cout << notprime[i] << ' ';
    }
    cout << ans;
}