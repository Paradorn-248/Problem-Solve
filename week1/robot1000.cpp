#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x=0,y=0;
    string dir;
    cin >> dir;
    for(int i=0;i<dir.length();i++)
    {
        if(dir[i]=='E')
            x++;
        else if(dir[i]=='W')
            x--;
        else if(dir[i]=='N')
            y++;
        else if(dir[i]=='S')
            y--;
        else if(dir[i]=='Z')
        {
            x = 0;
            y = 0;
        }
    }
    cout << x << " " << y;
}