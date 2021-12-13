// vector เก็บเหมือนarray เข้าถึงข้อมูลโดยการใช้index,iteratorก้ได้

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    v.push_back(10);
    v.push_back(100);
    v.push_back(1000);
    v.push_back(10000);
    for(int i=0;i<v.size();i++) //can use index
    {
        cout << v[i] << '\n';
    }
    v.pop_back();
    cout << v.size() << '\n';
    for(auto it=v.begin();it!=v.end();it++) //can use iterator 
    {
        cout << *it << '\n';
    }

    ////// vectorที่เก็บpair
    vector<pair<int,int>> v2;
    v2.push_back(make_pair(10,20));
    v2.push_back(make_pair(50,60));
    v2.push_back(make_pair(20,40));
    v2.push_back(make_pair(20,10));
    cout << (v2[0]).first << ' ' << (v2[0]).second << '\n';
    for(auto it=v2.begin();it!=v2.end();it++)    
    {
        // cout << (*it).first <<' ' << (*it).second << '\n';
        cout << it->first << ' ' << it->second << '\n';
    }
    cout << "---------------------\n";

    sort(v2.begin(),v2.end()); // ถ้าเป็นpairจะเรียงfirst ก่อน second
    for(auto it=v2.begin();it!=v2.end();it++)    
    {
        // cout << (*it).first <<' ' << (*it).second << '\n';
        cout << it->first << ' ' << it->second << '\n';
    }

}