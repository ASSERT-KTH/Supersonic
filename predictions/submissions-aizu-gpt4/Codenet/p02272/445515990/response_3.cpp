#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int merge(vector<int>& A, int left, int mid, int right) {
    int i, j, cnt = 0;
    vector<int> L(A.begin() + left, A.begin() + mid);
    vector<int> R(A.begin() + mid, A.begin() + right);
    i = 0;
    j = 0;
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
        cnt++;
    }
    return cnt;
}

int mergesort(vector<int>& A, int left, int right) {
    int mid, cnt = 0;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        cnt += mergesort(A, left, mid);
        cnt += mergesort(A, mid, right);
        cnt += merge(A, left, mid, right);
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    vector<int> S(N);
    for (int& num : S) {
        cin >> num;
    }
    int cnt = mergesort(S, 0, N);
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << S[i];
    }
    cout << "\n" << cnt << "\n";
    return 0;
}