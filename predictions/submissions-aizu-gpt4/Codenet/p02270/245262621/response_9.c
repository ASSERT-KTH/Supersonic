#include <stdio.h>
#define MAX_PACKET 100000
int num_packet, num_track;
int weight[MAX_PACKET];

inline bool canAlloc(long capacity) {
  int i = 0, track_id = 0;
  long alloced_in_one = 0;
  while(i < num_packet) {
    if ((alloced_in_one += weight[i]) <= capacity) {
      i++;
    } else {
      alloced_in_one = 0;
      if (++track_id == num_track)
        return false;
    }
  }
  return true;
}

int main(void) {
  scanf("%d %d", &num_packet, &num_track);
  int max_weight = 0;
  long sum_weight = 0;
  for (int i = 0; i < num_packet; i++) {
    scanf("%d", &weight[i]);
    if (weight[i] > max_weight)
      max_weight = weight[i];
    sum_weight += weight[i];
  }
  long low = max_weight, upp = sum_weight;
  while (low < upp) {
    long mid = low + ((upp - low) >> 1);
    if (canAlloc(mid))
      upp = mid;
    else
      low = mid + 1;
  }
  printf("%ld\n", low);
  return 0;
}