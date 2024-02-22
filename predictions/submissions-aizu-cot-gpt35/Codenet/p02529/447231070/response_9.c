#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  int count;
  struct Node* next;
} Node;

Node* createNode(int key) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->count = 0;
  newNode->next = NULL;
  return newNode;
}

void insert(Node* hashtable[], int key) {
  int index = abs(key) % 999;
  if (hashtable[index] == NULL) {
    hashtable[index] = createNode(key);
  } else {
    Node* cur = hashtable[index];
    while (cur->next != NULL && cur->key != key) {
      cur = cur->next;
    }
    if (cur->key == key) {
      cur->count++;
    } else {
      cur->next = createNode(key);
    }
  }
}

int getCount(Node* hashtable[], int key) {
  int index = abs(key) % 999;
  Node* cur = hashtable[index];
  while (cur != NULL && cur->key != key) {
    cur = cur->next;
  }
  if (cur != NULL && cur->key == key) {
    return cur->count;
  }
  return 0;
}

int main() {
  int a, b, d;
  Node* hashtable[999] = {NULL};

  scanf("%d", &b);
  for (a = b; a > 0; a--) {
    int num;
    scanf("%d", &num);
    insert(hashtable, num);
  }

  d = 0;
  scanf("%d", &b);
  for (a = b; a > 0; a--) {
    int num;
    scanf("%d", &num);
    d += getCount(hashtable, num);
  }

  printf("%d\n", d);
  return 0;
}