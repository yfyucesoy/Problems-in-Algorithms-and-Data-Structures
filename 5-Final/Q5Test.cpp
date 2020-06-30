#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include "time.h"
#include <algorithm>

using namespace std;

extern int MinimumInRotatedSortedArray(vector<int>& A);

///--------------------------------
/// Q5Test1
///
int Q5Test1() {
	vector<int> A = { 3, 4, 5, 1, 2 };
	if (MinimumInRotatedSortedArray(A) != 1) return 0;

	vector<int> B = { 4, 5, 6, 7, 0, 1, 2 };
	if (MinimumInRotatedSortedArray(B) != 0) return 0;

	vector<int> C;
	for (int i = 20; i < 30; i++) C.push_back(i);
	for (int i = 5; i < 15; i++) C.push_back(i);
	if (MinimumInRotatedSortedArray(C) != 5) return 0;

	return 10;
} //end-Q5Test1

///---------------------------------------------
/// Test2
///
int Q5Test2() {
	int N = 1024 * 2;
	vector<int> A;
	vector<int> B;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		A.push_back(rand());
	}
	sort(A.begin(), A.end());
	int k = 0;
	for (size_t i = 1; i < A.size(); i++) {
		if (A[i] == A[k]) continue;
		A[++k] = A[i];
	} // end-for
	A.resize(k);
	int min = A[0];
	for (int i = 30; i < k; i++)B.push_back(A[i]);
	for (int i = 0; i < 30; i++)B.push_back(A[i]);
	if (MinimumInRotatedSortedArray(B) != min) return 0;


	return 15;
} //end-Q5Test2

///--------------------------------
/// Q5Test Code
///
int Q5Test() {
	int grade = 0;

	grade += Q5Test1();
	grade += Q5Test2();

	return grade;
} // end-Q5Test
