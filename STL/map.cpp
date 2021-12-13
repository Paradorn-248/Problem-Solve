// map เก็บเป็นเหมือน key,value

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int,int> m;
    m[10] = 100;
    m[100] = 1001;
    m[112122121] = 100111;
    m[100000] = 10011;
    //เรียงให้เหมือนกัน โดยเรียงตามkey(first)ก่อน
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout << it->first << ' ' << it->second << '\n';
    }
    cout << (m.find(112122121)!=m.end()? "yes\n":"no\n");
    cout << (m.find(112122120)!=m.end()? "yes\n":"no\n");

}