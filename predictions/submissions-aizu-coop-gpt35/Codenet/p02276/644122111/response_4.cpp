static uint partition(int as[], const uint first, const uint last) {
  auto pivot = as[last];
  auto less = first;
  for (auto i = first; i < last; ++i) {
    if (as[i] <= pivot) {
      std::swap(as[less++], as[i]);
    }
  }
  std::swap(as[less], as[last]);
  return less;
}