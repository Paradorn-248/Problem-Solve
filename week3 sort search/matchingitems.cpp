#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> p;
    int n,price,c;
    cin >> n >> c;
    p.emplace_back(0);
    for(int i=1;i<=n;i++)
    {
        cin >> price;
        p.emplace_back(price);
    }
    for(int i=0;i<c;i++)
    {
        int each,y,summ=0;
        cin >> each >> y;
        summ = p[each] + y;
        cout << summ << "" <<upper_bound(p.begin(),p.end(),summ)-p.begin()-1 << "\n";
    }
}