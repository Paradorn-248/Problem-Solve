#include<bits/stdc++.h>
using namespace std;

pair<int,int> p[111111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> p[i].first >> p[i].second;
        p[i].first += 10;
        // cout << p[i].first << ' ' << p[i].second << endl;
    }
    sort(p,p+n);
    int current=0,ans=0;
    for(int i=0;i<n;i++)
    {
        current += p[i].second;
        if(current>p[i].first)
        {
            ans = max(1000*(current-p[i].first),ans);
        }
        // cout 
    }
    cout << ans;
}