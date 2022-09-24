#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

/* Make head and tail global */
struct Node *head = NULL;
struct Node *tail = NULL;

void display_nodes() {
  /*
   * time complexity: o(n)
   * space complexity: o(1)
   */
  struct Node *temp = head;
  while (temp) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void display_nodes_in_reverse() {
  /*
   * time complexity: o(n)
   * space complexity: o(1)
   */
  struct Node *temp = tail;
  while (temp) {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}

void insert_at_end(int data) {
  /*
   * time complexity: o(1)
   * space complexity: o(1)
   */
  struct Node *new_node;
  new_node = malloc(sizeof *new_node);

  new_node->data = data;
  new_node->next = NULL;

  if (!head) {
    new_node->prev = NULL;
    head = new_node;
    tail = new_node;
  } else {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }
}

void delete_by_value(int data) {
  /*
   * time complexity: o(n)
   * space complexity: o(1)
   */
  struct Node *temp = head;
  if (temp->data == data) { /* If data is in head */
    head = temp->next;
    head->prev = NULL;
    free(temp);
    return;
  }
  while (temp->data != data) {
    temp = temp->next;
  }
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  free(temp);

  return;
}

bool if_value_exists(int data) {
  /*
   * time complexity: o(n)
   * space complexity: o(1)
   */
  struct Node *temp = head;
  while (temp) {
    if (temp->data == data) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

int main(int argc, char *argv[]) {
  insert_at_end(10);
  display_nodes();
  insert_at_end(20);
  display_nodes();
  insert_at_end(30);
  display_nodes();

  display_nodes_in_reverse();
  display_nodes();
  delete_by_value(20);
  display_nodes();
  display_nodes_in_reverse();

  if_value_exists(20) == true ? printf("true\n") : printf("false\n");

  if_value_exists(30) == true ? printf("true\n") : printf("false\n");

  return 0;
}
