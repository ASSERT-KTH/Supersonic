#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 2000000
#define INFTY (1 << 30)

void maxHeap(std::vector<int>& A, int H, int i) {
    int l, r, large;
    while (true) {
        l = 2 * i;
        r = 2 * i + 1;
        if (l <= H && A[l] > A[i]) {
            large = l;
        } else {
            large = i;
        }
        if (r <= H && A[r] > A[large]) {
            large = r;
        }
        if (large == i) {
            break;
        }
        std::swap(A[large], A[i]);
        i = large;
    }
}

int extract(std::vector<int>& A, int& H) {
    if (H < 1) {
        return -INFTY;
    }
    int maxv = A[1];
    A[1] = A[H--];
    maxHeap(A, H, 1);
    return maxv;
}

void increasekey(std::vector<int>& A, int i, int key) {
    if (key < A[i]) {
        return;
    }
    A[i] = key;
    while (i > 1 && A[i / 2] < A[i]) {
        std::swap(A[i], A[i / 2]);
        i = i / 2;
    }
}

void insert(std::vector<int>& A, int& H, int key) {
    H++;
    A[H] = -INFTY;
    increasekey(A, H, key);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int H = 0;
    std::vector<int> A(MAX + 1);
    A.reserve(MAX + 1);

    char com[10];
    while (true) {
        std::cin.getline(com, 10);
        if (com[0] == 'e' && com[1] == 'n') {
            break;
        }
        if (com[0] == 'i') {
            int key;
            std::cin >> key;
            std::cin.ignore(); // Ignore the newline character
            insert(A, H, key);
        } else {
            std::cout << extract(A, H) << std::endl;
        }
    }

    return 0;
}