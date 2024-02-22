#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

#define EPS (1e-6)
#define equals(a, b) (fabs((a) - (b)) < EPS)

const int COUNTER_CLOCKWISE = 1;
const int CLOCKWISE = -1;
const int ONLINE_BACK = 2;
const int ONLINE_FRONT = -2;
const int ON_SEGMENT = 0;

class Point {
// The rest of your code goes here, with the changes mentioned above applied.