// Replace the 2D array with a 1D array
char field[kMaxField];

// Update the xy2pos() function
inline int xy2pos(const int x, const int y) { return x * R + y; }