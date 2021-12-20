#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int M,k;
    char work;
    list<int> l;
    cin >> M;
    for(int i=0;i<M;i++)
    {
        cin >> work >> k;
        if(work=='I')
        {
            l.push_front(k);
        }
        if(work=='D'&&k>0&&k<=l.size())
        {
            int c = 1;
            for(auto it=l.begin();it!=l.end();it++)
            {
                if(c==k)
                {
                    l.erase(it);
                    break;
                }
                c++;
            }
        }
    }
    for(auto it=l.begin();it!=l.end();it++)
    {
        cout << *it << '\n';
    }
}