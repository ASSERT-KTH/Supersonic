#include <iostream>
#include <vector>
#include <algorithm>

int cnt;
std::vector<int> G;

void insertionSort(std::vector<int>& a, int g, int n) {
    for (int i = g - 1; i < n; i++) {
        int j = i;
        while (j - g >= 0 && a[j - g] > a[j]) {
            std::swap(a[j], a[j - g]);
            j = j - g;
            cnt++;
        }
    }
}

void selectionSort(std::vector<int>& a, int n) {
    cnt = 0;
    for (int h = 1;;) {
        if (h > n)
            break;
        G.push_back(h);
        h = 3 * h + 1;
    }
    for (int i = G.size() - 1; i >= 0; i--) {
        insertionSort(a, G[i], n);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    selectionSort(a, n);
    std::cout << G.size() << std::endl;
    std::cout << G.back();
    for (auto it = G.rbegin() + 1; it != G.rend(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
    std::cout << cnt << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << std::endl;
    }
    return 0;
}