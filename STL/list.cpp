// listเก็บเป็นlist เข้าถึงได้แค่หัวกับท้าย และเวลาเข้าถึงต้องใช้iteratorเท่านั้น

#include<bits/stdc++.h>
using namespace std;

void f(list<int> mm)
{
    cout << mm.size() << '\n';
}
void f2(list<int> *mm)
{
    cout << mm->size() << '\n'; // (*m).size()
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    list<int> l;
    l.push_back(10);
    l.push_back(100);
    l.push_back(1000);
    l.push_back(10000);
    auto j = l.begin();
    j++;
    l.insert(j,50000); //insert @ iterlator ที่เลือก (ตอนนี้คือแทรกตน.ที่2)
    l.pop_back();
    j = l.end();
    l.insert(j,30); //แทรกตน.สุดท้าย
    cout << l.size() << '\n';
    for(auto it=l.begin();it!=l.end();it++) //can use only iterator
    {
        cout << *it << '\n';
    }
 
    // ข้อควรระวังในการเรียกใช้STL การเรียกใช้ฟังก์ชันจะpass by valueตามหลักภาษาC แต่จะมีการcopyข้อมูลไปทั้งก้อนเลย ทำให้ทำงานช้าสุดๆ
    // example
    list<int> ll;
    for(int i=0;i<100000;i++)
    {
        ll.push_back(i);
    }
    // for(int i=0;i<ll.size();i++)
    // {
    //     f(ll); //ทุกครั้งที่มีการเรียกใช้f()จะเกิดการcopyทุกครั้ง
    // }
    // ถ้าเราไม่ต้องการให้มันcopyทุกครั้งที่เรียกใช้ ทำได้โดยการอ้างถึงaddress(void f(list<int> *mm))
    for(int i=0;i<ll.size();i++)
    {
        f2(&ll);
    }
}