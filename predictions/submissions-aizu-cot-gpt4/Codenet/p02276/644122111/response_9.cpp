#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned int uint;

void print_partition_ints(const vector<int>& as, const uint q) {
    string out_sep = "";
    string format;
    for (uint i = 0; i < as.size(); ++i) {
        format = (i != q ? "%s%d" : "%s[%d]");
        printf(format.c_str(), out_sep.c_str(), as[i]);
        out_sep = " ";
    }
    printf("\n");
}

uint partition(vector<int>& as, const uint first, const uint last) {
    auto less = first;
    for (auto i = first; i < last; ++i) {
        if (as[i] <= as[last]) {
            swap(as[less], as[i]);
            ++less;
        }
    }
    swap(as[less], as[last]);
    return less;
}

int main() {
    ios_base::sync_with_stdio(false);
    uint n;
    cin >> n;
    vector<int> as(n);
    for (auto i = 0u; i < n; ++i) {
        cin >> as[i];
    }
    auto q = partition(as, 0, n - 1);
    print_partition_ints(as, q);
    return 0;
}