#include <stdbool.h>
#include <stdio.h>

#define MAX_PACKET 100000

bool canAlloc(long capacity, int num_packet, int* weight);

int main(void) {
  int num_packet;
  int num_track;
  int weight[MAX_PACKET];

  scanf("%d %d", &num_packet, &num_track);

  int max_weight = 0;
  long sum_weight = 0;

  for (int i = 0; i < num_packet; i++) {
    scanf("%d", &weight[i]);

    if (weight[i] > max_weight) {
      max_weight = weight[i];
    }

    sum_weight += weight[i];
  }

  long low = max_weight;
  long upp = sum_weight;

  while (low < upp) {
    long mid = (low + upp) / 2;

    if (canAlloc(mid, num_packet, weight)) {
      upp = mid;
    } else {
      low = mid + 1;
    }
  }

  printf("%ld\n", low);

  return 0;
}

bool canAlloc(long capacity, int num_packet, int* weight) {
  long remaining_weight = 0;
  int track_id = 0;

  for (int i = 0; i < num_packet; i++) {
    if (remaining_weight + weight[i] <= capacity) {
      remaining_weight += weight[i];
    } else {
      remaining_weight = 0;
      i--;

      if (++track_id == num_track) {
        return false;
      }
    }

    if (remaining_weight < capacity) {
      break;
    }
  }

  return true;
}