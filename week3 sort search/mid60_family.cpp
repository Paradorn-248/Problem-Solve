#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int t[N + 1], rel, a, b;
    t[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        cin >> rel;
        t[i] = rel;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        int ch = 1;
        int tmp = a;
        while (tmp!= 1)
        {
            if (t[tmp] == b)
            {
                cout << b << "\n";
                ch = 0;
                break;
            }
            else
            {
                tmp = t[tmp];
            }
        }
        tmp = b;
        while (tmp!= 1)
        {
            if (t[tmp] == a)
            {
                cout << a << "\n";
                ch = 0;
                break;
            }
            else
            {
                tmp = t[tmp];
            }
        }
        if (ch == 1)
        {
            cout << "-1" << "\n";
        }
    }
}