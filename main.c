#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
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

  if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL", listToString(mylist)) != 0){
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
  // Testing list_remove_at_index
  list_remove_at_index(mylist, 1);
  list_remove_at_index(mylist,6);
  list_remove_at_index(mylist, 4);
  list_remove_at_index(mylist, 400);
  if(strcmp("20->30->40->60->NULL",listToString(mylist)) != 0){
        printf("list_remove_at_index : FAILED\n");
  }
  else{
    printf("list_remove_at_index : PASSED\n");
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


  // Stress Testing
  printf("\nTime for more rigorous testing!\n");
  
  //Randomizing function calls tests 

  list_free(mylist);
  if(strcmp("NULL",listToString(mylist)) != 0){
        printf("randomize_free : FAILED\n");
  }
  else{
    printf("randomize_free : PASSED\n");
  }

  int i = 0;
  while (i<20)
  {
    list_add_to_back(mylist, i);
    i = i + 1;
  }

  i=0;
  while(i<10)
  {
    list_add_to_front(mylist, list_remove_from_back(mylist));
    i = i + 1;
  }
  if(strcmp("10->11->12->13->14->15->16->17->18->19->0->1->2->3->4->5->6->7->8->9->NULL",listToString(mylist)) != 0){
        printf("randomize_functions_rotate_list : FAILED\n");
  }
  else{
    printf("randomize_functions_rotate_list_right : PASSED\n");
  }



  i=0;
  while(i<10)
  {
    list_add_to_back(mylist, list_remove_from_front(mylist));
    i = i + 1;
  }

  // printf("%s",listToString(mylist));
  if(strcmp("0->1->2->3->4->5->6->7->8->9->10->11->12->13->14->15->16->17->18->19->NULL",listToString(mylist)) != 0){
        printf("randomize_functions_rotate_list : FAILED\n");
  }
  else{
    printf("randomize_functions_rotate_list_right : PASSED\n");
  }


  printf("\nIndex of %d?: %d\n", 81, list_get_index_of(mylist, 81));
  
  list_free(mylist);
  list_add_at_index(mylist, -1, -1);
  list_add_at_index(mylist, -1, -1);
  list_add_at_index(mylist, 10, 0);
  list_add_at_index(mylist, 20, 1);
  printf("The list length after freeing is: %d\n", list_length(mylist));
  if(strcmp("20->NULL",listToString(mylist)) != 0){
        printf("randomize_index_add_delete : FAILED\n");
  }
  else{
    printf("randomize_index_add_delete : PASSED\n");
  }
  list_free(mylist);
  list_remove_from_back(mylist);
  list_remove_from_front(mylist);
  list_remove_at_index(mylist, -3);
  list_remove_at_index(mylist, 0);
  list_remove_at_index(mylist, 2);

  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 60);
  list_add_at_index(mylist, 50, 1);
  list_add_at_index(mylist, 0, 6);
  list_add_at_index(mylist, 70, 0);
  list_add_at_index(mylist, 80, 12);

  list_free(mylist);
  list_free(mylist);
  list_add_to_back(mylist, 100);
  list_remove_from_front(mylist);
  list_add_to_back(mylist, 13);
  list_add_to_back(mylist, 14); 
  list_remove_from_back(mylist);


  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 60);
  list_remove_at_index(mylist, 0);
  list_remove_at_index(mylist, -2);
  list_remove_at_index(mylist, 3);
  list_remove_at_index(mylist, 4);


  list_free(mylist);
  list_print(mylist);
  list_remove_at_index(mylist, 0);
  list_print(mylist);
  list_add_to_front(mylist, 60);
  list_print(mylist);
  list_remove_at_index(mylist, 1);
  list_print(mylist);
  list_add_to_front(mylist, 80);
  list_print(mylist);
  list_remove_at_index(mylist, 0);
  list_print(mylist);

  printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
  list_add_to_back(mylist, 50);
  list_add_to_back(mylist, 60);
  list_add_to_back(mylist, 70);
  list_add_to_back(mylist, 80);
  list_add_to_back(mylist, 90);
  list_print(mylist);
  printf("Is %d in the list?: %d\n", 30, list_is_in(mylist, 30));
  printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
  printf("Is %d in the list?: %d\n", 80, list_is_in(mylist, 80));
  list_add_to_back(mylist, 70);
  list_print(mylist);
  printf("Is %d in the list?: %d\n", 70, list_is_in(mylist, 70));
  
  printf("The list length is %d\n", list_length(mylist));
  printf("Value at %d in the list?: %d\n", -4, list_get_elem_at(mylist, -4));
  printf("Value at %d in the list?: %d\n", 10, list_get_elem_at(mylist, 10));
  printf("Value at %d in the list?: %d\n", 6, list_get_elem_at(mylist, 6));
  printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  list_free(mylist);
  list_print(mylist);
  printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  list_remove_at_index(mylist, 0);
  printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  printf("Index of %d?: %d\n", 21, list_get_index_of(mylist, 21));
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_print(mylist);
  printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
  printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
  printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  printf("Index of %d?: %d\n", 30, list_get_index_of(mylist, 30));
  list_add_to_front(mylist, 60);
  list_print(mylist);
  printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
  printf("Index of %d?: %d\n", 60, list_get_index_of(mylist, 60));
  list_add_to_front(mylist, 10);
  list_print(mylist);
  printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  list_add_to_back(mylist, 40);
  list_print(mylist);
  printf("Index of %d?: %d\n", 40, list_get_index_of(mylist, 40));


  // Hundred node test
  i=0;
  list_free(mylist);
  while (i<100)
  {
    list_add_to_back(mylist, i);
    i = i + 1;
  }

  if (list_length(mylist) == 100)
    printf("hundred_node_test : PASSED\n");
  else
    printf("hundred_node_test : FAILED\n");
  return 0;
}