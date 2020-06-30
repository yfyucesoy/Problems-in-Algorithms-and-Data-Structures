#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include "time.h"
#include <algorithm>

using namespace std;

extern void SortStack(stack<int>& S);

///--------------------------------
/// Q3Test1
///
int Q3Test1() {
	stack<int> S;
	vector<int> A = { 4, 2, 1, 6, 3, 8, 7, 9 };

	for (auto iter : A) S.push(iter);

	// Sort
	SortStack(S);

	// Check
	sort(A.begin(), A.end());

	for (auto iter : A) {
		if (iter != S.top()) return 0;
		S.pop();
	} //end-for

	if (!S.empty()) return 0;

	return 10;
} //end-Q3Test1

///--------------------------------
/// Q3Test2
///
int Q3Test2() {
	stack<int> S;
	vector<int> A;
	int N = 1024*8;
	
	srand((int)time(NULL));
	for (int i = 0; i < N; i++) {
		A.push_back(rand());
		S.push(A[i]);
	} // end-for

	// Sort the stack
	SortStack(S);

	// Sort the array
	sort(A.begin(), A.end());

	for (auto iter : A) {
		if (iter != S.top()) return 0;
		S.pop();
	} //end-for

	if (!S.empty()) return 0;

	return 15;
} //end-Q3Test2

///--------------------------------
/// Q3Test Code
///
int Q3Test() {
	int grade = 0;

	grade += Q3Test1();
	grade += Q3Test2();

	return grade;
} // end-Q3Test
