#include<bits/stdc++.h>
using namespace std;

string s[122];
int w,h;
int kstate[122][122][3];

int dfs(int row,int col,int state)
{
    if(s[row][col]=='.')
    {
        dfs(row+1,col,state);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int count=0,ans1,ans2;
    cin >> w >> h;
    for(int i=0;i<h;i++)
    {
        cin >> s[i];
    }
    memset(kstate,-1,sizeof(kstate));
    for(int i=0;i<w;i++)
    {

    }
}