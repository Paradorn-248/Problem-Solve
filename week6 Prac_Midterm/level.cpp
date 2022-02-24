#include <bits/stdc++.h>
using namespace std;

int chk[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,now=1;
    cin >> n >> m;
    int a[n],b[n],c[n];
    for(int i=1;i<n;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
        if(x>=a[now])
            chk[0] = 1;
        if(y>=b[now])
            chk[1] = 1;
        if(z>=c[now])
            chk[2] = 1;
        if(chk[0]==1&&chk[1]==1&&chk[2]==1)
        {
            now++;
            chk[0] = 0;
            chk[1] = 0;
            chk[2] = 0;
        }
        // cout << now << chk[0] << chk [1] << chk[2] << endl;
    }
    cout << now;
}