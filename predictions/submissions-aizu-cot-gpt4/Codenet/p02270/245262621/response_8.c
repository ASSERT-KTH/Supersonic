#include <stdbool.h>
#include <stdio.h>
#define MAX_PACKET 100000
size_t num_packet;
size_t num_track;
int weight[MAX_PACKET];
bool canAlloc(long capacity);
int main(void) {
  auto i;
  scanf("%zu %zu", &num_packet, &num_track);
  int max_weight = 0;
  long sum_weight = 0;
  for (i = 0; i < num_packet; i++) {
    scanf("%d", &weight[i]);
    if (weight[i] > max_weight) {
      max_weight = weight[i];
    }
    sum_weight += weight[i];
  }
  auto low = max_weight;
  auto upp = sum_weight;
  while (low < upp) {
    auto mid = (upp - low) / 2 + low;
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
  auto i = 0;
  auto alloced_in_one = 0;
  auto track_id = 0;
  for (i = 0; i < num_packet;) {
    if (alloced_in_one + weight[i] <= capacity) {
      alloced_in_one += weight[i];
      i++;
    } else {
      alloced_in_one = 0;
      track_id++;
      if (track_id == num_track) {
        return false;
      }
    }
  }
  return true;
}