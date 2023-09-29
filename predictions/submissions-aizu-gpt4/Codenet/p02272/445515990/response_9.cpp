#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> S;
long long cnt;

void merge(int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1 + 1), R(n2 + 1);
    copy(S.begin() + left, S.begin() + mid, L.begin());
    copy(S.begin() + mid, S.begin() + right, R.begin());
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            S[k] = L[i++];
        } else {
            S[k] = R[j++];
        }
        ++cnt;
    }
}

void mergesort(int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergesort(left, mid);
        mergesort(mid, right);
        merge(left, mid, right);
    }
}

int main() {
    int N, num;
    cin >> N;
    S.reserve(N);
    for (int i = 0; i < N; i++) {
        cin >> num;
        S.push_back(num);
    }
    mergesort(0, N);
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << S[i];
    }
    cout << "\n" << cnt << "\n";
    return 0;
}