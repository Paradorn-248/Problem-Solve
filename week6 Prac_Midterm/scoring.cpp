#include <bits/stdc++.h>
using namespace std;
int nub[55555],maxscore[55555];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,no,score;
    cin >> n >> m;
    
    
    for(int i=0;i<m;i++)
    {
        cin >> no >> score;
        nub[no]++;
        if(nub[no]>5)
            maxscore[no] = 0;
        else
            maxscore[no] = max(score,maxscore[no]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans += maxscore[i];
    cout << ans;
}