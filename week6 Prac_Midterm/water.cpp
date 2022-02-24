#include <bits/stdc++.h>
using namespace std;

int chk[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,prev=0,now,ans=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> now;
        if(prev-now>10)
        {
            if((prev-now)*10<=700)
                ans += (prev-now)*10;
            else
                ans += 700;
        }
        
        // cout << (prev-now)*10 << '\n';
        prev = now;
    }
    cout << ans;
}