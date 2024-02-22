#include <bits/stdc++.h>

template <class Key> struct RandomizedBinarySearchTree {
  inline int xor128() const {
    static int x = 123456789;
    static int y = 362436069;
    static int z = 521288629;
    static int w = 88675123;
    int t;
    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  // Rest of the code remains same as it is already optimized.

};

// Rest of the classes remain same.

int main() {

  // Use cin and cout for standard input/output.
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  // Rest of the code remains same as it is already optimized.

}