#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(vector<int> &v) {
    int n = v.size();
    int k = *max_element(v.begin(), v.end());
    int cnt[k + 1] = {0};

    for (int x : v)
        cnt[x]++;
    for (int i = 1; i <= k; i++)
        cnt[i] += cnt[i - 1];

    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[cnt[v[i]] - 1] = v[i];
        cnt[v[i]]--;
    }

    v = output;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    counting_sort(A);
    cout << A[0];
    for (int i = 1; i < A.size(); i++) {
        cout << " " << A[i];
    }
    cout << endl;
    return 0;
}