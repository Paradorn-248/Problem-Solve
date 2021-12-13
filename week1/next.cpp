#include<iostream>
using namespace std;

int visit[100000];

int main()
{
    int N,i=0,summ=0,res=0;
    cin >> N;
    int swapp[N+1],s[N+1],ps[N+1];
    for(i=1;i<N+1;i++)
    {
        cin >> swapp[i];
        s[i] = i;
        summ += 1;
    }

    while(summ!=0)
    {        
        for(i=1;i<N+1;i++)
        {
            ps[i] = s[i]; 
        }  
        for(i=1;i<N+1;i++)
        {
            s[swapp[i]] = ps[i]; 
            if(s[i]==i&&visit[i]==0)
            {
                summ -= 1;
                visit[i] = 1;
            }
        }
        res++;
    }
    cout << res;
}