#include <iostream>
#include <vector>
#include <algorithm>
#define ALL(a) (a).begin(), (a).end()
#define debug(x) cout << #x << " : " << (x) << " --------------" << endl;
using namespace std;

int fastSqrt(int num) {
    int low = 0, high = num, mid;
    while(low <= high) {
        mid = (low + high) >> 1;
        if(mid * mid <= num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int main(void) {
  vector<int> cube(101), square(100001);
  for(int i = 0; i <= 100; i++)
    cube[i] = i * i * i;
  for(int i = 0; i <= 100000; i++)
    square[i] = i * i;
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      if (cube[z] > e)
        continue;
      for (int y = fastSqrt(e - cube[z]); y >= 0; --y) {
        int val2 = cube[z] + square[y];
        if (val2 > e)
          continue;
        int diff = e - val2;
        m = min(m, diff + y + z);
      }
    }
    cout << m << '\n';
  }
  return EXIT_SUCCESS;
}