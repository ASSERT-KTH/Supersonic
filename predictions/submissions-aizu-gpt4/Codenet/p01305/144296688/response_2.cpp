#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    array<int, 9> a, b;
    int win[2] = {0, 0};

    while(n--) {
        for(auto& e : a) cin >> e;
        for(auto& e : b) cin >> e;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        do {
            int score[] = {0, 0};
            for(int i=0; i<9; i++) {
                if(a[i] > b[i]) score[0] += a[i] + b[i];
                else score[1] += a[i] + b[i];
            }
            win[score[0] < score[1]]++;
        } while(next_permutation(b.begin(), b.end()));
    }

    double total = 1;
    for(int i=1; i<=9; i++) total *= i;

    cout.precision(5);
    cout << fixed << win[0] / total << " " << win[1] / total << "\n";

    return 0;
}