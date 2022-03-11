#include<bits/stdc++.h>
using namespace std;

vector<int> vprime;
int dp[11111][15];

int is_not_prime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return 1;
        }
    }
    return 0;
}

void gen_prime()
{
    for(int i=2;i<=1120;i++)
    {
        if(is_not_prime(i)==0)
        {
            vprime.emplace_back(i);
        }
    }
    // for(auto it:vprime)
    //     cout << it << ' ';
    // cout << endl;
}

int main()
{
    gen_prime();
    for (auto p : vprime)
    {
        for (int k = 14; k >= 2; k--)
        {
            for (int i = p + 1; i <= 1120; i++)
            {
                dp[i][k] += dp[i - p][k - 1];
            }
        }
        dp[p][1] = 1;
    }
    
    // for (int k = 1; k <= 10; k++)
    // {
    //     for (int i = 1; i <= 50; i++)
    //     {
    //         printf("%d ", dp[i][k]);
    //     }
    //     printf("\n");
    // }

    while(1)
    {
        int n,k;
        cin >> n >> k;
        if(n==0 && k==0)
            break;
        cout << dp[n][k] << endl;
    }
}