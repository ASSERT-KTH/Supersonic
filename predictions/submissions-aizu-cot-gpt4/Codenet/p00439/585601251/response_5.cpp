#include <iostream>
#include <deque>
#include <climits>
using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k, n) {
        long long current_sum = 0, max_sum = -LLONG_MAX;
        deque<int> q;
        for (int i = 1; i <= n; ++i) {
            int num;
            cin >> num;
            current_sum += num;
            q.push_back(num);
            if (i > k) {
                current_sum -= q.front();
                q.pop_front();
            }
            max_sum = max(max_sum, current_sum);
        }
        cout << max_sum << endl;
    }
    return 0;
}