#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node* prev;
  struct Node* next;
} Node;

Node* new_node(char data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->prev = node->next = NULL;
  return node;
}

void add_to_end(Node** head, Node** tail, char data) {
  Node* node = new_node(data);
  if (*head == NULL) *head = *tail = node;
  else {
    (*tail)->next = node;
    node->prev = *tail;
    *tail = node;
  }
}

void add_to_start(Node** head, Node** tail, char data) {
  Node* node = new_node(data);
  if (*head == NULL) *head = *tail = node;
  else {
    (*head)->prev = node;
    node->next = *head;
    *head = node;
  }
}

void print_list(Node* head) {
  Node* node = head;
  while (node) {
    putchar(node->data);
    node = node->next;
  }
  puts("");
}

bool ope_line() {
  char buffer[105];
  fgets(buffer, sizeof(buffer), stdin);
  Node *head = NULL, *tail = NULL;
  int i = 0;

  add_to_end(&head, &tail, buffer[i++]);

  while (buffer[i] != '\n' && buffer[i] != '\0') {
    char a = buffer[i++];
    char b = buffer[i++];
    char c = buffer[i++];
    if (a == '<' && b == '-') add_to_start(&head, &tail, c);
    else if (a == '-' && b == '>') add_to_end(&head, &tail, c);
  }

  print_list(head);
  return true;
}

int main(int argc, char **argv) {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) ope_line();
  return 0;
}