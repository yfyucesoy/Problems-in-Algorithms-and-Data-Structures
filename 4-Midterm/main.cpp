#include <iostream>
#include <stdio.h>
#include <vector>
#include <array>
#include <time.h>

#include "Midterm.h"

using namespace std;

int PolynomialAdditionTest();
int TwoDimensionalWordSearchTest();
int IntervalSumTest();
int MergeKSortedSeqsTest();

///---------------------------------------------------
/// Program entry
///
int main(){
    int grades[4] = { 0 };

    grades[0] = PolynomialAdditionTest();
    grades[1] = TwoDimensionalWordSearchTest();
    grades[2] = IntervalSumTest();
    grades[3] = MergeKSortedSeqsTest();

    printf("%d, %d, %d, %d\n", grades[0], grades[1], grades[2], grades[3]);

    int grade = 0;
    for (int i = 0; i < 4; i++) grade += grades[i];
    printf("===>Your grade is %d\n", grade);

    return 0;
} //end-main

///======================= PolynomialAdditionTest ==========================
/// Test routine for PolynomialAddition
///
PolyNode *AddPolyNode(PolyNode* head, int c, int e) {
    PolyNode* node = new PolyNode(c, e);
    node->next = head;

    return node;
} //end-AddPolyNode

void DeletePoly(PolyNode* p) {
    while (p) {
        PolyNode* node = p;
        p = p->next;
        delete node;
    } //end-while
} //end-DeletePoly

///--------------
/// Test1
///
int Q1Test1() {
    PolyNode* P1 = NULL;
    P1 = AddPolyNode(P1, 3, 4);
    P1 = AddPolyNode(P1, 3, 2);
    P1 = AddPolyNode(P1, 5, 0);

    PolyNode* P2 = NULL;
    P2 = AddPolyNode(P2, 5, 4);
    P2 = AddPolyNode(P2, -3, 2);
    P2 = AddPolyNode(P2, 3, 1);

    PolyNode* R = NULL;
    R = AddPolyNode(R, 8, 4);
    R = AddPolyNode(R, 3, 1);
    R = AddPolyNode(R, 5, 0);

    // Add them up
    PolyNode* P3 = PolynomialAddition(P1, P2);

    // Check for correctness
    PolyNode* p1 = R;
    PolyNode* p2 = P3;
    while (p1 && p2) {
        if (p1->coeff != p2->coeff) return 0;
        if (p1->exp != p2->exp) return 0;

        p1 = p1->next;
        p2 = p2->next;
    } //end-while

    if (p1 != NULL || p2 != NULL) return 0;

    DeletePoly(P1);
    DeletePoly(P2);
    DeletePoly(P3);
    DeletePoly(R);

    return 7;
} //end-Q1Test1

///----------------------
/// Test2
///
int Q1Test2() {
    PolyNode* P1 = NULL;
    P1 = AddPolyNode(P1, 7, 4);
    P1 = AddPolyNode(P1, 5, 3);
    P1 = AddPolyNode(P1, -2, 1);
    P1 = AddPolyNode(P1, 3, 0);

    PolyNode* P2 = NULL;
    P2 = AddPolyNode(P2, 2, 4);
    P2 = AddPolyNode(P2, -4, 3);
    P2 = AddPolyNode(P2, 2, 1);
    P2 = AddPolyNode(P2, -3, 0);

    PolyNode* R = NULL;
    R = AddPolyNode(R, 9, 4);
    R = AddPolyNode(R, 1, 3);

    // Add them up
    PolyNode* P3 = PolynomialAddition(P1, P2);

    // Check for correctness
    PolyNode* p1 = R;
    PolyNode* p2 = P3;
    while (p1 && p2) {
        if (p1->coeff != p2->coeff) return 0;
        if (p1->exp != p2->exp) return 0;

        p1 = p1->next;
        p2 = p2->next;
    } //end-while

    if (p1 != NULL || p2 != NULL) return 0;

    DeletePoly(P1);
    DeletePoly(P2);
    DeletePoly(P3);
    DeletePoly(R);

    return 7;
} //end-Q1Test2

