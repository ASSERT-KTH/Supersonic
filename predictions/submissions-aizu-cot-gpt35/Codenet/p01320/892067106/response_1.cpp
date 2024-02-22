#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
typedef complex<double> P;
typedef vector<P> G;
const double EPS = 1e-9;
const double PI = acos(-1.0);
inline int sig(const double &x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }