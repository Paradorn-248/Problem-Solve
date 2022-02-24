#include <bits/stdc++.h>
using namespace std;

list<int> l;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int want,year;
    char ans='C';
    cin >> want;
    while(1)
    {
        cin >> year;
        if(year==0)
            break;
        l.emplace_back(year);
    }
    l.sort();
    for(int i=2558;i<=want;i++)
    {
        int head = l.front();
        if(i==head)
        {
            l.pop_front();
            continue;
        }
        if(ans=='K')
            ans = 'C';
        else
            ans = 'K';
    }
    cout << ans;
}