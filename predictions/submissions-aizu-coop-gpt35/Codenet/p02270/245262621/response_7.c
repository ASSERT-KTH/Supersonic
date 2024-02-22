bool canAlloc(long capacity) {
  long alloced_in_one = 0;
  int track_id = 0;
  for (int i = 0; i < num_packet; i++) {
    if (alloced_in_one + weight[i] <= capacity) {
      alloced_in_one += weight[i];
    } else {
      alloced_in_one = 0;
      if (++track_id == num_track) {
        return false;
      }
    }
  }
  return true;
}