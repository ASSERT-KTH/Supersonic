#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        size_t n;
        cin >> n;
        if (!n)
            break;

        long long s = 0, a = 0;
        multiset<long long> nums;
        for (size_t i = 0; i < n; ++i) {
            long long num;
            cin >> num;
            s += num;
            nums.insert(num);
        }

        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            a = max(a, n * s);
            s -= *it;
            --n;
        }
        cout << a << endl;
    }

    return 0;
}