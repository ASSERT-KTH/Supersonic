#include <iostream>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 58;

bool Find(const long long* sum, int N, int pos, long long size) {
    int low = pos + 1;
    int high = N + pos;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sum[mid] - sum[pos] >= size)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return (sum[low] - sum[pos] == size);
}

bool calc(const long long* sum, int N, long long size) {
    for (int pos = 0; pos < N; pos++) {
        if (Find(sum, N, pos, size))
            return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    long long* A = new long long[2 * N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[N + i] = A[i];
    }

    long long* sum = new long long[2 * N];
    sum[0] = A[0];
    for (int i = 1; i < 2 * N; i++) {
        sum[i] = sum[i - 1] + A[i];
    }

    long long low = 0, high = INF;
    while (high != low) {
        long long mid = (low + high + 1) / 2;
        if (calc(sum, N, mid))
            low = mid;
        else
            high = mid - 1;
    }

    cout << low << endl;

    delete[] A;
    delete[] sum;

    return 0;
}