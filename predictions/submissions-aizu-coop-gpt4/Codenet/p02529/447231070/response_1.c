#include <stdio.h>
#include <uthash.h>

typedef struct {
  int id;
  UT_hash_handle hh;
} MapItem;

int main() {
  char line[1000];
  int a, b, d = 0;
  MapItem *map = NULL;

  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &a);
  for (; a--; ) {
    sscanf(line, "%d", &b);
    MapItem *item = (MapItem *)malloc(sizeof(MapItem));
    item->id = b;
    HASH_ADD_INT(map, id, item);
  }

  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &a);
  for (; a--; ) {
    sscanf(line, "%d", &b);
    MapItem *item;
    HASH_FIND_INT(map, &b, item);
    if (item) d++;
  }

  printf("%d\n", d);
  return 0;
}