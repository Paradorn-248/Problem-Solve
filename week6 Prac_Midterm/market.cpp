#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairr;

priority_queue<pair<int, int>> buyer;                        // popเอาตัวมาก
priority_queue<pairr, vector<pairr>, greater<pairr>> seller; // popเอาตัวน้อย

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, type, p, a, q, b, ans = 0;
    cin >> n;
    int nub[n + 1];
    pairr select;
    for (int i = 1; i <= n; i++)
    {
        cin >> type;
        if (type == 1) // buyer
        {
            cin >> p >> a;
            while (!seller.empty())
            {
                select = seller.top();
                if (select.first <= p) // เกิดการซื้อ
                {
                    if(a==select.second)
                    {
                        ans += p*a;
                        a = 0;
                        select.second = 0;
                        seller.pop();
                        break;
                    }
                    else if(a<select.second)
                    {
                        ans += p*a;   
                        select.second -= a;
                        a = 0;
                        seller.pop();
                        seller.push(make_pair(select.first,select.second));
                        break;
                    }
                    else if(a>select.second)
                    {
                        ans += p*select.second;
                        a -= select.second;
                        seller.pop();
                    }
                }
                else
                    break;
            }
            if (a != 0)
            {
                buyer.push(make_pair(p, a));
            }
        }
        else if (type == 2) // seller
        {
            cin >> q >> b;

            while (!buyer.empty())
            {
                select = buyer.top();
                if (select.first >= q) // เกิดการซื้อขาย
                {
                    if(b==select.second)
                    {
                        ans += q*b;
                        b = 0;
                        select.second = 0;
                        buyer.pop();
                        break;
                    }
                    else if(b<select.second)
                    {
                        ans += q*b;   
                        select.second -= b;
                        b = 0;
                        buyer.pop();
                        buyer.push(make_pair(select.first,select.second));
                        break;
                    }
                    else if(b>select.second)
                    {
                        ans += q*select.second;
                        b -= select.second;
                        buyer.pop();
                    }
                }
                else
                    break;
            }

            if (b != 0)
            {
                seller.push(make_pair(q, b));
            }
        }
        // if (!buyer.empty())
        // {
        //     pairr select1 = buyer.top();
        //     printf("p:%d a:%d\n", select1.first, select1.second);
        // }
        // if (!seller.empty())
        // {
        //     pairr select1 = seller.top();
        //     printf("q:%d b:%d\n", select1.first, select1.second);
        // }
        // cout << endl;
    }
    cout << ans;
}