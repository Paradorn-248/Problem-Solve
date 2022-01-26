#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int want;
        cin >> want;
        while(1)
        {
            int a,b;
            cin >> a >> b;
            if(a==0 && b==0)
                break;
            if(b>0)
                v.emplace_back(make_pair(b,a));
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        int current = 0,s=v.size(),chk=0;
        vector<pair<int,int>> ans;
        while(current<want)
        {
            int can = 1;
            for(int j=0;j<s;j++)
            {
                if(v[j].second<=current && v[j].first>current)
                {
                    current = v[j].first;
                    can = 0;
                    s=j+1;
                    ans.emplace_back(make_pair(v[j].second,v[j].first));
                    if(current>=want)
                        chk=1;
                    break;
                    
                }  
            }
            if(can)
                break;
        }
        if(chk==0)
        {
            cout << 0 << "\n\n";
        }
        else
        {
            cout << ans.size() << '\n';
            for(auto it=ans.begin();it != ans.end();it++)
            {
                cout << (*it).first << ' ' << (*it).second << '\n';
            }
        }
        v.clear();
        ans.clear();
    }
}