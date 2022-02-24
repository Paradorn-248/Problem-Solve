#include <bits/stdc++.h>
using namespace std;

vector<int> r;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, addr, ans = 0, a;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> addr;
        r.emplace_back(addr);
    }
    sort(r.begin(), r.end());
    int busy = 1,compare;
    int pos;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        pos = lower_bound(r.begin(),r.end(),a) - r.begin();
        if(pos>=n)
        {
            pos = n-1;
        }
        if(pos==busy)
        {
            if(pos-1<0)
            {
                pos = 1;
                compare = pos;
            }
            else if(pos+1>=n)
            {
                pos = n-2;
                compare = pos;
            }
            else
            {
                compare = pos-1;
                pos+=1;
            }
        }
        else if(pos-1 == 0 && pos-1 == busy)
        {
            compare = pos;
        }
        else if(pos-1 >= 0 && pos-1 != busy)
        {
            compare = pos-1;
        }
        else if(pos-2>=0 && pos-2 !=busy)
        {
            compare = pos-2;
        }
        int left=abs(a-r[compare]),right=abs(a-r[pos]);
        if(left<=right)
        {
            busy = compare;
            ans += left;
        }
        else
        {
            busy = pos;
            ans += right;
        }

        // printf("busy: %d | compare: %d left: %d | pos: %d right: %d | ans: %d\n",busy,compare,left,pos,right,ans);
    }
    
    cout << ans;
}