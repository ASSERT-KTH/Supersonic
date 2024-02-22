#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);

int main() {
    int N, Q;
    ll T;
    cin >> N >> T >> Q;
    
    vector<ll> A(N);
    vector<int> D(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> D[i];
    }
    
    vector<ll> people(Q);
    
    for (int i = 0; i < Q; i++) {
        cin >> people[i];
        people[i]--;
    }
    
    ll east = MIN;
    ll west = MIN;
    ll t;
    
    if (D[people[0]] == 1) {
        east = A[people[0]];
        for (ll j = people[0] + 1; j < N; j++) {
            if (D[j] == 1) {
                east = A[j];
            } else {
                t = (east + A[j]) / 2;
                break;
            }
        }
    } else {
        west = A[people[0]];
        for (ll j = people[0] - 1; j >= 0; j--) {
            if (D[j] == 1) {
                t = (west + A[j]) / 2;
                break;
            } else {
                west = A[j];
            }
        }
    }
    
    for (int i = 0; i < Q; i++) {
        if (D[people[i]] == 1) {
            if (T < std::abs(t - A[people[i]])) {
                cout << A[people[i]] + T << endl;
            } else {
                cout << t << endl;
            }
        } else {
            if (T < std::abs(A[people[i]] - t)) {
                cout << A[people[i]] - T << endl;
            } else {
                cout << t << endl;
            }
        }
    }
    
    return 0;
}