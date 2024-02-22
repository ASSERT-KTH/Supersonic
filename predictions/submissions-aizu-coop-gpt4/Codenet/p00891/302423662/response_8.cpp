// ... (code not modified remains same)
typedef unsigned long long ull;
unordered_set<ull> used; // Replacing vector with unordered_set for O(1) search
ull g = 1; // Precompute g value
for(int i = 0; i < p; i++) g *= N;

void ppp() {
  ull a = 0;
  ull roll[1001][1001] = {};
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  if (used.count(a)) // Check in unordered set
    return;
  used.insert(a); // Insert in unordered_set
  // ...
  // (Rest of the code remains same)
}

// ... (Rest of the function definitions remain same)

int main() {
  // ...
  while (cin >> w >> h >> p, w) {
    ull n = 1; // Precompute n value
    for(int i = 0; i < p; i++) n *= N;
    // ...
    for (int i = 0; i < 4; i++) {
      ppp();
      ch1();
      ppp();
      ch1();
      ch();
    }
    cout << ans << endl;
  }
  return 0;
}