#include <stdio.h>

#define MAX_PACKET 100000

int num_packet;
int num_track;
int weight[MAX_PACKET];

bool canAlloc(int capacity);

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] > pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quicksort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

int main(void) {
  scanf("%d %d", &num_packet, &num_track);

  int max_weight = 0;
  int sum_weight = 0;

  for (int i = 0; i < num_packet; i++) {
    scanf("%d", &weight[i]);
    if (weight[i] > max_weight) {
      max_weight = weight[i];
    }
    sum_weight += weight[i];
  }

  quicksort(weight, 0, num_packet - 1);

  int low = max_weight;
  int upp = sum_weight;

  while (low < upp) {
    int mid = (low + upp) / 2;
    if (canAlloc(mid)) {
      upp = mid;
    } else {
      low = mid + 1;
    }
  }

  printf("%d\n", low);
  return 0;
}

bool canAlloc(int capacity) {
  int alloced_in_one = 0;
  int track_id = 0;

  for (int i = 0; i < num_packet; i++) {
    if (alloced_in_one + weight[i] <= capacity) {
      alloced_in_one += weight[i];
    } else {
      alloced_in_one = 0;
      i--;
      if (++track_id == num_track) {
        return false;
      }
    }
  }

  return true;
}