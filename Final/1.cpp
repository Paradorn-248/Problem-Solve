#include <bits/stdc++.h>
using namespace std;
int n, s, in[222],ind;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        ind = (i+s)%20;
        cin >> in[ind];
    }
    if (n < 20)
    {
        int a = 1;
        for (int i = n; i < 20; i++)
        {
            ind = (i+s)%20;
            in[ind] = a;
            a++;
        }
    }    
    // for (int i = 0; i < 20; i++)
    // {
    //     cout << in[i]<< ' ';
    // }
    // cout << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << in[i + j * 5] << " ";
    }
}