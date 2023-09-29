#include <stdbool.h>
#include <stdio.h>
#define MAX_PACKET 100000
int num_packet;
int num_track;
int weight[MAX_PACKET];
bool canAlloc(long capacity);
int main(void) {
  int i;
  scanf("%d %d", &num_packet, &num_track);
  int max_weight = 0;
  long sum_weight = 0;
  for (i = 0; i < num_packet; i++) {
    scanf("%d", &weight[i]);
    if (weight[i] > max_weight) {
      max_weight = weight[i];
    }
    sum_weight += weight[i];
  }
  long low = max_weight;
  int upp = sum_weight;
  while (low < upp) {
    long mid = (low + upp) / 2;
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
  long i = 0;
  long alloced_in_one = 0;
  int track_id = 0;
  for (i = 0; i < num_packet; i++) {
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
