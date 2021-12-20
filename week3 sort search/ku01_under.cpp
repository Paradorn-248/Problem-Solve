#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int,int>> v;
    float run=0.5;
    int start,stop,count,ans=-1,L,N;
    cin >> L >> N;
    for(int i=0;i<N;i++)
    {
        cin >> start >> stop;
        v.emplace_back(make_pair(start,stop));
    }
    while(run!=L)
    {
        count = 0;
        for(auto it=v.begin();it!=v.end();it++)
        {
            if(run>it->first && run<it->second)
                count++;
        }
        if(ans<count)
            ans = count;
        run += 0.5;
    }
    cout << ans;
}
