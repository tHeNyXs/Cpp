#include <bits/stdc++.h>
#include "dining_car.h"
using namespace std;

int find_min(int l, int r) {
  while (l < r) {
    int mid = (l+r)/2;
    int val = compare_cars(mid, mid+1);
    if (val <= 0) r = mid;
    else l = mid+1;
  }
  return l;
}

pair<int, int> locate_dining_cars(int N)
{
  int l = 1, r = N;
  while (l < r) {
    int mid = (l+r)/2;
    int q1 = compare_cars(l, r);
    if (q1 == 0) {
      int x = find_min(l, mid);
      int y = r - (x-l);
      return make_pair(x, y);
    }
    int q2 = compare_cars(mid, mid+1);
    if (q1 == q2 && q1 == -1) r = mid;
    else if (q1 == q2 && q1 == 1) l = mid+1;
    else return make_pair(find_min(l, mid), find_min(mid+1, r));
  }  
}