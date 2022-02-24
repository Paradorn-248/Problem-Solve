#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairr;

queue<int> q;

priority_queue<pair<int, int>> maxheap;                        // popเอาตัวมาก
priority_queue<pairr, vector<pairr>, greater<pairr>>  minheap; // popเอาตัวน้อย