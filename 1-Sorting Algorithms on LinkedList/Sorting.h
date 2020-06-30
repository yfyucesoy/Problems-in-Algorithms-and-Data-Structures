#ifndef _SORTING_H_
#define _SORTING_H_

#include "LinkedList.h"

/****************************************************
 * Uses bubble sort to sort the LinkedList
 ****************************************************/
void BubbleSort(LinkedList &list);

/****************************************************
 * Uses selection sort to sort the LinkedList
 ****************************************************/
void SelectionSort(LinkedList& list);

/****************************************************
 * Uses insertion sort to sort the LinkedList
 ****************************************************/
void InsertionSort(LinkedList& list);

/****************************************************
 * Uses mergesort to sort the LinkedList
 ****************************************************/
void MergeSort(LinkedList& list);

#endif