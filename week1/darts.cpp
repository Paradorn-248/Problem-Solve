#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int i,N,x,y,score=0;
    double r;
    cin >> N;
    for(i=0;i<N;i++)
    {
        cin >> x >> y;
        r = sqrt(x*x+y*y);
        if (r>=0 && r<=2)
            score += 5;
        else if (r>2 && r<=4)
            score += 4;
        else if (r>4 && r<=6)
            score += 3;
        else if (r>6 && r<=8)
            score += 2;
        else if (r>8 && r<=10)
            score += 1;

    }
    cout << score;
}