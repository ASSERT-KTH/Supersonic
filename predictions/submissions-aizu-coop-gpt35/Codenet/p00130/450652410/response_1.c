#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node* next;
  struct Node* prev;
} Node;

bool ope_line() {
  Node* train = NULL;
  int leftCount = 0;
  int rightCount = 0;

  char input[100];
  fgets(input, sizeof(input), stdin);
  int len = strlen(input);
  if (input[len - 1] == '\n') {
    input[len - 1] = '\0';
    len--;
  }

  for (int i = 0; i < len; i++) {
    char c = input[i];
    if (c == '<' && input[i + 1] == '-') {
      i += 2;
      char moveChar = input[i];
      Node* newNode = (Node*)malloc(sizeof(Node));
      newNode->data = moveChar;
      newNode->prev = NULL;
      newNode->next = train;
      if (train != NULL) {
        train->prev = newNode;
      }
      train = newNode;
      leftCount++;
    } else if (c == '-' && input[i + 1] == '>') {
      i += 2;
      char moveChar = input[i];
      Node* newNode = (Node*)malloc(sizeof(Node));
      newNode->data = moveChar;
      newNode->prev = NULL;
      newNode->next = NULL;
      if (train == NULL) {
        train = newNode;
      } else {
        Node* lastNode = train;
        while (lastNode->next != NULL) {
          lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->prev = lastNode;
      }
      rightCount++;
    }
  }

  if (train == NULL) {
    printf("\n");
  } else {
    Node* currentNode = train;
    for (int i = 0; i < leftCount; i++) {
      printf("%c", currentNode->data);
      currentNode = currentNode->next;
    }
    printf("\n");
  }

  while (train != NULL) {
    Node* nextNode = train->next;
    free(train);
    train = nextNode;
  }

  if (len == 0)
    return false;
  return true;
}

int main(int argc, char** argv) {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    if (!ope_line())
      break;
  }
  return 0;
}