#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& a, int g, int& cnt) {
    int n = a.size();
    for (int i = g; i < n; i++) {
        int j = i;
        int jMinusG = j - g;
        while (jMinusG >= 0 && a[jMinusG] > a[j]) {
            swap(a[j], a[jMinusG]);
            j = jMinusG;
            jMinusG = j - g;
            cnt++;
        }
    }
}

void shellSort(vector<int>& a) {
    int n = a.size();
    int cnt = 0;
    int h = 1;
    while (h <= n) {
        insertionSort(a, h, cnt);
        h = 3 * h + 1;
    }
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