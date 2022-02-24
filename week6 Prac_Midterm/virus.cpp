#include <bits/stdc++.h>
using namespace std;

list<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        v.emplace_back(a);
    }
    auto now = v.begin();
    for(int i=0;i<m;i++)
    {
        cin >> a;
        if(a==1)
        {
            now = v.begin();
        }
        if(a==2)
        {
            now ++;
            if(now==v.end())
                now = v.begin();
        }
        if(a==3)
        {
            cin >> b;
            v.insert(now,b);
        }
        if(a==4)
        {
            cin >> b;
            now++;
            v.insert(now,b);
            now--;
            now--;
        }
        // for(auto it:v)
        //     cout << it << ' ' ;
        // cout << endl << *now << "\n------------------\n";
    }
    for(auto it:v)
            cout << it << '\n' ;

}