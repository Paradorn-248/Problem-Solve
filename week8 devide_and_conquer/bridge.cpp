#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[3333];
vector<int> v;

int main()
{
    int n;
    cin >> n;
    int tmp;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        p[tmp-1].first = i;
    }
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        p[tmp-1].second = i;
    }
    sort(p,p+n);
    int now=-1,ans=0;
    for(int i=0;i<n;i++)
    {
        auto lower = lower_bound(v.begin(),v.end(),p[i].second);
        if(lower == v.end())
        {
            v.emplace_back(p[i].second);
        }
        else
        {
            *lower = p[i].second;
        }
    }
    cout << v.size();
}