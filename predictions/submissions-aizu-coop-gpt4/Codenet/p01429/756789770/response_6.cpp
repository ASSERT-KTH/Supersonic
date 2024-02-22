// lookup table for compute function results
ll compute_lookup[2001][2001];

// new compute function
ll compute(int i, int j) {
  // check if result is already in lookup table
  if (compute_lookup[i][j] != -1) {
    return compute_lookup[i][j];
  }

  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  ll result = (lhs - rhs) / force_of_repulsion;

  // store result in lookup table
  compute_lookup[i][j] = result;

  return result;
}

// initialize lookup table in main function
memset(compute_lookup, -1, sizeof(compute_lookup));

// change loop where compute is called
for (int i = 0; i < num_of_notes; i++) {
  int next = i + 1;
  for (int j = 0; j <= i; j++) {
    dp[next][j] = min(dp[next][j], dp[i][j] + compute(i, next));
    dp[next][i] = min(dp[next][i], dp[i][j] + compute(j, next));
  }
}