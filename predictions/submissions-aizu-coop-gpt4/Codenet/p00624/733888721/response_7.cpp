/* ...Same includes and macros... */

using namespace std;

// Use vectors instead of arrays in the state structure
struct state {
  char x, y, Sc;
  vector<char> cx, cy;
  state(char _x, char _y, vector<char> _cx, vector<char> _cy, char _Sc) {
    x = _x, y = _y, Sc = _Sc;
    cx = _cx, cy = _cy;
  }
  /* ...Same overloaded operators... */
};

// Replace the rep macro with standard for loops
#define rep(i, n) for (int i = 0; i < (n); ++i)

// Store repeated calculations in temporary variables
void BFS(char nx, char ny, vector<char> ncx, vector<char> ncy, char Sc) {
  /* ...Same function body, but with standard for loops... */
}

void input() {
  /* ...Same function body, but with standard for loops... */
}

int main() {
  /* ...Same function body, but with standard for loops and temporary variables to store repeated calculations... */
  return 0;
}