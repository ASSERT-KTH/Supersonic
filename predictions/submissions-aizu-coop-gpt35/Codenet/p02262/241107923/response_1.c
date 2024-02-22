#include <stdio.h>
#include <stdlib.h>

void quickSort(int *, int, int *);
void insertionSort(int *, int, int *);

int main(void) {
  int num, *arr, i;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  quickSort(arr, num, NULL);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  return 0;
}

void quickSort(int *arr, int num, int *count) {
  if (num <= 1)
    return;
  int pivot = arr[num/2];
  int i, j;
  for (i = 0, j = num - 1;; i++, j--) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i >= j)
      break;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    if (count != NULL)
      (*count)++;
  }
  quickSort(arr, i, count);
  quickSort(arr + i, num - i, count);
}