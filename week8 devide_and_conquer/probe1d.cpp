#include "probelib.h"
#include<bits/stdc++.h>

using namespace std;

// void binarySearch(int l, int r)
// {
//     cout << l << " " << r <<endl;
//     if (r >= l) {
//         int mid = l + (r - l) / 2;
//         if (probe_check(l,mid))
//         {
//             if(l==mid)
//                 return probe_answer(mid);
//             else
//                 return binarySearch(l, mid);
//         }
//         else    
//         {
//             if(r==mid)
//                 return probe_answer(mid);
//             else
//                 return binarySearch(mid+1,r);
//         }
//     }
// }

void binarySearch(int l, int r)
{
    cout << l << " " << r <<endl;
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if(l==r)
        {
            return probe_answer(l);
        }
        if (probe_check(l,mid))
        {
            return binarySearch(l, mid);
        }
        else    
        {
            return binarySearch(mid+1,r);
        }
    }
}

int main()
{
    int n = probe_init();
    binarySearch(0,n-1);
    probe_answer(n-1);
}

//g++ -o probe1d probe1d.cpp probelib.cpp