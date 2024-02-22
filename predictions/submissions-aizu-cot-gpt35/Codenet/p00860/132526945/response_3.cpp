inline bool check(int u, int v) {
  int p1, p2;
  
  p1 = v & 255;
  if (p1) {
    if (wall[p1]) {
      return false;
    }
    p2 = (v >> 8) & 255;
    if (p1 == p2) {
      return false;
    }
    if (p1 == ((u >> 8) & 255) && p2 == ((u >> 16) & 255)) {
      return false;
    }
    
    p2 = (v >> 16) & 255;
    if (p1 == p2) {
      return false;
    }
    if (p1 == ((u >> 16) & 255) && p2 == ((u >> 24) & 255)) {
      return false;
    }
    
    p2 = (v >> 24) & 255;
    if (p1 == p2) {
      return false;
    }
    if (p1 == ((u >> 24) & 255) && p2 == (u >> 0) & 255) {
      return false;
    }
  }
  
  p1 = (v >> 8) & 255;
  if (p1) {
    if (wall[p1]) {
      return false;
    }
    p2 = (v >> 16) & 255;
    if (p1 == p2) {
      return false;
    }
    if (p1 == ((u >> 16) & 255) && p2 == ((u >> 24) & 255)) {
      return false;
    }
    
    p2 = (v >> 24) & 255;
    if (p1 == p2) {
      return false;
    }
    if (p1 == ((u >> 24) & 255) && p2 == (u >> 0) & 255) {
      return false;
    }
    
    p2 = (v >> 0) & 255;
    if (p1 == p2) {
      return false;
    }
    if (p1 == ((u >> 0) & 255) && p2 == ((u >> 8) & 255)) {
      return false;
    }
  }
  
  p1 = (v >> 16) & 255;
  if (p1) {
    if (wall[p1]) {
      return false;
    }
    p2 = (v >> 24) & 255;
    if (p1 == p2) {
      return false;
    }
    if (p1 == ((u >> 24) & 255) && p2 == (u >> 0) & 255) {
      return false;
    }
    
    p2 = (v >> 0) & 255;
    if (p1 == p2) {
      return false;
    }
    if (p1 == ((u >> 0) & 255) && p2 == ((u >> 8) & 255)) {
      return false;
    }
    
    p2 = (v >> 8) & 255;
    if (p1 == p2) {
      return false;
    }
    if (p1 == ((u >> 8) & 255) && p2 == ((u >> 16) & 255)) {
      return false;
    }
  }
  
  return true;
}