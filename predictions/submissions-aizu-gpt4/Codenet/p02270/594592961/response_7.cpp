#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsAllLoaded(int P, const vector<int>& W, int k) {
    int TrackIndex = 0;
    int CurrentSum = 0;
    for (int w : W) {
        if (w > P) {
            return false;
        }
        if (CurrentSum + w > P) {
            TrackIndex++;
            if (TrackIndex == k) {
                return false;
            }
            CurrentSum = w;
        } else {
            CurrentSum += w;
        }
    }
    return true;
}

int Calc(vector<int>& W, int k) {
    int Sum = accumulate(W.begin(), W.end(), 0);
    int P = max((Sum + k - 1) / k, *max_element(W.begin(), W.end()));
    while (!IsAllLoaded(P, W, k)) {
        P++;
    }
    return P;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> W(n);
    for (int& w : W) {
        cin >> w;
    }
    int P = Calc(W, k);
    cout << P << '\n';
    return 0;
}