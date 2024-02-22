#include <stdio.h>

void insertionSort(int *, int, int, int *);
void ShellSort(int, int *);

int main(void) {
    int num, arr[100], i, count = 0; // Stack allocation for arr and count made local
    int h[20]; // h made local

    scanf("%d", &num);
    for (i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    ShellSort(num, arr);

    printf("%d\n", count);
    for (i = 0; i < num; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

void ShellSort(int num, int *arr) {
    int i, j, n, m, temp = 0; // temp made local
    int h[20]; // h made local

    h[0] = 1;
    for (i = 0; i < 20; i++) {
        h[i + 1] = 3 * h[i] + 1;
        if (num < h[i + 1]) { // Avoid unnecessary computation
            temp = i;
            break;
        }
    }

    for (i = temp; i >= 0; i--) {
        insertionSort(arr, num, h[i], &count);
    }
}

void insertionSort(int *arr, int num, int h, int *count) {
    int i, j, v;
    for (i = h; i < num; i++) {
        v = arr[i];
        j = i - h;
        while (j >= 0 && arr[j] > v) {
            arr[j + h] = arr[j];
            j = j - h;
            (*count)++;
        }
        arr[j + h] = v;
    }
}