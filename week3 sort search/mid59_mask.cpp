#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v,cons;
    
    int N,score,count=0,tmp=0,maxx=-1,minn=1000000,maxi,mini,a,b,c,d;
    cin >> N;
    int ind[4*N],win[4],lost[4],wa,wb;
    for(int i=0;i<4*N;i++)
    {
        cin >> score;
        v.push_back(score);
        if(maxx<score) 
        {
            maxi = i;
            maxx = score;
        }
        if(minn>score) 
        {
            mini = i;
            minn = score;
        }
        if(tmp==N-1)
        {
            win[count] = maxi;
            lost[count] = mini;
            count++;
            maxx=-1;
            minn=1000000;
            tmp=-1;
        }
        tmp++;
    }
    if(v[win[0]]<v[win[1]])
        c = win[0]+1;
    else
        c = win[1]+1;
    if(v[win[2]]<v[win[3]])
        d = win[2]+1;
    else
        d = win[3]+1;
    if(v[win[0]]>v[win[1]])
        wa = win[0];
    else 
        wa = win[1];
    if(v[win[2]]>v[win[3]])
        wb = win[2];
    else 
        wb = win[3];
    if(v[wa]>v[wb])
    {
        a = wa+1;
        b = wb+1;
    }
    else
    {
        a = wb+1;
        b = wa+1;
    }
    printf("%d %d %d %d",a,b,c,d);
}
