#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *next;
} Node;

void print_list(Node *head);
Node *insert_at_head(Node *head, int new_value);
Node *insert_at_tail(Node *head, int new_value);

int main()
{
  Node *list1_head = NULL;

  // list1_head = insert_at_head(list1_head, 7);
  // list1_head = insert_at_head(list1_head, 5);
  // list1_head = insert_at_head(list1_head, 3);

  list1_head = insert_at_tail(list1_head, 10);
  list1_head = insert_at_tail(list1_head, 20);
  list1_head = insert_at_tail(list1_head, 30);

  print_list(list1_head);
  free(list1_head);
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

Node *insert_at_head(Node *head, int new_value)
{
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;

  if (head == NULL)
    return new_node;
  else
  {
    new_node->next = head;
    return new_node;
  }
}

Node *insert_at_tail(Node *head, int new_value)
{
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;

  if (head == NULL)
    return new_node;
  else
  {
    Node *current = head;
    while (current->next != NULL)
      current = current->next;
    current->next = new_node;
    return head;
  }
}