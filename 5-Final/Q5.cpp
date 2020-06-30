/*
	@author: Yusuf Furkan Yucesoy
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

///----------------------------------------------------------------------
/// Suppose an array sorted in ascending order is rotated 
/// at some pivot unknown to you beforehand. 
/// (i.e., [0, 1, 2, 4, 5, 6, 7] might become [4, 5, 6, 7, 0, 1, 2]). 
/// Find the index of the minimum element. 
/// You may assume no duplicate exists in the array. 
/// Your algorithm must run in O(logN), where N is the number of elements in the array.
/// For example:
/// Input: [3, 4, 5, 1, 2] -> Output : 1
/// Input : [4, 5, 6, 7, 0, 1, 2] -> Output : 0
///
int FindMin(vector<int>& A, int low, int high) {
	if (low > high) return A[0];
	if (high == low) return A[low];
	int mid = (low + high) / 2;
	if (mid < high && A[mid + 1] < A[mid]) return A[mid + 1];
	if (mid > low && A[mid] < A[mid - 1]) return A[mid];
	if (A[high] > A[mid]) return FindMin(A, low, mid - 1);
	return FindMin(A, mid + 1, high);

}
int MinimumInRotatedSortedArray(vector<int> &A){
	if (A.size() == 0) return -1;
	if (A.size() == 1) return A[0];
	return FindMin(A,0, (int)A.size()- 1);
} //end-MinimumInRotatedSortedArray
