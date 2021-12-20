#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q,tall,mini=2e9;
    cin >> N >> Q;
    int arr[N];
    vector<int> v,sv;
    for(int i=0;i<N;i++)
    {
        cin >> tall;
        if(mini>tall)
            mini = tall;
        v.emplace_back(mini);
        sv.emplace_back(mini);
    }
    sort(sv.begin(),sv.end());
    // for(auto it=rv.begin();it!=rv.end();it++)	
    //     cout << *it << " ";
	// cout << '\n';
    int T,k;
    for(int i=0;i<Q;i++)
    {
        cin >> T >> k;
        if(T==1)
        {
            cout << v[k-1] << "\n";
        }
        else if(T==2)
        {
            int a = lower_bound(sv.begin(),sv.end(),k)-sv.begin();
            cout << N-a << "\n";
        }
    }
}