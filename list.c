#include <stdio.h>

typedef struct node
{
  int value;
  struct node *next;
} Node;

void print_list(Node *head);

int main()
{
  Node a, b, c;
  a.value = 2;
  b.value = 3;
  c.value = 4;
  a.next = &b;
  b.next = &c;
  c.next = NULL;

  print_list(&a);
}

void print_list(Node *head)
{
  Node *current = head;
  int i = 0;

  while (current != NULL)
  {
    printf("Node %i: %i\n", i, current->value);
    i++;
    current = current->next;
  }
}