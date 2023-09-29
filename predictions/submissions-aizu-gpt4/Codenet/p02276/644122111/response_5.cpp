#include <iostream>
#include <vector>
using namespace std;

void print_partition_ints(const vector<int>& as, const int q) {
    for (size_t i = 0; i < as.size(); ++i) {
        if(i != 0) cout << " ";
        if (i == q) cout << "[";
        cout << as[i];
        if (i == q) cout << "]";
    }
    cout << "\n";
}

int partition(vector<int>& as, const int first, const int last) {
    auto less = first;
    for (auto i = first; i < last; ++i) {
        if (as[i] <= as[last]) {
            swap(as[less++], as[i]);
        }
    }
    swap(as[less], as[last]);
    return less;
}

int main() {
    int n;
    cin >> n;
    vector<int> as(n);
    for (auto& a : as) {
        cin >> a;
    }
    auto q = partition(as, 0, n - 1);
    print_partition_ints(as, q);
    return 0;
}