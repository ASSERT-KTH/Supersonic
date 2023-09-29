#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(c) (c).begin(), (c).end()
#define loop(i, a, b) for (ll i = a; i < ll(b); i++)
#define rep(i, b) loop(i, 0, b)
#define each(e, c) for (auto &e : c)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#ifdef DEBUG
#define dump(...)                                                              \
  (cerr << #__VA_ARGS__ << " = " << (DUMP(), __VA_ARGS__).str() << " ["        \
       << __LINE__ << "]" << endl)
struct DUMP : ostringstream {
  template <class T> DUMP &operator,(const T &t) {
    if (this->tellp())
      *this << ", ";
    *this << t;
    return *this;
  }
};
#else
#define dump(...)
#endif
template <class T> ostream &operator<<(ostream &os, vector<T> const &v) {
  rep(i, v.size()) os << v[