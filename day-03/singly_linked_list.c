#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node *next;
};

void display_nodes(struct node *head_ref) {
  struct node *current = head_ref;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void insert_at_beginning(struct node **head_ref, int data) {
  /*
   * Time Complexity: O(1)
   * Space Complexity: O(1)
   */
  struct node *new_node;
  new_node = malloc(sizeof *new_node);

  new_node->data = data;
  new_node->next = *head_ref;

  *head_ref = new_node;
}

void insert_at_end(struct node **head_ref, int data) {
  /*
   *  Time Complexity: O(n)
   *  Space Complexity: O(1)
   */
  struct node *new_node;
  new_node = malloc(sizeof *new_node);
  struct node *last = *head_ref;

  new_node->data = data;
  new_node->next = NULL;

  /* If linked list is empty, make the new node as head */
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  while (last->next) {
    last = last->next;
  }

  last->next = new_node;
  last = new_node;
  return;
}

void insert_after_value(struct node **head_ref, int element, int data) {
  /*
   * Time Complexity: O(1)
   * Space Complexity: O(1)
   */
  struct node *new_node;
  new_node = malloc(sizeof *new_node);
  struct node *temp = *head_ref;

  while (temp->data != element) {
    temp = temp->next;
  }

  new_node->data = data;
  new_node->next = temp->next;

  temp->next = new_node;
}

void insert_from_array(struct node **tail_ref, int array[]) {
  /*
   * Time Complexity: O(n)
   * Space Complexity: O(n)
   */
  struct node *temp = *tail_ref;

  for (int i = 0; i < (int)sizeof(*array); i++) {
    struct node *new_node;
    new_node = malloc(sizeof *new_node);

    new_node->data = array[i];
    new_node->next = NULL;

    temp->next = new_node;
    temp = new_node;
  }
}

void delete_by_value(struct node **head_ref, int data) {
  /*
   * Time Complexity: O(n)
   * Space Complexity: O(1)
   */
  struct node *temp = *head_ref;
  if (temp->data == data) {
    *head_ref = temp->next;
    free(temp);
    return;
  }
  while (temp->next->data != data) {
    temp = temp->next;
  }
  temp->next = temp->next->next;
  // Now it is showing segmentation fault when using free, don't know why yet.
  // free(temp);
}

bool if_value_exists(struct node **head_ref, int data) {
  /*
   * Time Complexity: O(n)
   * Space Complexity: O(1)
   */
  struct node *temp = *head_ref;
  while (temp) {
    if (temp->data == data) {
      return true;
    }
    temp = temp->next;
  }

  return false;
}

int total_node_count(struct node **head_ref) {
  int count = 0;
  struct node *temp = *head_ref;
  while (temp) {
    temp = temp->next;
    count += 1;
  }
  return count;
}

int main(int argc, char *argv[]) {

  struct node *head, *tail, *middle;
  head = malloc(sizeof *head);
  middle = malloc(sizeof *middle);
  tail = malloc(sizeof *tail);

  head->data = 10;
  middle->data = 15;
  tail->data = 20;

  head->next = middle;
  middle->next = tail;
  tail->next = NULL;

  display_nodes(head);
  insert_at_beginning(&head, 5);
  insert_at_end(&head, 25);
  insert_at_end(&head, 30);
  insert_after_value(&head, 15, 17);
  insert_after_value(&head, 15, 16);

  int arr[] = {35, 40, 45, 50};
  insert_from_array(&tail, arr);
  delete_by_value(&head, 15);

  display_nodes(head);
  printf("%d", total_node_count(&head));;

  return 0;
}
