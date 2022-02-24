#include<bits/stdc++.h>
using namespace std;

int arr[2222222];

int main()
{
    int n;
    while(1)
    {
        cin >> n;
        if(n==0)
        {
            break;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                cin >> arr[i];
            }
            sort(arr,arr+n);
            for(int i=0;i<n;i++)
            {
                if(i!=0)
                    cout << " ";
                cout << arr[i];
            }
            cout << '\n';
        }
    }
}