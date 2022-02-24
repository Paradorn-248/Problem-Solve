#include<bits/stdc++.h>
using namespace std;

int score[111111],dp[111111];

int main()
{
    int n,ans=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> score[i];
        if(i>=2)
        {
            dp[i] = max(score[i]+dp[i-3],dp[i-1]);
            ans = max(ans,dp[i]);
        }
    }
    cout << ans;
}