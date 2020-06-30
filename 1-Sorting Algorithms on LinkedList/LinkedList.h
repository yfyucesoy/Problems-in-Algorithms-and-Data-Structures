#pragma once

#include <stdlib.h>

struct LinkedListNode {
	int key;
	LinkedListNode* next;

	LinkedListNode(int _key) { key = _key; next = NULL; }
};

struct LinkedList {
	LinkedListNode *head, *tail;

	LinkedList() { head = tail = NULL; }
	~LinkedList() {
		Clear();
	} //end-~LinkedList

	void Clear() {
		while (head) {
			LinkedListNode* p = head;
			head = head->next;
			delete p;
		} //end-while

		head = tail = NULL;
	} //end-Clear

	void Append(int key) {
		LinkedListNode* node = new LinkedListNode(key);
		if (tail == NULL) head = tail = node;
		else {
			tail->next = node;
			tail = node;
		} //end-else
	} //end-Append
};