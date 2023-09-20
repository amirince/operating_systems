// list/list.c
// 
// Implementation for linked list.
//
// Amir Ince

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* linked_list = (list_t *) malloc(sizeof(list_t));
  linked_list->head = NULL;
  return linked_list; 
}

void list_free(list_t *l) {
  node_t* curr = l->head;
  node_t *tmp = NULL;

  while(curr != NULL) {
    tmp = curr;
    curr = curr->next;
    free(tmp);
  }
  l->head = NULL;
}

void list_print(list_t *l) {
  node_t *curr = l->head;

  while(curr!=NULL) {
    printf("%d->", curr->value);
    curr = curr->next;
  }
  printf("NULL\n");
}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) {

  node_t* copy = l->head;
  int count = 0; 

  if (l == NULL)
    return -1;

  while(copy!=NULL) {
    count = count + 1;
    copy = copy->next;
  }
  
  return count; 
}

void list_add_to_back(list_t *l, elem value) {
  node_t* new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;

  node_t* head_copy = l->head;
  
  if(head_copy == NULL) {
    l->head = new_node;

    return;
  }
  
  while(head_copy->next != NULL) {
    head_copy = head_copy->next;
  }
  head_copy->next = new_node;
}

void list_add_to_front(list_t *l, elem value) {
    node_t* new_node = (node_t *) malloc(sizeof(node_t));
    new_node->value = value;
    
    node_t* copy = l->head;
    l->head = new_node;
    new_node->next = copy;
}

void list_add_at_index(list_t *l, elem value, int index) {
    if (index<=0)
      return;
    if(index==1) {
        list_add_to_front(l, value);
    }
    node_t* copy = l->head;
    node_t* new_node = (node_t *) malloc(sizeof(node_t));
    new_node->value = value;
    
    node_t *curr = l->head->next;
    node_t *prev = l->head;
    int count = 2;
    
    while(curr!=NULL) {
        if (count == index)
            break;
        curr = curr ->next;
        prev = prev->next;
        count = count + 1;
    }
    if (count == index)
    {
      prev->next = new_node;
      new_node->next = curr;
    }
}

elem list_remove_from_back(list_t *l) { 
    node_t *curr = l->head;
    
    if (curr==NULL)
        return -1; 
        
    while(curr->next->next != NULL) {
        curr = curr->next;
    }
    
    free(curr->next);
    curr->next = NULL;
}
    
elem list_remove_from_front(list_t *l) { 
    
    node_t *curr = l->head;
    elem value = curr->value;
    
    if(curr == NULL)
        return -1;
    
    l->head = curr->next;
    
    free(curr);
    return value;
}
    
elem list_remove_at_index(list_t *l, int index) {
    
    node_t *curr = l->head->next;
    node_t *prev = l->head;
    int count = 2;
    int deleted_node;
    
    if (index<=0) {
        return -1;
    }
    
    if (index == 1) {
        return list_remove_from_front(l);
    }
    
    while(curr!=NULL){
        if ( count == index)
            break;
        curr = curr->next;
        prev = prev->next;
        count = count + 1;
    }

    if(count == index){
        prev->next = curr->next;
        deleted_node = curr-> value;
    
        free(curr);
        return deleted_node;
    }
    return -1;
}
     
bool list_is_in(list_t *l, elem value) {
    node_t *curr = l->head;
    
    while(curr!=NULL) {
        if(curr->value == value)
            return true;
        curr = curr->next;
    }
    return false;
}

elem list_get_elem_at(list_t *l, int index) { 
    node_t *curr = l->head;
    int count = 1;
    
    while(curr!=NULL) {
        if(count == index)
            return curr->value;
        count = count + 1;
        curr=curr->next;
    }
    return -1; }
    
int list_get_index_of(list_t *l, elem value) {

    node_t *curr = l->head;
    int count = 1;

    while(curr!=NULL) {
        if(curr->value == value)
            return count;
        count = count + 1;
        curr=curr->next;
    }
    return -1;
}
