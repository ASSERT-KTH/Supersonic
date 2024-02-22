// Example of minimizing array accesses
int hyouka(int a, int b) {
  long long H_a = H[a];
  long long H_b = H[b];

  if (C < b)
    return 1;
  if (C < a || b == 0)
    return 0;
  return N[H_a] < N[H_b] || N[H_a] == N[H_b] && h[H_a] < h[H_b] ? 1 : 0;
}

// Example of optimizing conditional checks
int hyouka(int a, int b) {
  if (a >= C || b == 0 || b > C)
    return 0;
  return N[H[a]] < N[H[b]] || N[H[a]] == N[H[b]] && h[H[a]] < h[H[b]] ? 1 : 0;
}

// Example of avoiding unnecessary computations
int main() {
  ...
  long long lr0 = getlr(l, r, 0);
  h[R] = lr0;
  hin(getlr(l, r, 1));  // This can be optimized to hin(lr0);
  ...
}