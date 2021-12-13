// setเก็บเหมือนsetตามชื่อ

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<pair<int,int>> s; //เวลาinsertจะเรียงให้เองอัตโนมัติ
    s.insert(make_pair(10,20));
    s.insert(make_pair(50,60));
    s.insert(make_pair(20,40));
    s.insert(make_pair(20,10)); 
    for(auto it=s.begin();it!=s.end();it++)
    {
        cout << it->first << " " << it->second << '\n';
    }
}