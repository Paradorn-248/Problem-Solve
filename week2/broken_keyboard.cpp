#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s[10000],ans[10000],tmp;
    // list<string> l[10000];
    int i=0,mode,ins=0;
    s[0] = "b";
    while(s[i]!='\n')
    {
        ins=0;
        cin >> s[i];
        for(int j=0;j<s[i].length();j++)
        {
            if(s[i][j]!='[')
            {
                mode=0;
                continue;
            }
            else if(s[i][j]==']')
            {
                mode=1;
                ins=0;
            }
            if(mode==0)
            {
                ans[i].insert(ins,s[i][j]);
                ins++;
                ans[i].erase(j);
            }
            if(mode==1)
            {
                ans[i].push_back(s[i][j]);
            }
            else
            {
                ans[i].insert(j,s[i][j]);
            }
        }
        i++;
    }
    for(i=0;i<3;i++)
    {
        cout << ans[i] << '\n';
    }
}