///----------------------
/// Test3
///
int Q1Test3() {
    PolyNode* P1 = NULL;
    P1 = AddPolyNode(P1, 7, 6);
    P1 = AddPolyNode(P1, 5, 5);
    P1 = AddPolyNode(P1, -2, 1);
    P1 = AddPolyNode(P1, 1, 0);

    PolyNode* P2 = NULL;
    P2 = AddPolyNode(P2, 8, 7);
    P2 = AddPolyNode(P2, 4, 4);
    P2 = AddPolyNode(P2, 3, 3);

    PolyNode* R = NULL;
    R = AddPolyNode(R, 8, 7);
    R = AddPolyNode(R, 7, 6);
    R = AddPolyNode(R, 5, 5);
    R = AddPolyNode(R, 4, 4);
    R = AddPolyNode(R, 3, 3);
    R = AddPolyNode(R, -2, 1);
    R = AddPolyNode(R, 1, 0);

    // Add them up
    PolyNode* P3 = PolynomialAddition(P1, P2);

    // Check for correctness
    PolyNode* p1 = R;
    PolyNode* p2 = P3;
    while (p1 && p2) {
        if (p1->coeff != p2->coeff) return 0;
        if (p1->exp != p2->exp) return 0;

        p1 = p1->next;
        p2 = p2->next;
    } //end-while

    if (p1 != NULL || p2 != NULL) return 0;

    DeletePoly(P1);
    DeletePoly(P2);
    DeletePoly(P3);
    DeletePoly(R);

    return 7;
} //end-Q1Test3

///----------------------
/// Test4
///
int Q1Test4() {
    PolyNode* P1 = NULL;
    P1 = AddPolyNode(P1, 7, 6);
    P1 = AddPolyNode(P1, 5, 5);

    PolyNode* P2 = NULL;
    P2 = AddPolyNode(P2, -7, 6);
    P2 = AddPolyNode(P2, -5, 5);

    PolyNode* R = NULL;

    // Add them up
    PolyNode* P3 = PolynomialAddition(P1, P2);

    // Check for correctness
    PolyNode* p1 = R;
    PolyNode* p2 = P3;
    while (p1 && p2) {
        if (p1->coeff != p2->coeff) return 0;
        if (p1->exp != p2->exp) return 0;

        p1 = p1->next;
        p2 = p2->next;
    } //end-while

    if (p1 != NULL || p2 != NULL) return 0;

    DeletePoly(P1);
    DeletePoly(P2);
    DeletePoly(P3);
    DeletePoly(R);

    return 4;
} //end-Q1Test4

int PolynomialAdditionTest() {
    int grade = 0;

    grade += Q1Test1();
    grade += Q1Test2();
    grade += Q1Test3();
    grade += Q1Test4();

    return grade;
} //end-PolynomialAdditionTest

///======================= TwoDimensionalWordSearchTest ==========================
/// Test routine for TwoDimensionalWordSearch
/// Test1
int Q2Test1() {
    vector<string> A = {
        "ABCE",
        "SFCS",
        "ADEE"
    };
    string pattern = "ABCCED";
    vector<Index> patternIndices;

    /// Successful search
    if (TwoDimensionalWordSearch(A, pattern, patternIndices) == false) return 0;
    vector<Index> sol = { Index(0, 0), Index(0, 1), Index(0, 2),
                         Index(1, 2), Index(2, 2), Index(2, 1) };

    if (patternIndices.size() != sol.size()) return 0;

    for (size_t i = 0; i < sol.size(); i++) {
        if (sol[i].i != patternIndices[i].i) return 0;
        if (sol[i].j != patternIndices[i].j) return 0;
    } //end-for

    /// Unsuccessful search
    patternIndices.resize(0);
    string pattern2 = "CCSEC";  // Does not exist
    if (TwoDimensionalWordSearch(A, pattern2, patternIndices)) return 5;

    return 25;
} // end-Q2Test1

///---------------------------
/// Test2
int Q2Test2() {
    vector<string> A = {
        "ABCEXEYZABCD",
        "SFCSAAFABBBB",
        "ADEECFCDDEEE",
        "XYZXYZXYZAAB",
        "FFFFFEEEEEDD",
    };
    string pattern = "FCFCESCFDYZXFFE";
    vector<Index> patternIndices;

    /// Successful search
    if (TwoDimensionalWordSearch(A, pattern, patternIndices) == false) return 0;
    vector<Index> sol = { Index(1, 6), Index(2, 6), Index(2, 5),
                         Index(2, 4), Index(2, 3), Index(1, 3),
                         Index(1, 2), Index(1, 1), Index(2, 1),
                         Index(3, 1), Index(3, 2), Index(3, 3),
                         Index(4, 3), Index(4, 4), Index(4, 5)
    };

    if (patternIndices.size() != sol.size()) return 0;

    for (size_t i = 0; i < sol.size(); i++) {
        if (sol[i].i != patternIndices[i].i) return 0;
        if (sol[i].j != patternIndices[i].j) return 0;
    } //end-for

    /// Unsuccessful search
    patternIndices.resize(0);
    string pattern2 = "DBEBDXYZT";  // Does not exist
    if (TwoDimensionalWordSearch(A, pattern2, patternIndices)) return 10;

    return 15;
} // end-Q2Test2

