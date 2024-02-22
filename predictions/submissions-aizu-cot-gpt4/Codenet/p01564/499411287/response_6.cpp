#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>

using ll = long long;
using P = std::pair<int, int>;

// Rest of your code

// Replace getchar_unlocked() and putchar_unlocked() with cin and cout
int getint()
{
    int res;
    std::cin >> res;
    return res;
}

void putint(int d)
{
    std::cout << d;
}

// Replace tie() with structured bindings
void path_set(int u, int v, int d)
{
    auto [xl, xp] = n2l[u];
    auto [yl, yp] = n2l[v];
    // Rest of your code
}

// More replacements of tie() with structured bindings in other functions