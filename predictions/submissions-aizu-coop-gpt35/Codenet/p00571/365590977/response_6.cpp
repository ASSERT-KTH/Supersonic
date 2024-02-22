#include <stdio.h>

typedef long long llong;

struct Data {
  llong size;
  llong value;
};

llong Max(llong a, llong b) {
  return a > b ? a : b;
}

void quicksort(Data* arr, int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
  }
}

int partition(Data* arr, int low, int high) {
  Data pivot = arr[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (arr[j].size < pivot.size) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

int main(void) {
  int N;
  scanf("%d", &N);

  Data* art = new Data[N];

  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }

  quicksort(art, 0, N - 1);

  llong min_size = art[0].size;
  llong sum_value = art[0].value;
  llong ans = art[0].value;

  for (int i = 1; i < N; ++i) {
    llong value = art[i].value;
    llong size = art[i].size;
    llong tmp = sum_value + value - (size - min_size);
    if (tmp < value) {
      ans = Max(ans, value);
      sum_value = value;
      min_size = size;
    } else {
      ans = Max(ans, tmp);
      sum_value += value;
    }
  }

  printf("%lld\n", ans);

  delete[] art;

  return 0;
}