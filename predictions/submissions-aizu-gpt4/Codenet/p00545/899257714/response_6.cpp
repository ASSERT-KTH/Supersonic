#include <iostream>
#include <limits.h>
using namespace std;
using ll = long long;
constexpr ll MIN = -(LLONG_MAX - 1);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    ll T;
    cin >> N >> T >> Q;
    ll people[1001];
    ll A[100001];
    int D[100001];
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> D[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> people[i];
        people[i]--;
    }
    ll east;
    ll t;
    for (int i = 0; i < Q; i++) {
        if (D[people[i]] == 1) {
            east = A[people[i]];
            for (ll j = people[i] + 1; j < N; j++) {
                if (D[j] != 1) {
                    t = (east + A[j]) / 2;
                    break;
                }
                east = A[j];
            }
            if (T < abs(t - A[people[i]])) {
                cout << A[people[i]] + T << '\n';
            } else {
                cout << t << '\n';
            }
        } else {
            ll west = A[people[i]];
            for (ll j = people[i] - 1; j >= 0; j--) {
                if (D[j] == 1) {
                    t = (west + A[j]) / 2;
                    break;
                }
                west = A[j];
            }
            if (T < abs(A[people[i]] - t)) {
                cout << A[people[i]] - T << '\n';
            } else {
                cout << t << '\n';
            }
        }
    }
    return 0;
}