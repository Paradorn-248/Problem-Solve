#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string r;
    cin >> r;
    char state = 'N';
    for (int i = 0; i < r.length(); i++)
    {
        if(r[i]=='Z')
        {
            cout << 'Z';
            state = 'N';
        }
        else if (state == 'N')
        {
            if (r[i] == 'N')
            {
                cout << "F";
                state = 'N';
            }
            if (r[i] == 'E')
            {
                cout << "RF";
                state = 'E';
            }
            if (r[i] == 'S')
            {
                cout << "RRF";
                state = 'S';
            }
            if (r[i] == 'W')
            {
                cout << "RRRF";
                state = 'W';
            }
        }
        else if (state == 'E')
        {
            if (r[i] == 'N')
            {
                cout << "RRRF";
                state = 'N';
            }
            if (r[i] == 'E')
            {
                cout << "F";
                state = 'E';
            }
            if (r[i] == 'S')
            {
                cout << "RF";
                state = 'S';
            }
            if (r[i] == 'W')
            {
                cout << "RRF";
                state = 'W';
            }
        }
        else if (state == 'S')
        {
            if (r[i] == 'N')
            {
                cout << "RRF";
                state = 'N';
            }
            if (r[i] == 'E')
            {
                cout << "RRRF";
                state = 'E';
            }
            if (r[i] == 'S')
            {
                cout << "F";
                state = 'S';
            }
            if (r[i] == 'W')
            {
                cout << "RF";
                state = 'W';
            }
        }
        else if (state == 'W')
        {
            if (r[i] == 'N')
            {
                cout << "RF";
                state = 'N';
            }
            if (r[i] == 'E')
            {
                cout << "RRF";
                state = 'E';
            }

            if (r[i] == 'S')
            {
                cout << "RRRF";
                state = 'S';
            }

            if (r[i] == 'W')
            {
                cout << "F";
                state = 'W';
            }
        }
        // cout << " ";
    }
}