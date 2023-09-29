#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<int>& N, int k, int w) {
    int s = 0;
    int trucks = 1;
    for (auto& weight : N) {
        if (s + weight <= w) {
            s += weight;
        } else {
            s = weight;
            if (++trucks > k) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  
    int MAX_W = 1000000000;
    int n, k;
    cin >> n >> k;
    vector<int> N(n);
    int maxWeight = 0;
    for (int i = 0; i < n; ++i) {
        cin >> N[i];
        maxWeight = max(maxWeight, N[i]);
    }
    int left = maxWeight;
    int right = MAX_W;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(N, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << right << '\n';
    return 0;
}