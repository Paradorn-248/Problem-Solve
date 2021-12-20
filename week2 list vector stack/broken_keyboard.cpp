#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    
    int i=0,mode,ins;
    while(getline(cin,s))
    {
        list<char> l;
        ins=0;
        list<char>::iterator it;
        it = l.begin();
        mode = 1;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]=='[')
            {
                mode=0;
                it = l.begin();
                continue;
            }
            else if(s[j]==']')
            {
                mode=1;
                continue;
            }
            if(mode==0)
            {
                l.insert(it,s[j]);
            }
            else
            {
                l.emplace_back(s[j]);
            }
        }
        for(auto itt=l.begin();itt!=l.end();itt++)
        {
            cout << *itt;
        }
        cout << '\n';
    }
}