#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
   
    while(1)
    { 
        list<int> l;
        cin >> n;
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
            l.emplace_back(i);
        cout << "Discarded cards: ";
        while(1)
        {
            cout << l.front();
            if(l.size()==2)
            {
                l.pop_front();
                cout << "\nRemaining card: " << l.front() <<'\n';
                break;
            }
            else
                cout << ", ";
            
            l.pop_front();
            l.emplace_back(l.front());
            l.pop_front();
        }
    }
}