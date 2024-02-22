#include <iostream>
#define MAX 2000000

int H, A[MAX + 1];

void maxHeap(int i) {
    while (true) {
        int l = 2 * i;
        int r = l + 1;
        int largest = i;

        if (l <= H && A[l] > A[i]) {
            largest = l;
        }
        if (r <= H && A[r] > A[largest]) {
            largest = r;
        }

        if (largest == i) {
            break;
        }

        std::swap(A[largest], A[i]);
        i = largest;
    }
}

int extract() {
    if (H < 1) {
        return -1; // Return a sentinel value when the heap is empty
    }

    int maxv = A[1];
    A[1] = A[H--];
    maxHeap(1);
    return maxv;
}

void insert(int key) {
    H++;
    A[H] = key;
    int i = H;

    while (i > 1 && A[i / 2] < A[i]) {
        std::swap(A[i], A[i / 2]);
        i = i / 2;
    }
}

int main() {
    std::string com;
    while (true) {
        std::cin >> com;
        if (com[0] == 'e' && com[1] == 'n') {
            break;
        }
        if (com[0] == 'i') {
            int key;
            std::cin >> key;
            insert(key);
        } else {
            std::cout << extract() << std::endl;
        }
    }

    return 0;
}