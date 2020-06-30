/*
	author: Yusuf Furkan Yücesoy
	student number: 152120151005
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include<string>
#include <unordered_map>
#include <list>
#include<queue>
#include "Midterm.h"

using namespace std;

///============================ PolynomialAddition ====================
PolyNode* PolynomialAddition(PolyNode* P1, PolyNode* P2) {
	
	PolyNode* iter = NULL;
	PolyNode* tmp = NULL;
	tmp = (PolyNode*)malloc(sizeof(PolyNode));
	PolyNode* Sum = NULL;
	while (P1 && P2)
	{
		if (P1->exp < P2->exp)
		{
			tmp->exp = P1->exp;
			tmp->coeff = P1->coeff;
			P1 = P1->next;
		}
		else if (P1->exp > P2->exp)
		{
			tmp->exp = P2->exp;
			tmp->coeff = P2->coeff;
			P2 = P2->next;
		}
		else if ((P1->coeff + P2->coeff) == 0)
		{
			P1 = P1->next;
			P2 = P2->next;
			continue;

		}
		else if ((P1->coeff + P2->coeff) != 0)
		{
			tmp->exp = P1->exp;
			tmp->coeff = P1->coeff + P2->coeff;
			P1 = P1->next;
			P2 = P2->next;
		}
		else
		{
			P1 = P1->next;
			P2 = P2->next;
		}
		if (tmp->coeff)
		{
			if (Sum == NULL) {
				iter = (PolyNode*)malloc(sizeof(PolyNode));
				Sum = iter;
			}
			else {
				iter->next = (PolyNode*)malloc(sizeof(PolyNode));
				iter = iter->next;
			}
			iter->next = NULL;
			iter->coeff = tmp->coeff;
			iter->exp = tmp->exp;

		}
	}

	while (P1 || P2)
	{


		if (P1) {
			tmp->exp = P1->exp;
			tmp->coeff = P1->coeff;
			P1 = P1->next;
		}
		if (P2) {
			tmp->exp = P2->exp;
			tmp->coeff = P2->coeff;
			P2 = P2->next;
		}
		iter->next = (PolyNode*)malloc(sizeof(PolyNode));
		iter = iter->next;
		iter->next = NULL;
		iter->coeff = tmp->coeff;
		iter->exp = tmp->exp;
		tmp->coeff = NULL;
		tmp->coeff = NULL;
	}

	return Sum;


} //end-PolynomialAddition

///============================ TwoDimensionalWordSearch ====================
bool dfs(vector<string>&, int, int, string&, vector<Index>&);
bool TwoDimensionalWordSearch(vector<string>& A, string& pattern, vector<Index>& patternIndicies) {
	for (int i = 0;i <A.size(); i++)
	{
		for (int j = 0; j < A[0].size(); j++) {
			if (dfs(A, i, j, pattern, patternIndicies)) {
				return true;
			}

		}
	}

	return false;
} 
bool dfs(vector<string>& A, int i, int j, string& pattern, vector<Index>& patternIndicies) {
	if (!pattern.size())
		return true;
	if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] != pattern[0])
		return false;
	char c = A[i][j];
	Index ind = Index(i, j);
	patternIndicies.push_back(ind);
	A[i][j] = '*';
	string s = pattern.substr(1);
	bool ret = dfs(A, i - 1, j, s,patternIndicies) || dfs(A, i + 1, j, s,patternIndicies) || dfs(A, i, j - 1, s,patternIndicies) || dfs(A, i, j + 1, s,patternIndicies);
	A[i][j] = c;
	return ret;
}


//end-TwoDimensionalWordSearch

///============================ IntervalSum ====================
void IntervalSum(vector<int>& A, vector<int> &Sum) {
	

	/*
	// for previous versions (C++11/C++14)
	auto p = m.emplace(e, sum);
	auto it = p.first;
	bool inserted = p.second;
	if (!inserted) {*/

	//C++17 syntax
	unordered_map<int, int> m;
	int sum = 0;

	for (auto e : A) {
		sum += e;
		if (auto [it, inserted] = m.emplace(e, sum); !inserted) {
			Sum.push_back(sum - e - it->second);
			it->second = sum;
		}
		else {
			Sum.push_back(0);
		}
	}
	

} //end-IntervalSum

///=========================== MergeKSortedSeqs ================================
/// Takes in "k" sorted sequences of "n" total integers, and merges them all into a 
/// single sorted sequence in O(nlogk) time
///
void MergeKSortedSeqs(vector<Sequence>& seqs, vector<int>& sortedArray) {
	struct Element {
		int value;
		int seqPose;
		vector<int>::iterator iter;
		Element(int deger, vector<int>::iterator sequ, int sp) { value = deger; iter = sequ; seqPose = sp; }
	};
	vector<Element> v;
	v.reserve(seqs.size());
	for (size_t i = 0; i < seqs.size(); i++)
	{
		v.push_back(Element(*seqs[i].start, seqs[i].start, i));
	}

	auto cmp = [](Element& left, Element& right) {return(left.value > right.value); };
	priority_queue<Element, vector<Element>, decltype(cmp)> H(v.begin(), v.end(), cmp);

	while (!H.empty()) {
		Element tmp = H.top();
		H.pop();
		sortedArray.push_back(tmp.value);
		if (seqs[tmp.seqPose].end._Ptr != (tmp.iter._Ptr + 1)) {
			tmp.iter++;
			H.push(Element(*tmp.iter, tmp.iter, tmp.seqPose));
		}

	}

} //end-MergeKSortedSeqs

