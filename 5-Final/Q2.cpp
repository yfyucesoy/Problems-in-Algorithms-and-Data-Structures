/*
	@author: Yusuf Furkan Yucesoy
*/
#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

///----------------------------------------------------------------------
/// Given a sorted array of distinct integer values, find all pairs of numbers (x, y) s.t. 
/// x < y and
///	(x + y) % 10 = k, 0 <= k <= 9
///	Your algorithm must return the number of such pairs, not the pairs themselves
/// and run in O(n) time
///	For example :
/// A = [1, 2, 3, 4, 7, 9, 10, 11, 12, 13, 20, 23, 30], k = 3
/// Pairs : (1, 2), (1, 12), (2, 11), (3, 10), (3, 20), (3, 30), (4, 9), (10, 13), (10, 23), (11, 12), (13, 20), (13, 30), (20, 23), (23, 30)
/// # of pairs : 14
///
int NoOfPairs(vector<int>& A, int k) {
	

	int size = A.size();
	std::vector<int> table[10];

	int totals[10];

	for (int i = 0; i < 10; i++)
	{
		totals[i] = 0;
		for (int j = 0; j < size; j++)
		{
			if ((A[j] + i) % 10 == k)
			{
				totals[i]++;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < size; j++)
		{
			table[i].push_back(totals[i]);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if ((A[0] + i) % 10 == k)
		{
			table[i][0]--;
		}

		for (int j = 1; j < size; j++)
		{
			table[i][j] = table[i][j - 1];
			if ((A[j] + i) % 10 == k)
			{
				table[i][j]--;
			}
		}
	}

	int count = 0;
	for (int j = 0; j < size; j++)
	{
		count += table[A[j] % 10][j];
	}


	return count;
} //end-FindPairs
