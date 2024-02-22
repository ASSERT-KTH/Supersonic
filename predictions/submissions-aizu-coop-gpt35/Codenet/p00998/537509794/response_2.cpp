#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct SegmentTree {
  int* tree;
  int size;

  SegmentTree(int n) {
    size = 1;
    while (size < n) {
      size *= 2;
    }
    tree = (int*)calloc(2 * size, sizeof(int));
  }

  void update(int index, int value) {
    index += size;
    tree[index] = value;
    while (index > 1) {
      index /= 2;
      tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
    }
  }

  int query(int left, int right) {
    int result = INT_MAX;
    left += size;
    right += size;
    while (left <= right) {
      if (left % 2 == 1) {
        result = min(result, tree[left]);
        left++;
      }
      if (right % 2 == 0) {
        result = min(result, tree[right]);
        right--;
      }
      left /= 2;
      right /= 2;
    }
    return result;
  }
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  SegmentTree tree(n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    tree.update(i, a);
  }
  while (q--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x == 0) {
      int val = tree.query(z, z);
      tree.update(z, val);
      tree.update(y, val);
    } else if (x == 1) {
      printf("%d\n", tree.query(y, z));
    } else {
      tree.update(y, z);
    }
  }
  return 0;
}