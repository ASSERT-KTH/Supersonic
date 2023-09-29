#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<int>& N, int k, int w) {
    int sum = 0;
    int count = 1;
    for(int weight : N) {
        if(sum + weight > w) {
            sum = weight;
            count++;
            if(count > k) return false;
        } else {
            sum += weight;
        }
    }
    return true;
}

int main() {
    int MAX_W = 1000000000;
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> N(n);
    int left = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &N[i]);
        left = max(left, N[i]);
    }
    int right = MAX_W;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(N, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    printf("%d\n", right);
    return 0;
}