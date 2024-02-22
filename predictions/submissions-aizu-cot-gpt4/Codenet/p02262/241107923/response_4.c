#include <stdio.h>
#include <vector>

void insertionSort(std::vector<int>& arr, int num, int h, int& count) {
    int i, j, v;
    for (i = h; i < num; i++) {
        v = arr[i];
        int j_plus_h = i - h;
        j = j_plus_h;
        while (j >= 0 && arr[j] > v) {
            arr[j_plus_h] = arr[j];
            j -= h;
            j_plus_h -= h;
            count++;
        }
        arr[j_plus_h] = v;
    }
}

void ShellSort(std::vector<int>& arr, int num, std::vector<int>& h, int& count) {
    int temp, temp_temp;
    h[0] = 1;
    for (int i = 0; i < 19; i++) {
        h[i + 1] = 3 * h[i] + 1;
    }
    for (int i = 0; i < 20; i++) {
        if (num < h[i]) {
            temp = i - 1;
            break;
        }
    }
    for (int i = temp; i != -1; i--) {
        if (i == temp) {
            temp_temp = temp;
        }
        insertionSort(arr, num, h[i], count);
    }
}

int main(void) {
    int num, count = 0;
    scanf("%d", &num);
    std::vector<int> arr(num);
    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    std::vector<int> h(20);
    ShellSort(arr, num, h, count);
    printf("%d\n", h[h.size()-1] + 1);
    for (int i = h.size()-1; i >= 0; i--)
        printf("%d ", h[i]);
    printf("\n%d\n", count);
    for (int i = 0; i < num; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}