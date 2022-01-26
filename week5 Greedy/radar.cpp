#include <bits/stdc++.h>
using namespace std;

pair<double, double> p[1200];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d, casee = 1, can;
    while (1)
    {
        cin >> n >> d;
        can = 0;
        if (n == 0 && d == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            double x, y;
            cin >> x >> y;
            if (y > d)
            {
                can = 1;
            }
            //หาจุดตัดแกนxโดยที่ให้เสมือนวางเรดาร์ที่เกาะ นั่นคือจะได้ช่วงในการวางเรดาร์
            p[i].first = x+sqrt(d*d-y*y);
            p[i].second = x-sqrt(d*d-y*y);
            
        }
        if (can)
        {
            printf("Case %d: -1\n",casee);
            casee++;
            continue;
        }
        sort(p,p+n);
        int current=0,ans=1;
        for(int i=0;i<n;i++)
        {
            if(p[current].first >= p[i].second)
            {
                continue;
            }
            else
            {
                ans++;
                current = i;
            }
        }
        printf("Case %d: %d\n",casee,ans);
        casee++;
    }
}