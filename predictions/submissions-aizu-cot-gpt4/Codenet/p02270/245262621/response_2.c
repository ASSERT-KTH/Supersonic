#include <stdbool.h>
#include <stdio.h>
#define MAX_PACKET 100000
bool canAlloc(int weight[MAX_PACKET], int num_packet, int num_track, long capacity);

int main(void) {
  register int i;
  int num_packet, num_track;
  int weight[MAX_PACKET];
  
  scanf("%d %d", &num_packet, &num_track);
  
  register int max_weight = 0;
  register long sum_weight = 0;
  
  for (i = 0; i < num_packet; ++i) {
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
    if (canAlloc(weight, num_packet, num_track, mid)) {
      upp = mid;
    } else {
      low = mid + 1;
    }
  }
  
  printf("%ld\n", low);
  return 0;
}

bool canAlloc(int weight[MAX_PACKET], int num_packet, int num_track, long capacity) {
  register long i = 0;
  register long alloced_in_one = 0;
  register int track_id = 0;
  
  for (i = 0; i < num_packet; ++i) {
    if (alloced_in_one + weight[i] <= capacity) {
      alloced_in_one += weight[i];
    } else {
      alloced_in_one = 0;
      --i;
      if (++track_id == num_track) {
        return false;
      }
    }
  }
  
  return true;
}