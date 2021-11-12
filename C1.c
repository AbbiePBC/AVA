
#include <stdio.h>
#include <stdlib.h>

// 1. Given:
typedef struct node_t
{
 unsigned v;
 struct node_t* next;
}node_t;
// A singly linked list of nodes is referred to by a pointer to the head node (the head pointer will be
// NULL in the case of an empty list).
// Write a function:
// struct node_t* even_nodes(struct node_t**)
// which is passed a pointer to the head pointer of a list. It should remove all nodes with even
// values from the indicated list, putting them in a new list, which is returned.
node_t* even_nodes(node_t** head){

  node_t* even_head = (node_t *)malloc(sizeof(node_t));
  even_head->v = 0;
  even_head->next = NULL;
  // ^ could have an initialise_node() fn, and would null check etc here if also generating list
  // as this would decrease repetition

  node_t* new = NULL;
  node_t* tmp = *head;

  while (tmp->next != NULL){
    if ((tmp->v) % 2 == 0){
      new = (node_t *)malloc(sizeof(node_t));
      new->v = tmp->v;
      new->next = even_head;
      tmp=tmp->next;
    }
  }

  free(even_head);

  return new;
}

void delete_list(node_t* head){
  node_t* tmp = head;
  while (head != NULL){
    //printf("%d\n", head->v);
    tmp = head->next;
    free(head);
    head = tmp;
  }
}


int main(void){

  // assume that the list is of malloc'ed nodes.
  node_t* head = (node_t *)malloc(sizeof(node_t)); // assume that this actually has a list hanging off of it
  // we're given the list, so I'm not going to make one
  // head->v = 6; <- for test
  // head->next = NULL;
  if (head == NULL){
    return 1;
  }

  node_t* even_head = NULL;

  even_head = even_nodes(&head);

  delete_list(even_head);
  delete_list(head);

  return 0;

}