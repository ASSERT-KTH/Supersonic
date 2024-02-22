// ... (same as before)

// Use a 2D vector instead of unordered_map
vector<vector<int>> d;

int damerau_levenshtein_distance(const string &a, const string &b, const int alphabet_size) {
  // Initialize the vector
  d = vector<vector<int>>(a.size() + 1, vector<int>(b.size() + 1, 0));
  
  // ... (same as before)
  
  // Replace map operations with vector operations
  d[i][j] = min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                 d[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1)});
  
  // ... (same as before)
  
  return d[a.size()][b.size()];
}

// ... (same as before)

void solve(int n) {
  // ... (same as before)
  
  // Use multithreading to compute distances
  vector<thread> threads;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      threads.push_back(thread([&](int i, int j){
        if (damerau_levenshtein_distance(name[i], name[j], 26) <= d) {
          ++count;
          cout << name[i] << "," << name[j] << endl;
        }
      }, i, j));
    }
  }
  
  // Join all threads
  for (auto &t : threads) {
    t.join();
  }
  
  // ... (same as before)
}

// ... (same as before)