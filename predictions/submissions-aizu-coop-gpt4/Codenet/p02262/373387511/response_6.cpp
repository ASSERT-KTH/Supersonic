#include <iostream>
#include <deque>
#include <utility>
using namespace std;

const int maxN = 1e6;
int cnt;
deque<int> G;
int gaps[maxN];

void computeGaps(int n) {
    int h = 1, i = 0;
    while (h <= n) {
        gaps[i++] = h;
        h = 3 * h + 1;
    }
    G.assign(gaps, gaps + i);
}

int insertionSort(int *a, int g, int n) {
    int cnt = 0;
    for (int i = g - 1; i < n; i++) {
        int j = i;
        while (j - g >= 0 && a[j - g] > a[j]) {
            std::swap(a[j], a[j - g]);
            j = j - g;
            cnt++;
        }
    }
    return cnt;
}

void shellSort(int *a, int n) {
    cnt = 0;
    computeGaps(n);
    for (int i = G.size() - 1; i >= 0; i--) {
        cnt += insertionSort(a, G[i], n);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    shellSort(a, n);
    cout << G.size() << endl;
    cout << G[G.size() - 1];
    for (int i = G.size() - 2; i >= 0; i--) {
        cout << " " << G[i];
    }
    cout << endl;
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}