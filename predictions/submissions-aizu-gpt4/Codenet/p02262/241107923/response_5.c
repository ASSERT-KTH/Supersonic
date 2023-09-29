#include <stdio.h>
#include <stdlib.h>

void ShellSort(int*, int);

int main(void) {
    int num, *arr;
    scanf("%d", &num);
    arr = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    ShellSort(arr, num);
    for (int i = 0; i < num; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}

void insertionSort(int *arr, int num, int h) {
    for (int i = h; i < num; i++) {
        int v = arr[i];
        int j = i - h;
        while (j >= 0 && arr[j] > v) {
            arr[j + h] = arr[j];
            j -= h;
        }
        arr[j + h] = v;
    }
}

void ShellSort(int* arr, int num) {
    int h = 1;
    while (h < num)
        h = 3 * h + 1;

    while (h >= 1) {
        h /= 3;
        insertionSort(arr, num, h);
    }
}