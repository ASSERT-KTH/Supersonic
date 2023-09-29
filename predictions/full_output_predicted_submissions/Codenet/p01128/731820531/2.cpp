#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(it, c)                                                         \
  for (__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define rforeach(it, c)                                                       \
  for (__typeof__((c).rbegin()) it = (c).rbegin(); it != (c).rend(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CL(arr, val) memset(arr, val, sizeof(arr))
#define COPY(dest, src) memcpy(dest, src, sizeof(dest))
#define ten(n) ((long long)(1e##n))
#define bin(n) (1LL << (n))
