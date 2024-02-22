#include <stdio.h>

#define MAX_PACKET 100000

int num_packet;
int num_track;
int weight[MAX_PACKET];

bool canAlloc(long capacity);

int main(void) {
  scanf("%d %d", &num_packet, &num_track);

  int max_weight = 0;
  long sum_weight = 0;

  for (int i = 0; i < num_packet; i++) {
    scanf("%d", &weight[i]);
    max_weight = (weight[i] > max_weight) ? weight[i] : max_weight;
    sum_weight += weight[i];
  }

  long low = max_weight;
  long upp = sum_weight;

  while (low < upp) {
    long mid = low + (upp - low) / 2;
    if (canAlloc(mid)) {
      upp = mid;
    } else {
      low = mid + 1;
    }
  }

  printf("%ld\n", low);
  return 0;
}

bool canAlloc(long capacity) {
  int counter = 0;
  long remaining_capacity = capacity;

  for (int i = 0; i < num_packet; i++) {
    if (weight[i] > capacity) {
      return false;
    }

    if (weight[i] <= remaining_capacity) {
      remaining_capacity -= weight[i];
    } else {
      remaining_capacity = capacity - weight[i];
      if (++counter == num_track) {
        return false;
      }
    }
  }

  return true;
}