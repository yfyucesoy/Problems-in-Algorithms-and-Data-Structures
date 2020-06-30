/*
	@author: Yusuf Furkan Yucesoy
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

///----------------------------------------------------------------------
/// Sort a stack
/// You are given a stack of elements
/// You are asked to sort this stack in increasing order
/// so that the smallest element is at the top, and
/// the largest element is at the bottom of the stack
/// You only have the regular stack operations:
/// Push, pop, top, isEmpty
/// You may make use of an additional stack BUT
/// You are NOT allowed to copy all stack elements into an array,
/// sort them in the array and copy them from the array to the stack.
/// This is NOT allowed.
/// Your algorithm must have a worst case running time performance of O(N^2),
/// and a best case running time of O(N). That is, if the stack is already sorted,
/// it must run in O(N).
/// Hint: Implement an insertion sort algorithm using two stacks


///
void SortStack(stack<int>& S) {

	stack<int> AuxStack;
	while (!S.empty()) {

		int element = S.top();
		S.pop();		
		int until = 0;
		while (!AuxStack.empty()) {
			if (AuxStack.top() <= element) break;
			S.push(AuxStack.top());
			AuxStack.pop();
			until++;
		} 	
		AuxStack.push(element);
		for (int i = 0; i < until; i++) {
			AuxStack.push(S.top());
			S.pop();
		} 
	} 
	while (!AuxStack.empty()) {
		S.push(AuxStack.top());
		AuxStack.pop();
	}
} //end-SortStack
