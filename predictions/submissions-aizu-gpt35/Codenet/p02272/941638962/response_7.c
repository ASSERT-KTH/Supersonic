#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int l, int m, int r, long long* count)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(sizeof(int) * n1);
    int* R = (int*)malloc(sizeof(int) * n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            (*count) += n1 - i;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int* arr, int l, int r, long long* count)
{
    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);

        merge(arr, l, m, r, count);
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long count = 0;
    mergeSort(arr, 0, n - 1, &count);

    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n%lld\n", count);

    free(arr);
    return 0;
}