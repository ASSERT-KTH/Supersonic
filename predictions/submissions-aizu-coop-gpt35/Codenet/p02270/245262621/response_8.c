#include <stdio.h>
#define MAX_PACKET 100000
int num_packet;
int num_track;
int weight[MAX_PACKET];
int canAlloc(long capacity);

int main(void) {
  int i;
  scanf("%d %d", &num_packet, &num_track);
  int max_weight = 0;
  long sum_weight = 0;

  // Calculate maximum weight and sum of all weights
  scanf("%d", &weight[0]);
  max_weight = weight[0];
  sum_weight = weight[0];
  for (i = 1; i < num_packet; i+=2) {
    scanf("%d %d", &weight[i], &weight[i+1]);
    max_weight = (max_weight > weight[i]) ? max_weight : weight[i];
    max_weight = (max_weight > weight[i+1]) ? max_weight : weight[i+1];
    sum_weight += weight[i] + weight[i+1];
  }
  if (i == num_packet) {
    scanf("%d", &weight[i]);
    max_weight = (max_weight > weight[i]) ? max_weight : weight[i];
    sum_weight += weight[i];
  }

  long low = max_weight;
  long upp = sum_weight;

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

int canAlloc(long capacity) {
  long i = 0;
  long alloced_in_one = 0;
  int track_id = 0;

  for (i = 0; i < num_packet; i+=2) {
    int w1 = weight[i];
    int w2 = weight[i+1];

    if (alloced_in_one + w1 <= capacity) {
      alloced_in_one += w1;
    } else {
      alloced_in_one = 0;
      i--;
      if (++track_id == num_track) {
        return 0;
      }
    }

    if (alloced_in_one + w2 <= capacity) {
      alloced_in_one += w2;
    } else {
      alloced_in_one = 0;
      if (++track_id == num_track) {
        return 0;
      }
    }
  }
  return 1;
}