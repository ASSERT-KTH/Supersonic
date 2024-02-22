#include <stdio.h>
#include <limits.h>

#define MAX_PACKET 100000

bool canAlloc(int num_packet, int num_track, int weight[], long capacity);

int main(void) {
  int num_packet, num_track;
  scanf("%d %d", &num_packet, &num_track);
  
  int max_weight = INT_MIN;
  long sum_weight = 0;
  
  for (int i = 0; i < num_packet; i++) {
    int current_weight;
    scanf("%d", &current_weight);
    
    if (current_weight > max_weight) {
      max_weight = current_weight;
    }
    
    sum_weight += current_weight;
  }
  
  long low = max_weight;
  long upp = sum_weight;
  
  for (long i = low; i < upp; i++) {
    if (canAlloc(num_packet, num_track, weight, i)) {
      upp = i;
    } else {
      low = i + 1;
    }
  }
  
  printf("%ld\n", low);
  return 0;
}

bool canAlloc(int num_packet, int num_track, int weight[], long capacity) {
  long alloced_in_one = 0;
  int current_track = 0;
  
  for (int i = 0; i < num_packet; i++) {
    if (alloced_in_one + weight[i] <= capacity) {
      alloced_in_one += weight[i];
    } else {
      alloced_in_one = 0;
      i--;
      
      if (++current_track == num_track) {
        return false;
      }
    }
  }
  
  return true;
}