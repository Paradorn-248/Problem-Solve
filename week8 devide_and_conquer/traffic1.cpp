#include <bits/stdc++.h>
#include "traffic.h"
using namespace std;

int n, k, tmp, x, y;

void binarySearch_ver(int l, int r)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;
    // cout << l << " " << mid << ' ' << r << endl;
    // cout << "dis-> " << traffic_query(tmp, l, tmp, mid) << ' ' << a << endl;
    if (abs(l - r) == 1)
    {
      x = l, y = r;
      return;
    }
    if (traffic_query(tmp, l, tmp, mid) > mid - l)
    {
      return binarySearch_ver(l, mid);
    }
    else
    {
      return binarySearch_ver(mid, r);
    }
  }
}

void binarySearch_hor(int l, int r)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;
    // cout << l << " "  << mid << ' ' << r << endl;
    // cout << "dis-> " << traffic_query(l, tmp, mid, tmp) << ' ' << traffic_query(l, tmp, r, tmp) / 2 << endl;
    if (abs(l - r) == 1)
    {
      x = l, y = r;
      return;
    }
    if (traffic_query(l, tmp, mid, tmp) > mid - l)
    {
      return binarySearch_hor(l, mid);
    }
    else
    {
      return binarySearch_hor(mid, r);
    }
  }
}

int main()
{
  traffic_init(&n, &k);
  int line = 0;
  for (int i = 1; i <= n; i++) //เส้นตั้ง
  {
    if (traffic_query(i, n, i, 1) == n)
    {
      tmp = i;
      line = 1;
      break;
    }
  }
  for (int i = 1; i <= n; i++) //เส้นนอน
  {
    if (traffic_query(1, i, n, i) == n)
    {
      tmp = i;
      break;
    }
  }

  if (line)
  {
    binarySearch_ver(1, n);
    traffic_report(tmp, x, tmp, y, 0, 0, 0, 0);
  }
  else
  {
    binarySearch_hor(1, n);
    traffic_report(x, tmp, y, tmp, 0, 0, 0, 0);
  }
}