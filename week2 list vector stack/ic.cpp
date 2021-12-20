#include<bits/stdc++.h>
using namespace std;
list<int>::iterator it;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M,n;
    list<int> l;
    string work;
    cin >> M;
    for(int i=0;i<M;i++)
    { 
        cin >> work;
        if(work.compare("li")==0)
        {
            cin >> n;
            l.push_front(n);
        }
        if(work.compare("ri")==0)
        {
            cin >> n;
            l.push_back(n);
        }
        if(work.compare("lr")==0)
        {
            l.push_back(l.front());
            l.pop_front();
        }
        if(work.compare("rr")==0)
        {
            l.push_front(l.back());
            l.pop_back();
        } 
    }
    for(auto it=l.begin();it!=l.end();it++)
    {
        cout << *it << '\n';
    }
}