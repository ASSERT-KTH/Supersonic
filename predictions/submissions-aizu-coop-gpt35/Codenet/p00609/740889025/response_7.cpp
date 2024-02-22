#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
int main() {
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    v.clear(); // Clear the vector before each test case
    v.reserve(aN); // Reserve memory for vector v
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v.emplace_back(x, y); // Store the coordinates as a pair in vector v
    }
    // Rest of the code remains the same