#include<iostream>
using namespace std;
int w[400];

int main()
{
    int N,a,maxx=0,i;
    cin >> N;
    for(i=0;i<N;i++)
    {
        cin >> a;
        w[a] += 1;
        maxx=max(maxx,w[a]);
    }
    cout << maxx;
}