const int MAX_N = 128;  // maximum value for n
const int MAX_MASK = 1 << 15;  // maximum value for (1 << (m - depth))
int lookup[MAX_N][MAX_MASK];

// Initialize the lookup table
memset(lookup, -1, sizeof(lookup));