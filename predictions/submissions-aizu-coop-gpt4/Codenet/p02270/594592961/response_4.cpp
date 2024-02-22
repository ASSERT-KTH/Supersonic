#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<int> Input(const int n) {
    vector<int> W;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        W.push_back(w);
    }
    return W;
}

bool IsAllLoaded(int P, const vector<int>& W, int k) { // pass vector by reference
    int TrackIndex = 0;
    int CurrentSum = 0;
    for (int i = 0; i < W.size(); i++) {
        if (W[i] > P) {
            return false;
        }
        if (CurrentSum + W[i] > P) {
            TrackIndex++;
            if (TrackIndex == k) {
                return false;
            }
            CurrentSum = 0;
        }
        CurrentSum += W[i];
    }
    return true;
}

int Calc(vector<int>& W, int k) { // pass vector by reference
    int Sum = accumulate(W.begin(), W.end(), 0);
    int P_min = *max_element(W.begin(), W.end());
    int P_max = Sum;
    while (P_min < P_max) { // binary search for minimum P
        int P_mid = P_min + (P_max - P_min) / 2;
        if (IsAllLoaded(P_mid, W, k)) {
            P_max = P_mid;
        } else {
            P_min = P_mid + 1;
        }
    }
    return P_min;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> W = Input(n);
    int P = Calc(W, k);
    cout << P << endl;
    return 0;
}