#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,k,T,start=1,res=1;
    cin >> N >> k >> T;
    while(1)
    {
        start = (start+k)%N;
        res++;
        if(start==T)
            break;
        if(start==1)
        {
            res--;
            break;
        }
        // cout << res << endl;
    }
    cout << res;
}