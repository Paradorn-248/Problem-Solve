#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,k,T,s=1,res=1;
    cin >> N >> k >> T;
    while(1)
    {
        s = (s+k)%N;
        res++;
        if(s==T)
            break;
        if(s==1)
        {
            res--;
            break;
        }
        // cout << res << endl;
    }
    cout << res;
}