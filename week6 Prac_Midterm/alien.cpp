#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b,r,ans=0,x,y;
    cin >> n >> a >> b >> r;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        if((a-x)*(a-x)+(b-y)*(b-y)<=r*r)
        {
            ans++;
        }
    }
    cout << ans;
}