#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)

struct Heap {
    int H, A[MAX + 1];
    void maxHeapify(int i) {
        int l = 2 * i;
        int r = 2 * i + 1;
        int largest = (l <= H && A[l] > A[i]) ? l : i;
        if (r <= H && A[r] > A[largest]) largest = r;
        if (largest != i) {
            swap(A[largest], A[i]);
            maxHeapify(largest);
        }
    }
    int extractMax() {
        if (H < 1) return -INFTY;
        int maxVal = A[1];
        A[1] = A[H--];
        maxHeapify(1);
        return maxVal;
    }
    void increaseKey(int i, int key) {
        if (key < A[i]) return;
        A[i] = key;
        while (i > 1 && A[i / 2] < A[i]) {
            swap(A[i], A[i / 2]);
            i = i / 2;
        }
    }
    void insertKey(int key) {
        A[++H] = -INFTY;
        increaseKey(H, key);
    }
};

int main() {
    int key;
    char command[10];
    Heap heap;
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "end") == 0) break;
        if (strcmp(command, "insert") == 0) {
            scanf("%d", &key);
            heap.insertKey(key);
        } else {
            printf("%d\n", heap.extractMax());
        }
    }
    return 0;
}