#include <bits/stdc++.h>
using namespace std;

int summ[55555];
vector<tuple<int, int, int>> v;
vector<int> no;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, longg, want;
    cin >> n >> q;
    int a, b, c;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        v.emplace_back(make_tuple(a, b, c));
        no.emplace_back(a);
    }

    sort(v.begin(), v.end());
    sort(no.begin(), no.end());
    
    // for (auto it = 0; it < v.size(); it++)
    // {
    //     printf("%d %d %d\n", get<0>(v[it]), get<1>(v[it]), get<2>(v[it]));
    // }
    // for (auto it = 0; it < no.size(); it++)
    // {
    //     printf("%d ",no[it]);
    // }
    int now;
    for (int i = 0; i < q; i++)
    {
        cin >> now;
        int minn = 1e9, buy = -1;
        auto it = lower_bound(no.begin(),no.end(),now)-no.begin();
        // cout << it << ' ';
        if(it==n)
            it--;
        if(it-5<0)
            it = 0;
        else
            it -= 5;
        // cout << it << ' ';
        while(1)
        {
            if(it==n)
            {
                break;
            }
            if(get<0>(v[it])-now>5)
            {
                break;
            }
            // cout << it << ' ';
            if (get<2>(v[it]) != 0 && abs(get<0>(v[it])-now)<=5)
            {
                if (minn > get<1>(v[it]))
                {
                    buy = it;
                    minn = get<1>(v[it]);
                }
            }
            it++;
        }
        // cout << endl << "buy: " << buy <<" ans: ";                                                                                   // 0=เลขที่บ้าน, 1 = ราคา , 2= จำนวนที่เหลือ
        if (buy == -1)
        {
            cout << "0\n";
        }
        else
        {
            get<2>(v[buy])--;
            cout << minn << '\n';
        }
    }
}