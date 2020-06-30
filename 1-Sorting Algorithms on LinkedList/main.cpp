#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Sorting.h"

//#define N 1024*8192*2
//#define N 1024*4096
#define N 1024*32
int A[N];

typedef void (*SortingFunction)(LinkedList &);

/****************************************************
 * Test
 ****************************************************/
float Test(SortingFunction F, char *msg){
  int B[] = {4, 2, 5, 7, 8, 1, 10, 9, 15, 34, 6, 17, 66, 55, 44, 33};

  LinkedList list;
  for (int i = 0; i < sizeof(B) / sizeof(int); i++) {
      list.Append(B[i]);
  } //end-for
 
  // Use the sorting algorithm
  F(list);

  printf("Using %s to sort %d numbers...\n", msg, 16);

  // Check the result
  LinkedListNode* p = list.head;
  int S[] = { 1, 2, 4, 5, 6, 7, 8, 9, 10, 15, 17, 33, 34, 44, 55, 66 };
  for (int i = 0; i < sizeof(S) / sizeof(int); i++) {
      if (S[i] != p->key) return 0;
      p = p->next;
  } // end-for

  list.Clear();
  srand((unsigned int)time(NULL));
  int i;
  int min = INT_MAX;
  int max = 0;
  for (i=0; i<N;i++){
      int number = rand();
      list.Append(number);

      if (number<min) min=number;
      else if (number>max) max=number;
  } //end-for

  printf("Using %s to sort %d numbers...", msg, N);
  time_t t1 = time(NULL);
  F(list);
  time_t t2 = time(NULL);
  printf("took %I64d seconds\n", t2-t1);

  // Check the result
  if (list.head->key!=min || list.tail->key!=max) return 0;

  LinkedListNode* q = list.head;
  p = q->next;
  while (p){
    if (q->key > p->key) return 0;
    q = p;
    p = p->next;
  } //end-for

  return 25;
} //end-Test

/****************************************************
 * Main function
 ****************************************************/
int main(){
  float grade = 0;

  printf("======================= TEST1 =======================\n");
  grade += Test(BubbleSort, "BubbleSort");

  printf("======================= TEST2 =======================\n");
  grade += Test(SelectionSort, "SelectionSort");

  printf("======================= TEST3 =======================\n");
  grade += Test(InsertionSort, "InsertionSort");

  printf("======================= TEST4 =======================\n");
  grade += Test(MergeSort, "MergeSort");

  printf("=====================================================\n");
  printf("Final grade: %.1f\n", grade);

  return 0;
} //end-main
