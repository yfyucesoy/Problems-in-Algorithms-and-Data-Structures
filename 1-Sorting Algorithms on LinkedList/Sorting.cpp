/*
    author: Yusuf Furkan Yücesoy 
    */

#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"

LinkedListNode* mergeSorting(LinkedListNode*);
int getLength( LinkedListNode*);
LinkedListNode* merge(LinkedListNode* , LinkedListNode* );
/****************************************************
 * Uses bubble sort to sort the LinkedList
 ****************************************************/
void BubbleSort(LinkedList& list) {
    int swapped;
    LinkedListNode* myhead;
    LinkedListNode* mytail = NULL;
    do
    {
        swapped = 0;
        myhead = list.head;
        while (myhead->next != mytail)
        {
            if (myhead->key > myhead->next->key)
            {
                int temp = myhead->key;
                myhead->key = myhead->next->key;
                myhead->next->key = temp;
                swapped = 1;
            }
            myhead = myhead->next;
        }
        mytail = myhead;

    } while (swapped);


} //end-BubbleSort

/****************************************************
 * Uses selection sort to sort the LinkedList
 ****************************************************/
void SelectionSort(LinkedList& list) {
    LinkedListNode* myhead = list.head;
    while (myhead) {
        LinkedListNode* min = myhead;
        LinkedListNode* restof = myhead->next;
        while (restof)
        {
            if (min->key > restof->key)
                min = restof;
            restof = restof->next;
        }
        int x = myhead->key;
        myhead->key = min->key;
        min->key = x;
        myhead = myhead->next;
    }



} //end-SelectionSort

/****************************************************
 * Uses insertion sort to sort the LinkedList
 ****************************************************/
void InsertionSort(LinkedList& list) {
    LinkedListNode* current = list.head;
    LinkedListNode* myhead = list.head;
    LinkedListNode* insertionPointer = myhead;
    current = current->next;
    while (current != NULL) {
        insertionPointer = myhead;
        while (insertionPointer != current)
        {
            if (insertionPointer->key > current->key)
            {
                int temp = current->key;
                current->key = insertionPointer->key;
                insertionPointer->key = temp;

            }
            else
            {
                insertionPointer = insertionPointer->next;
            }
        }
        current = current->next;
    }
} //end-InsertionSort

/****************************************************
 * Uses mergesort to sort the LinkedList
 ****************************************************/

void MergeSort(LinkedList& list) {
    list.head = mergeSorting(list.head);
    const LinkedListNode* cur = list.head;;
    bool flag = 0;
    for (; cur != NULL; cur = cur->next) {
        if (flag == 0) {
            if (cur->next->next == NULL) {
                list.tail = cur->next;
                flag = 1;
            }
        }
       
    }
    
} //end-MergeSort
LinkedListNode* mergeSorting(LinkedListNode* head) {
    if (head->next != NULL) {
        LinkedListNode* head1;
        LinkedListNode* head2;
        LinkedListNode* prev = head;
        LinkedListNode* cur = head;
        int half = getLength(head) / 2;
        for (int i = 0; i < half; i++) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        head1 = mergeSorting(head);
        head2 = mergeSorting(cur);
        head = merge(head1, head2);
    }
    return head;
}
int getLength( LinkedListNode* head) {
    const LinkedListNode* cur = head;
    int i = 0;
    for (; cur != NULL; cur = cur->next) {
        i++;
    }
    return i;
}
LinkedListNode* merge(LinkedListNode* head1, LinkedListNode* head2) {
    LinkedListNode* newHead;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->key <= head2->key) {
        newHead = head1;
        newHead->next = merge(head1->next, head2);
    }
    else {
        newHead = head2;
        newHead->next = merge(head1, head2->next);
    }
    return newHead;
}
//end-MergeSort

