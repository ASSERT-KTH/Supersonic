// ... (same as before)

// Function to calculate cross and dot products
pair<double, double> cross_and_dot(P a, P b) {
  return make_pair(a.x * b.y - a.y * b.x, a.x * b.x + a.y * b.y);
}

int main() {
  // ... (same as before)

  // Reserve memory for pos vector
  pos.reserve(n);

  // ... (same as before)

  // Parallelize outer loop using OpenMP
  #pragma omp parallel for
  for (int i = 0; i < n; i++) {
    // ... (same as before)

    // Use cross_and_dot function to avoid redundant computations
    pair<double, double> products = cross_and_dot(pos[i].F, pos[i].S, pos[pos.size() - 1].F, pos[pos.size() - 1].S);
    
    // ... (same as before)

    // Use the computed products instead of calculating them again
    if (products.first > EPS)
      // ...
    if (products.second < -EPS)
      // ...
  }

  // ... (same as before)

  return 0;
}