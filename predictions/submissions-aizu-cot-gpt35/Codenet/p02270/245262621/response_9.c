#include <stdio.h>

int canAlloc(int num_packet, int num_track, int weight[], int capacity);
int main(void) {
  int num_packet;
  int num_track;
  scanf("%d %d", &num_packet, &num_track);
  int max_weight = 0;
  long sum_weight = 0;
  int weight[num_packet];
  for (int i = 0; i < num_packet; i++) {
    scanf("%d", &weight[i]);
    if (weight[i] > max_weight) {
      max_weight = weight[i];
    }
    sum_weight += weight[i];
  }
  int low = max_weight;
  int upp = sum_weight;
  while (low < upp) {
    int mid = (low + upp) / 2;
    if (canAlloc(num_packet, num_track, weight, mid)) {
      upp = mid;
    } else {
      low = mid + 1;
    }
  }
  printf("%d\n", low);
  return 0;
}

int canAlloc(int num_packet, int num_track, int weight[], int capacity) {
  int alloced_in_one = 0;
  int track_id = 0;
  for (int i = 0; i < num_packet; i++) {
    if (alloced_in_one + weight[i] <= capacity) {
      alloced_in_one += weight[i];
    } else {
      alloced_in_one = 0;
      i--;
      if (++track_id == num_track) {
        return 0;
      }
    }
  }
  return 1;
}