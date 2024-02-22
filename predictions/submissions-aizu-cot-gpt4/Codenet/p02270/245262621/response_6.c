#include <stdbool.h>
#include <stdio.h>
#define MAX_PACKET 100000
int weight[MAX_PACKET];
bool canAlloc(int num_packet, int num_track, long capacity);
int main(void) {
  int num_packet, num_track;
  scanf("%d %d", &num_packet, &num_track);
  long low = 0;
  long sum_weight = 0;
  for (int i = 0; i < num_packet; i++) {
    scanf("%d", &weight[i]);
    if (weight[i] > low) {
      low = weight[i];
    }
    sum_weight += weight[i];
  }
  long upp = sum_weight;
  while (low < upp) {
    long mid = (low + upp) / 2;
    if (canAlloc(num_packet, num_track, mid)) {
      upp = mid;
    } else {
      low = mid + 1;
    }
  }
  printf("%ld\n", low);
  return 0;
}
bool canAlloc(int num_packet, int num_track, long capacity) {
  long alloced_in_one = 0;
  int track_id = 0;
  for (int i = 0; i < num_packet; i++) {
    if (alloced_in_one + weight[i] <= capacity) {
      alloced_in_one += weight[i];
    } else {
      alloced_in_one = weight[i];
      if (++track_id == num_track) {
        return false;
      }
    }
  }
  return true;
}