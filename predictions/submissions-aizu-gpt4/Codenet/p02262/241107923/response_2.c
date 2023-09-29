#include <vector>
#include <iostream>
#include <algorithm>

void insertionSort(std::vector<int>& arr, int h) {
    int num = arr.size();
    for (int i = h; i < num; i++) {
        int v = arr[i];
        int j = i - h;
        while (j >= 0 && arr[j] > v) {
            arr[j + h] = arr[j];
            j = j - h;
        }
        arr[j + h] = v;
    }
}

void shellSort(std::vector<int>& arr) {
    std::vector<int> h = {1};
    while(h.back() < arr.size()) {
        h.push_back(3 * h.back() + 1);
    }
    h.pop_back();

    for (int i = h.size() - 1; i >= 0; --i) {
        insertionSort(arr, h[i]);
    }
}

int main() {
    int num;
    std::cin >> num;
    std::vector<int> arr(num);
    for (int i = 0; i < num; i++)
        std::cin >> arr[i];
    shellSort(arr);
    for (int i = 0; i < num; i++) {
        std::cout << arr[i] << "\n";
    }
    return 0;
}