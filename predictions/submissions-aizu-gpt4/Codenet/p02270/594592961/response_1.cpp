#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> W(n);
    for(int& w : W) cin >> w;
    
    int left = *max_element(W.begin(), W.end()), right = accumulate(W.begin(), W.end(), 0);
    while(left < right) {
        int mid = left + (right - left) / 2, required = 1, current = 0;
        for(int& w : W) {
            if(current + w > mid) {
                required++;
                current = 0;
            }
            current += w;
        }

        if(required <= k) right = mid;
        else left = mid + 1;
    }
    cout << left << endl;
    return 0;
}