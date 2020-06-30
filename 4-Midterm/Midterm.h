#pragma once
#include <vector>
using namespace std;

///============================ PolynomialAddition ====================
struct PolyNode {
    int coeff;
    int exp;
    PolyNode* next;

    PolyNode(int c, int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

PolyNode* PolynomialAddition(PolyNode* P1, PolyNode* P2);

///============================ TwoDimensionalWordSearch ====================
struct Index { 
    int i, j; 
    Index() { i = -1; j = -1; }
    Index(int _i, int _j) { i = _i; j = _j; } 
};
bool TwoDimensionalWordSearch(vector<string>& A, string& pattern, vector<Index>& patternIndicies);

///============================ IntervalSum ====================
void IntervalSum(vector<int>& A, vector<int>& Sum);

///============================ MergeKSortedSeqs ====================
struct Sequence {
    vector<int>::iterator start;
    vector<int>::iterator end;

    Sequence(vector<int>::iterator s, vector<int>::iterator e) { start = s; end = e; }
};

/// Takes in "k" sorted sequences, and merges them all into a single sorted sequence
/// Your algorithm must take at most O(nlogk) time, where "n" is the total number of numbers
void MergeKSortedSeqs(vector<Sequence>& seqs, vector<int>& sortedArray);
