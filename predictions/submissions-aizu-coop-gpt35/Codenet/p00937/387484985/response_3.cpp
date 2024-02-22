bool adjMatrix[51][51]; // Declaring adjacency matrix

// ...

for (int i = 0; i < M; i++) {
  int f, t;
  cin >> f >> t;
  f--;
  t--;
  adjMatrix[f][t] = true; // Updating adjacency matrix
}

// ...

for (int to = 0; to < N; to++) {
  if (adjMatrix[k][to]) {
    dp[i][j][to] = true;
  }
}