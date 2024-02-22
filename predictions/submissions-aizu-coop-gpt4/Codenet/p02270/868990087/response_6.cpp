#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<int>& N, int k, int mid) {
    int sum = 0;
    int count = 1;
    for (int i = 0; i < N.size(); ++i) {
        if (N[i] > mid) return false;
        sum += N[i];
        if (sum > mid) {
            sum = N[i];
            ++count;
        }
    }
    return count <= k;
}

int main() {
    int MAX_W = 1000000000;
    int n, k;
    cin >> n >> k;
    vector<int> N(n);
    for (int i = 0; i < n; ++i) {
        cin >> N[i];
    }
    int left = *max_element(N.begin(), N.end());
    int right = MAX_W;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(N, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << right << endl;
    return 0;
}