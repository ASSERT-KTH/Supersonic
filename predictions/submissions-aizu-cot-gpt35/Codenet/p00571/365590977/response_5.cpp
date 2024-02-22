#include <stdio.h>

struct Data {
  long long size;
  long long value;
};

void countingSort(Data* art, int N) {
  const int MAX_SIZE = 1000001;
  int counts[MAX_SIZE] = {0};
  for (int i = 0; i < N; ++i) {
    ++counts[art[i].size];
  }
  int index = 0;
  for (int size = 0; size < MAX_SIZE; ++size) {
    while (counts[size] > 0) {
      art[index].size = size;
      ++index;
      --counts[size];
    }
  }
}

int main(void) {
  int N;
  scanf("%d", &N);

  Data art[N];
  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }

  countingSort(art, N);

  long long min_size = art[0].size;
  long long sum_value = art[0].value;
  long long ans = art[0].value;

  for (int i = 1; i < N; ++i) {
    long long value = art[i].value;
    long long size = art[i].size;
    long long tmp = sum_value + value - (size - min_size);
    if (tmp < value) {
      ans = value;
      sum_value = value;
      min_size = size;
    } else {
      ans = tmp;
      sum_value += value;
    }
  }

  printf("%lld\n", ans);
  return 0;
}