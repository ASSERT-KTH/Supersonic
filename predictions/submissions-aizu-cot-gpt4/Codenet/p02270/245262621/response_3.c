#include <stdbool.h>
#include <stdio.h>
#define MAX_PACKET 100000
int num_packet;
int num_track;
int weight[MAX_PACKET];
bool canAlloc(long capacity);

int main(void) {
  scanf("%d %d", &num_packet, &num_track);
  long sum_weight = 0;
  for (int i = 0; i < num_packet; i++) {
    scanf("%d", &weight[i]);
    sum_weight += weight[i];
  }
  long low = 0, upp = sum_weight;
  for (int i = 0; i < num_packet; i++) {
    if (weight[i] > low) {
      low = weight[i];
    }
  }
  
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
  long alloced_in_one = 0;
  int track_id = 0;
  for (int i = 0; i < num_packet;) {
    if (alloced_in_one + weight[i] <= capacity) {
      alloced_in_one += weight[i];
      i++;
    } else {
      alloced_in_one = 0;
      if (++track_id == num_track) {
        return false;
      }
    }
  }
  return true;
}