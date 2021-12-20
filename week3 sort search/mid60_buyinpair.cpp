#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long int a,b,price;
    vector<long long int> v;
    cin >> N >> a >> b;

    for(int i =0;i<N;i++)
    {
        cin >> price;
        v.push_back(price);
    }
    sort(v.begin(),v.end());
    // int ch=0;
    // for(int i=0;i<N-1;i++)
    // {
    //     for(int j=i+1;j<N;j++)
    //     {
    //         int sum = v[i]+v[j];
    //         if(ch==0 && sum>=a && sum<=b)
    //         {
    //             printf("(%lld,%lld)",v[i],v[j]);
    //             ch = 1;
    //         }
    //         else if(sum>=a && sum<=b)
    //             printf(",(%lld,%lld)",v[i],v[j]);
    //     }
    // }
    long long int ans = 0,betw;
    for(auto it=v.begin();it!=v.end();it++)
    {
        betw = upper_bound(it+1,v.end(),b-*it)-lower_bound(it+1,v.end(),a-*it);
        ans += betw;
    }
    cout << ans;
}