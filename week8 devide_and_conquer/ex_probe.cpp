#include "probelib.h"
#include <bits/stdc++.h>

using namespace std;

int n;

main()
{
  int n = probe_init();
    // cout << n;
  for(int i=0; i<10; i++) {
    if(probe_check(i,i)) {
      probe_answer(i);
    }
  }
  
  probe_answer(n-1);
}