#include <iostream>
#include <vector>

void insertionSort(int *a, int g, int n, int& cnt) {
    for (int i = g - 1; i < n; i++) {
        int j = i;
        while (j - g >= 0 && a[j - g] > a[j]) {
            std::swap(a[j], a[j - g]);
            j = j - g;
            cnt++;
        }
    }
}

void selectionSort(int *a, size_t n) {
    int cnt = 0;
    std::vector<int> G;
    for (int h = 1; h <= n; h = 3 * h + 1) {
        G.push_back(h);
    }
    for (size_t i = G.size() - 1; i < G.size(); i--) {
        insertionSort(a, G[i], n, cnt);
    }
    std::cout << G.size() << std::endl;
    std::cout << G.back();
    for (size_t i = G.size() - 2; i < G.size(); i--) {
        std::cout << " " << G[i];
    }
    std::cout << std::endl;
    std::cout << cnt << std::endl;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    selectionSort(a.data(), n);
    for (size_t i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}