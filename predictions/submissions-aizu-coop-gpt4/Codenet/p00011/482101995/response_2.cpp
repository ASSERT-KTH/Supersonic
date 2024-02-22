#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int w, n;
    cin >> w >> n;

    unordered_map<int, int> swaps;

    for (int i = 0; i < n; i++) {
        int left, right;
        char dummy;
        cin >> left >> dummy >> right;
        if(swaps.find(left) == swaps.end())
            swaps[left] = left;
        if(swaps.find(right) == swaps.end())
            swaps[right] = right;
        swap(swaps[left], swaps[right]);
    }

    for (int i = 1; i <= w; i++) {
        if(swaps.find(i) != swaps.end())
            cout << swaps[i] << endl;
        else
            cout << i << endl;
    }

    return 0;
}