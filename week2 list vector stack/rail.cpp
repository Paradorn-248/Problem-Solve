#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    int n = 1;
    while(1)
    {
        cin >> n;
        if(n==0)
            break;
        
        while(1)
        {
            int rail[n];
            cin >> rail[0];
            if(rail[0]==0)
            {
                cout << '\n';
                break;
            }
            for (int i = 1; i < n; i++)
            {
                cin >> rail[i];
            }
            int ind=0;
            for(int i=0;i<n;i++)
            {
                l.emplace_back(i+1);
                while(l.size()!=0 && l.back()==rail[ind])
                {
                    l.pop_back();
                    ind++;
                }
            }
            if(l.size()==0)
                cout << "Yes" << '\n';
            else 
                cout << "No" << '\n';
            l.clear();
        }
    }
}