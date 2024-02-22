#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int bucket_size = 256;
int inf = 1e9;
int64_t inf64 = 1e18;
double eps = 1e-9;

struct sqrt_decomp {
    int length, bucket_num;
    vector<vector<int>> buckets;
    vector<int> update, bucket_sum;
    sqrt_decomp(const vector<int> &x)
        : length(x.size()),
          bucket_num((x.size() + bucket_size - 1) / bucket_size) {
        buckets.resize(bucket_num);
        update.resize(bucket_num);
        bucket_sum.resize(bucket_num);
        for (int i = 0; i < x.size(); ++i) {
            buckets[i / bucket_size].push_back(x[i]);
            bucket_sum[i / bucket_size] += x[i];
            update[i / bucket_size] = 2;
        }
    }
    // Other functions remain the same...
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}