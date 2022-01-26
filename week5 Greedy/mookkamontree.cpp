#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string want,s;
    cin >> want;
    cin >> s;
    int index=0,ans=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==want[index])
        {
            index++;
            if(index==want.length()-1)
            {
                index = 0;
                ans++;
            }
        }
    }
    cout << ans;
}