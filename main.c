#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  int x;
  printf("Test Cases for Linked List Library\n\n");

  // Testing list_add_to_front
  list_t *mylist;
  mylist = list_alloc();
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_add_to_front(mylist, 60);
  list_add_to_front(mylist, 70);
  list_add_to_front(mylist, 80);
  list_add_to_front(mylist, 90);
  list_add_to_front(mylist, 100);

  if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0){
        printf("list_add_to_front : FAILED\n");
  }
  else{
    printf("list_add_to_front : PASSED\n");
  }

  //Testing list_free
  list_free(mylist);
  if(strcmp("NULL",listToString(mylist)) != 0){
        printf("list_free : FAILED\n");
  }
  else{
    printf("list_free : PASSED\n");
  }

  // Testing list_length
  bool test_status = true;

  if (list_length(mylist) != 0)
    test_status = false;

  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_add_to_front(mylist, 60);
  list_add_to_front(mylist, 70);
  list_add_to_front(mylist, 80);
  list_add_to_front(mylist, 90);
  list_add_to_front(mylist, 100);

  if (list_length(mylist) != 10)
    test_status = false;

  if(test_status == false){
        printf("list_length : FAILED\n");
  }
  else{
    printf("list_length : PASSED\n");
  }

  // Testing list_add_to_back
  list_free(mylist);
  list_add_to_back(mylist, 10);
  list_add_to_back(mylist, 20);
  list_add_to_back(mylist, 30);
  list_add_to_back(mylist, 40);
  list_add_to_back(mylist, 50);
  list_add_to_back(mylist, 60);
  list_add_to_back(mylist, 70);
  list_add_to_back(mylist, 80);
  list_add_to_back(mylist, 90);
  list_add_to_back(mylist, 100);

  if(strcmp("10->20->30->40->50->60->70->80->90->100->NULL",listToString(mylist)) != 0){
        printf("list_add_to_back : FAILED\n");
  }
  else{
    printf("list_add_to_back : PASSED\n");
  }

  // Testing list_add_at_index
  list_add_at_index(mylist, 9, 1);
  list_add_at_index(mylist, 7, 2);
  list_add_at_index(mylist, 30, 100);
  list_add_at_index(mylist, 40, 4);
  if(strcmp("9->7->10->40->20->30->40->50->60->70->80->90->100->NULL",listToString(mylist)) != 0){
        printf("list_add_at_index : FAILED\n");
  }
  else{
    printf("list_add_at_index : PASSED\n");
  }

  //Testing list_remove_from_back
  list_remove_from_back(mylist);
  list_remove_from_back(mylist);
  list_remove_from_back(mylist);
  if(strcmp("9->7->10->40->20->30->40->50->60->70->NULL",listToString(mylist)) != 0){
        printf("list_remove_from_back : FAILED\n");
  }
  else{
    printf("list_remove_from_back : PASSED\n");
  }

  //Testing list_remove_from_front
  list_remove_from_front(mylist);
  list_remove_from_front(mylist);
  list_remove_from_front(mylist);
  if(strcmp("40->20->30->40->50->60->70->NULL",listToString(mylist)) != 0){
        printf("list_remove_from_front : FAILED\n");
  }
  else{
    printf("list_remove_from_front : PASSED\n");
  }

  // Testing list_add_at_index
  list_remove_at_index(mylist, 1);
  list_remove_at_index(mylist,6);
  list_remove_at_index(mylist, 4);
  if(strcmp("20->30->40->60->NULL",listToString(mylist)) != 0){
        printf("list_add_at_index : FAILED\n");
  }
  else{
    printf("list_add_at_index : PASSED\n");
  }


  // Testing list_is_in
  test_status = true;

  if (list_is_in(mylist, 100)== false)
    test_status = true;
  else
    test_status = false;

  if (list_is_in(mylist, 20) == true)
    test_status = true;
  else 
    test_status = false;

  if(test_status == false){
        printf("list_is_in : FAILED\n");
  }
  else{
    printf("list_is_in : PASSED\n");
  }

  // Testing list_get_elem_at
  test_status = true;

  if (list_get_elem_at(mylist, 1) == 20)
    test_status = true;
  else
    test_status = false;

  if (list_get_elem_at(mylist, 4) == 60)
    test_status = true;
  else
    test_status = false;

  if (list_get_elem_at(mylist, 5) == -1)
    test_status = true;
  else
    test_status = false;

  if(test_status == false){
        printf("list_get_elem_at : FAILED\n");
  }
  else{
    printf("list_get_elem_at : PASSED\n");
  }

  // Test list_get_index_of
  test_status = true;

  if (list_get_index_of(mylist, 1) == -1)
    test_status = true;
  else
    test_status = false;

  if (list_get_index_of(mylist, 60) == 4)
    test_status = true;
  else
    test_status = false;

  if (list_get_index_of(mylist, 20) == 1)
    test_status = true;
  else
    test_status = false;
  
  if(test_status == false){
        printf("list_get_index_of : FAILED\n");
  }
  else{
    printf("list_get_index_of : PASSED\n");
  }

  return 0;
}