int TwoDimensionalWordSearchTest() {
    int grade = 0;

    grade += Q2Test1();
    grade += Q2Test2();

    return grade;
} //end-TwoDimensionalWordSearchTest

///============================ IntervalSum ====================
/// You are given an array of numbers where each number occurs at least twice.
/// You are asked to implement an algorithm that takes such an array as input
/// and returns another array that contains the sum of the numbers between
/// a number A[i] and the last occurrence of the same number in A[0..i-1].
/// If this is the first occurrence of a number, then the sum is 0.
/// For example, assume you are given A=[2, 5, 7, 2, 6, 7, 6, 5, 6, 5].
/// Then Sum=[0, 0, 0, 12, 0, 8, 7, 28, 5, 6].
///
/// ------------------------
/// Test1
///
int Q3Test1() {
    vector<int> A = { 2, 5, 7, 2, 6, 7, 6, 5, 6, 5 };
    vector<int> Sum;

    vector<int> Sol = { 0, 0, 0, 12, 0, 8, 7, 28, 5, 6 };

    // Call Interval Sum
    IntervalSum(A, Sum);

    if (Sum.size() != Sol.size()) return 0;

    for (size_t i = 0; i < Sum.size(); i++) {
        if (Sum[i] != Sol[i]) return 0;
    } //end-for

    return 10;
} //end-Q3Test1

/// ------------------------
/// Test2
///
int Q3Test2() {
    vector<int> A;
    vector<int> Sum;

    vector<int> Sol;

    int N = 1024*8;
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        A.push_back(rand() % 100);
    } //end-for

    // Solve using the brute-force method
    for (int i = 0; i < A.size(); i++) {
        int sum = 0;
        bool found = false;
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] == A[i]) {
                found = true;
                break;
            } //end-if

            sum += A[j];
        } //end-for


        if (!found) sum = 0;
        Sol.push_back(sum);
    } //end-for

    // Call Interval Sum
    IntervalSum(A, Sum);

    if (Sum.size() != Sol.size()) return 0;

    for (size_t i = 0; i < Sum.size(); i++) {
        if (Sum[i] != Sol[i]) return 0;
    } //end-for

    return 15;
} //end-Q3Test2

int IntervalSumTest(){
    int grade = 0;

    grade = Q3Test1();
    grade += Q3Test2();

    return grade;
} //end-IntervalSumTest

///======================== MergeKSortedSeqsTest ============================
/// Test routine for MergeKSortedSeqs
///
int Q4Test1() {
    vector<int> A = { 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16 };
    int k = 4;
    vector<Sequence> seqs;
    auto iter = A.begin();
    seqs.push_back(Sequence(iter, iter + 4));
    seqs.push_back(Sequence(iter + 4, iter + 8));
    seqs.push_back(Sequence(iter + 8, iter + 12));
    seqs.push_back(Sequence(iter + 12, A.end()));

    vector<int> sortedArray;
    MergeKSortedSeqs(seqs, sortedArray);

    // Check for correctness
    // Sort the input array
    sort(A.begin(), A.end());

    if (sortedArray.size() != A.size()) return 0;

    for (size_t i = 0; i < A.size(); i++) {
        if (A[i] != sortedArray[i]) return 0;
    } //end-for

    return 10;
} //end-Q4Test1

int Q4Test2() {
    int N = 1024 * 512;     // 512K numbers
    vector<int> A(N);
            
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < A.size(); i++) {
        A[i] = rand();
    } //end-for

    int k = 1024 * 16;   // 16K sequences
    int inc = N / k;     // Size of each sequence

    vector<Sequence> seqs;
    auto iter = A.begin();
    for (int i = 0; i < k; i++) {
        vector<int>::iterator end = iter + inc;
        if (i == k - 1) end = A.end();

        seqs.push_back(Sequence(iter, end));
        
        // Sort this sequence
        sort(iter, end);

        iter = end;
    } //end-for

    vector<int> sortedArray;
    MergeKSortedSeqs(seqs, sortedArray);

    // Check for correctness
    // Sort the entire array
    sort(A.begin(), A.end());

    if (sortedArray.size() != A.size()) return 0;

    for (size_t i = 0; i < A.size(); i++) {
        if (A[i] != sortedArray[i]) return 0;
    } //end-for

    return 15;
} //end-Q4Test2

int MergeKSortedSeqsTest() {
    int grade = Q4Test1();
    grade += Q4Test2();

    return grade;
}  // end-MergeKSortedSeqsTest