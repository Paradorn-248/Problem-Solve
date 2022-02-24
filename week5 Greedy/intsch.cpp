#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,s,stop;
    cin >> n;
    pair<int,int> p[n];
    //first เก็บ stop, second เก็บ s
    for(int i=0;i<n;i++)
    {
        cin >> p[i].second >> p[i].first;
    }
    sort(p,p+n);
    // for(int i=0;i<n;i++)
    // {
    //     cout << p[i].second << p[i].first << endl;
    // }
    int current=0,count=0;
    for(int i=0;i<n;i++)
    {
        if(p[current].first <= p[i].second) // ถ้าตอนจบของตัวปจบ<=ตอนเริ่มของตัวถัดไป
        {
            current = i;
            count++;
        }
    }
    cout << ++count;
}