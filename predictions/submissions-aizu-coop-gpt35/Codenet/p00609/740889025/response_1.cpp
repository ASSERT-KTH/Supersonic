int countInRange(const vector<pii>& row, int left, int right) {
  int low = 0;
  int high = row.size();
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (row[mid].first < left) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  int start = low;

  low = 0;
  high = row.size();
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (row[mid].first <= right) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  int end = low;

  return end - start;
}