#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;
const int64 INF = 1LL << 58;

bool Find(const vector<int64>& sum, const int& pos, const int64& size) {
    int hoge = distance(sum.begin(), lower_bound(sum.begin() + pos + 1, sum.end(), sum[pos] + size));
    if (hoge == sum.size())
        return false;
    int fuga = distance(sum.begin(), lower_bound(sum.begin() + hoge + 1, sum.end(), sum[hoge] + size));
    if (fuga == sum.size())
        return false;
    int foo = distance(sum.begin(), lower_bound(sum.begin() + fuga + 1, sum.end(), sum[fuga] + size));
    return (foo != sum.size());
}

bool calc(const vector<int>& A, const vector<int64>& sum, int64 size) {
    int N = A.size();
    for (int pos = 0; pos < N; pos++) {
        if (Find(sum, pos, size))
            return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int64> sum(2 * N);
    partial_sum(A.begin(), A.end(), sum.begin());
    partial_sum(A.begin(), A.end(), sum.begin() + N);

    int64 low = 0, high = INF;
    while (high != low) {
        int64 mid = (low + high + 1) >> 1;
        if (calc(A, sum, mid))
            low = mid;
        else
            high = mid - 1;
    }
    cout << low << endl;
    return 0;
}