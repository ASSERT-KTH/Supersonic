#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& A, int left, int mid, int right) {
    vector<int> L(A.begin() + left, A.begin() + mid);
    vector<int> R(A.begin() + mid, A.begin() + right);
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    int i = 0, j = 0, cnt = 0;
    for (int k = left; k < right; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
        ++cnt;
    }
    return cnt;
}

int mergesort(vector<int>& A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        int cnt = mergesort(A, left, mid);
        cnt += mergesort(A, mid, right);
        cnt += merge(A, left, mid, right);
        return cnt;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    vector<int> S(N);
    for (int& x : S) cin >> x;
    int cnt = mergesort(S, 0, N);
    copy(S.begin(), S.end() - 1, ostream_iterator<int>(cout, " "));
    cout << S.back() << "\n" << cnt << endl;
    return 0;
}