#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& a, int g, int& cnt) {
    int n = a.size();
    for (int i = g - 1; i < n; i++) {
        int j = i;
        while (j - g >= 0 && a[j - g] > a[j]) {
            swap(a[j], a[j - g]);
            j = j - g;
            cnt++;
        }
    }
}

void shellSort(vector<int>& a) {
    int n = a.size();
    vector<int> G;
    G.reserve(20); // assuming the size won't exceed 20
    int cnt = 0;

    for (int h = 1;;) {
        if (h > n)
            break;
        G.push_back(h);
        h = 3 * h + 1;
    }

    for (int i = G.size() - 1; i >= 0; i--) {
        insertionSort(a, G[i], cnt);
    }

    cout << G.size() << endl;
    for (int i = G.size() - 1; i >= 0; i--) {
        if (i != G.size() - 1) cout << " ";
        cout << G[i];
    }
    cout << endl;
    cout << cnt << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    shellSort(a);

    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}