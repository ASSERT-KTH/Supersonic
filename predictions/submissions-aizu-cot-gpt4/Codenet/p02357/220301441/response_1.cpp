#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> 
class StaticRMQ {
    vector<T> a;
    vector<vector<uint32_t>> table;
    vector<uint32_t> R, L, part;

public:
    StaticRMQ(vector<T> &array) {
        a = array;
        R.resize(a.size());
        L.resize(a.size());
        part.resize(a.size());
        table.resize(a.size());

        // ... rest of the constructor ...

    }

    uint32_t operator()(uint32_t begin, uint32_t end) {
        // ... operator implementation ...
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n, l;
    cin >> n >> l;
    vector<uint32_t> a(n);
    for (uint32_t i = 0; i < n; ++i) {
        cin >> a[i];
    }
    StaticRMQ<uint32_t> S(a);
    cout << S(0, l);
    for (uint32_t i = 1; i < n - l + 1; ++i) {
        cout << " " << S(i, i + l);
    }
    cout << "\n";
    return 0;
}