#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> Input(int n) {
    vector<int> W(n);
    for (int &w : W) {
        cin >> w;
    }
    return W;
}

bool IsAllLoaded(int P, const vector<int>& W, int k) {
    int TrackIndex = 0, CurrentSum = 0;
    for (auto w : W) {
        if (w > P) return false;
        if (CurrentSum + w > P) {
            if (++TrackIndex == k) return false;
            CurrentSum = 0;
        }
        CurrentSum += w;
    }
    return true;
}

int Calc(vector<int>& W, int k) {
    int left = *max_element(W.begin(), W.end()), right = accumulate(W.begin(), W.end(), 0);
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (IsAllLoaded(mid, W, k)) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> W = Input(n);
    cout << Calc(W, k) << endl;
    return 0;
}