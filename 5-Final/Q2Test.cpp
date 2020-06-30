#include <stdio.h>
#include <iostream>
#include <vector>
#include "time.h"
#include <algorithm>

using namespace std;

extern int NoOfPairs(vector<int>& A, int k);

///-------------------------------------
/// My O(n^2) solution finder :-)
/// Your algorithm must run in O(n)
///
int FindSolution(vector<int>& A, int k) {
	int count = 0;
	for (size_t i = 0; i < A.size()-1; i++) {
		for (size_t j = i + 1; j < A.size(); j++) {
			if (A[i] < A[j] && (A[i] + A[j]) % 10 == k) {
				count++;
			} //end-if
		} // end-for
	} //end-for

	return count;
} // end-FindSolution

///--------------------------------
/// Q2Test1
///
int Q2Test1() {
	vector<int> A = { 1, 2, 3, 4, 7, 9, 10, 11, 12, 13, 20, 23, 30 };

	int grade = 0;
	if (NoOfPairs(A, 3) != FindSolution(A, 3)) return 0;  // no of pairs: 14
	grade += 3;

	if (NoOfPairs(A, 0) != FindSolution(A, 0)) return grade;  // no of pairs: 8
	grade += 2;

	return grade;
} //end-Q2Test1

///--------------------------------
/// Q2Test2
///
int Q2Test2() {
	vector<int> A;
	int N = 1024*2;
	
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		A.push_back(rand());
	} // end-for

	// Sort the array
	sort(A.begin(), A.end());

	// Eliminate the duplicates
	int k = 0; 
	for (size_t i = 1; i < A.size(); i++) {
		if (A[i] == A[k]) continue;
		A[++k] = A[i];
	} // end-for
	A.resize(k);

	// Test
	int grade = 0;
	for (int k = 0; k <= 9; k++) {
		if (NoOfPairs(A, k) == FindSolution(A, k)) {
			grade += 2;
		} //end-if
	} //end-for

	return grade;
} //end-Q2Test2

///--------------------------------
/// Q2Test Code
///
int Q2Test() {
	int grade = 0;

	grade += Q2Test1();
	grade += Q2Test2();

	return grade;
} // end-Q2Test
