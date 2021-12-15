#include <bits/stdc++.h>
using namespace std;
list<int> l[300000];
list<int>::iterator it;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int att[n];
    for (int i = 0; i < n; i++)
    {
        l[i].emplace_back(i + 1);
        att[i] = i;
    }
    int b, a;
    for (int i = 0; i < n-1; i++)
    {
        cin >> b >> a;
        for (it = l[att[a - 1]].begin(); it != l[att[a - 1]].end(); it++)
        {
            if (*it == a)
                break;
        }
        it++;
        l[att[a - 1]].splice(it, l[att[b - 1]]);
        att[b - 1] = att[a - 1];
    }

    // print
    for (int i = 0; i < n; i++)
    {
        if (l[i].size() != 0)
        {
            for (auto itt = l[i].begin(); itt != l[i].end(); itt++)
            {
                cout << *itt << " ";
            }
            cout << "\n";
            break;
        }
    }
}