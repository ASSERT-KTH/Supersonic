#include <iostream>
#include <vector>
using namespace std;
int cnt;
vector<int> G;
void insertionSort(int *a, const int& g, const int& n) {
    for (int i = g; i < n; i++) {
        int v = a[i];
        int j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j = j - g;
            cnt++;
        }
        a[j + g] = v;
    }
}
void selectionSort(int *a, const int& n) {
    cnt = 0;
    for (int h = 1; h <= n; h = 3 * h + 1) {
        G.push_back(h);
    }
    for (int i = G.size() - 1; i >= 0; i--) {
        insertionSort(a, G[i], n);
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    selectionSort(a.data(), n);
    cout << G.size() << "\n";
    for (auto it = G.rbegin(); it != G.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n" << cnt << "\n";
    for (const int &i : a) {
        cout << i << "\n";
    }
    return 0;
}