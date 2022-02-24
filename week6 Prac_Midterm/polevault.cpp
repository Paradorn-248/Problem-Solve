#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, longg, want;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> longg;
        v.emplace_back(longg);
    }
    for (int i = 0; i < q; i++)
    {
        int ans = 0;
        cin >> want;
        for (int j = 0; j < n; j++)
        {
            int summ = v[j];
            // cout << v[j] << ' ';
            // cout << "summ : ";
            for (int k = j + 1; k < n ; k++)
            {
                // cout << v[k] << ' ';
                if (summ > want)
                {
                    break;
                }
                if (summ == want)
                {
                    ans = 1;
                    break;
                }
                summ += v[k]; 
            }
            if(summ==want)
            {
                ans=1;
            }
            // cout << "ans: " << ans; 
            if(ans==1)
            {
                break;
            }
            // if (summ == want)
            // {
            //     ans = 1;
            //     break;
            // }
            // cout << endl;
        }
        
        if (ans)
            cout << 'Y';
        else
            cout << 'N';
    }
}