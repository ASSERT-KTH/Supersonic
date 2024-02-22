#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <ctime>
#include <string>
#include <array>
#include <cstdlib>
#include <climits> 

using namespace std;
using int32 = int_fast32_t;
using int64 = int_fast64_t;
using uint32 = uint_fast32_t;
using uint64 = uint_fast64_t;

constexpr uint32 INF = 1000000000;
constexpr uint32 MOD = 1000000007;

template <typename T> 
class StaticRMQ {
    // ...
    // Keep the rest of the StaticRMQ code as is
    // ...
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    uint32 n, l;
    cin >> n >> l;
    vector<uint32> a(n);
    for (uint32 i = 0; i < n; ++i) {
        cin >> a[i];
    }
    StaticRMQ<uint32> S(a);
    cout << S(0, l);
    for (uint32 i = 1; i < n - l + 1; ++i) {
        cout << " " << S(i, i + l);
    }
    cout << "\n";
    return 0;
}