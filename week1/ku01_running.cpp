#include<iostream>
using namespace std;

int main()
{
    long long N,k,minn=1e9+1,i;
    cin >> N >> k; 
    long long s[N+1];
    long long mtime,chk;
    for(i=1;i<N+1;i++)
    {
        cin >> s[i];
        minn = min(minn,s[i]);
    }
    mtime = minn*k;
    long long res = N;
    for(i=1;i<N+1;i++)
    {
        if((double)mtime/s[i]<=k-1)
        {
            res--;
        }
    }
    cout << res;
}