#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=1,i;
    while(1)
    {
        vector<int> l,dis;
        cin >> n;
        if(n==1)
        {
            cout << "Discarded cards:";
            cout <<"\nRemaining card: " << "1" <<'\n';
            continue;
        }
        if(n==0)
            break;
        for(i=1;i<=n;i++)
        {
            l.emplace_back(i);
        }
        while(l.size()!=1)
        {
            dis.emplace_back(l.front());
            l.erase(l.begin());
            l.emplace_back(l.front());
            l.erase(l.begin());
        }
        cout << "Discarded cards: ";
        for(auto it=0;it<n-2;it++)
        {
            cout << dis[it] << ", ";
        }
        cout << dis[n-2] <<"\nRemaining card: " << l.front() <<'\n';
    }
}