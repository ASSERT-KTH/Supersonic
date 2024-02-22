#include <stdbool.h>
#include <stdio.h>
#define MAX_PACKET 100000
#define MAX_CAPACITY (long)1e10 // Maximum possible capacity
int num_packet;
int num_track;
int weight[MAX_PACKET];
bool memo[MAX_CAPACITY]; // Memoization array
bool first_run = true; // Flag to check if it's the first run of canAlloc
inline bool canAlloc(long capacity);

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

inline bool canAlloc(long capacity) {
  if (!first_run && memo[capacity] != 0) {
    return memo[capacity] == 1;
  }
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
        memo[capacity] = 2;
        first_run = false;
        return false;
      }
    }
  }
  memo[capacity] = 1;
  first_run = false;
  return true;
}