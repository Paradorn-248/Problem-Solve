#include <bits/stdc++.h>
using namespace std;
int dir[4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string r;
    cin >> r;
    int k;
    cin >> k;

    for(int i=0;i<r.length();i++)
    {
        if(r[i]=='N') 
        {
            dir[0]++;
        }
        if(r[i]=='S') 
        {
            dir[1]++;
        }
        if(r[i]=='W') 
        {
            dir[2]++;
        }
        if(r[i]=='E') 
        {
            dir[3]++;
        }
    }
    for(int i=0;i<k;i++)
    {
        //ลบตัวที่มีน้อยกว่าออก
        if(dir[2]>dir[3] && dir[3]!=0)
            dir[3]--;
        else if(dir[2]<dir[3] && dir[2]!=0)
            dir[2]--;
        else if(dir[0]>dir[1] && dir[1]!=0)
            dir[1]--;
        else if(dir[0]<dir[1] && dir[0]!=0)
            dir[0]--;
        //ตัวที่เหลือที่ไม่เข้าเคส
        else
        {
            if(dir[2]!=0)
                dir[2]--;
            else if(dir[3]!=0)
                dir[3]--;
            else if(dir[0]!=0)
                dir[0]--;
            else if(dir[1]!=0)
                dir[1]--;
        }
    }
    cout << (abs(dir[0]-dir[1])+abs(dir[2]-dir[3]))*2;
}