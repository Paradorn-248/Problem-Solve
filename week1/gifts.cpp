#include<iostream>
using namespace std;

int main()
{
    int N,i;
    float a,s=0;
    cin >> N;
    for(i=0;i<N;i++)
    {
        cin >> a;
        if(a>0)
        {
            s += a;
        }
    }
    cout << s;
}