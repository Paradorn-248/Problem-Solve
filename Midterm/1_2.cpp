#include <bits/stdc++.h>
using namespace std;
int countt[222222];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, maxx = 0;
    cin >> n;
    // นับว่าคนนั้นต้องหมุนโต๊ะกี่รอบจนจะเจออาหารที่ตัวเองสั่ง
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        t -= i;
        if (t < 0)
            t += n;
        countt[t]++;
        maxx = max(countt[t], maxx);
    }
    cout << maxx;
    return 0;
}