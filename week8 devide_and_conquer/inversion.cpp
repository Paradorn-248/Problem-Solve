#include <bits/stdc++.h>
using namespace std;

long long arr[111111], c = 0;

void merge(int l, int m, int r)
{
    int i, j, k;
    int nl = m - l + 1, nr = r - m;
    int L[nl], R[nr];
    for (i = 0; i < nl; i++)
        L[i] = arr[l + i];
    for (j = 0; j < nr; j++)
        R[j] = arr[m + 1 + j];
    // printf("%d %d %d %d %d\n",l,m,r,nl,nr);
    i = 0, j = 0, k = l;
    while (i < nl && j < nr)
    {
        // printf("%d %d\n",L[i],R[j]);
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            c+=nl-i;
            j++;
        }
        k++;
    }
    while (i < nl)
    {
        arr[k] = L[i];
        k++;
        i++;
    }
    while (r < nr)
    {
        arr[k] = R[j];
        k++;
        j++;
    }
    // cout << "---------------------------\n";
}

int merge_sort(int l, int r)
{
    int m;
    if (l < r)
    {
        m = l + (r - l) / 2;
        merge_sort(l, m);
        merge_sort(m + 1, r);
        merge(l, m, r);
    }
}

int main()
{
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    merge_sort(0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << ' ';
    // }
    cout << c;
}