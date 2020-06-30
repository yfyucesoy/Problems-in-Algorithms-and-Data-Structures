# Problems in Algorithms and Data Structures
## interview questions and solutions

### 1-Sorting Algorithms on LinkedList
BubbleSort, SelectionSort, InsertionSort and MergeSort algorithms are implemented. Data is sent to algorithms in a **singly-linked list** instead of Array. It manipulates and returns on the same list.

### 2-Crossword Puzzle Question and Solution
Solving of the problem Crossword Puzzle in *Hackerrank.com* under: Practice->Algorithms->Recursion->Crossword Puzzle. Implement the code in C++.

### 3-Simple Search Engine
In this project you are asked to implement a simple search engine. Here are the requirements for your project: 
 * You will be given a list of text files.
 * You are asked to read each file line by line, parse each line into its words, and create an indexfrom these words. Convert all words to lower-case characters and then store them in your index. Ignore words that are less than 3 characters long. This means that words such as “a”, “to”, “in” etc. will not be indexed.
 * Ignore all non-letter characters. That it, your words will only contain letters in the alphabet ‘A’-‘Z’. Other characters will be used to delimit the words.
 * For each words, keep track of which documents contain the word, and the specific lines where the word occurs. If a word occurs in multiple lines of a document, you have store all this information in your index. This is called an inverted-index in information retrieval literature.
 * To initially create the index, implement CreateIndex() function in Index.cpp.
 * There are 5 sample text files 01.txt, 02.txt, 03.txt, 04.txt and 05.txt given together with this project. You should expand your data and test your code with more files.
 * To query your index, there is a Search() function in Index.cpp that you need to fill in.
 * The Search function takes a list of keywords. There can be just one keyword, or multiple keywords.
 * Your Search function must work as follows: For each keyword, find ALL documents that contain that keyword. If you have two keywords, you will have two such lists, one for each keyword.You have to then intersect these two lists and return the documents that contain BOTH of the keywords. In general, you have to return documents that contain ALL the given keywords.
 * After computing the result, your Search function must print the result on the screen in a nicely formatted manner. For example, you can first print the name of the file, and then print each line that contains the keywords.

### 4-Midterm (CS interview type questions and solutions)

##### Q1. Polynomial Addition
You are given two polynomials each represented as a singly linked list. You are to implement a routine AddPolynomials that takes in two polynomials and returns a new polynomial that represents the sum of the two polynomials. For example, if you are given P1 = 3x4 + 3x2 + 5 and P2 = 5x4 – 3x2 + 3x, then you must return P3 = 8x4 + 3x + 5. The test code for this function can be found in main.cpp with the name PolynomialAdditionTest(). Make sure that you test your code thoroughly.

##### Q2. Two Dimensional Word Search 
You are given a two dimensional array of characters as shown below:
       ```            | A B C E |
          M[3][4] =   | S F C S |
                      | A D E E |```
Given a search pattern p = “ABCCED”, you are asked to find out whether the pattern exists in the two dimensional array. The rules of walking over the matrix are the following: If you are at a location ```[i,j]```, you are only allowed to move left [i,j-1], right [i,j+1], up [i-1, j] or down [i+1,j]. Furthermore, you cannot move to a place you have already visited.
Notice that the given pattern p = “ABCCED” exists in the matrix as follows. We start at [0,0], that contains ‘A’. We then move right to B, then to right to C, then down to C, then down to E and then to left to D, which is the end of the given pattern. 
You algorithm TwoDimensionalWordSearch takes in the two dimensional array of characters and the search pattern, and returns either true if the pattern exists in the two dimensional array, or false if the pattern does not exist. If the pattern exists, you must also return the sequence of indices that make up the pattern.
Fill in the function TwoDimensionalWordSearch in Midterm.cpp. The test code for this function can be found in main.cpp with the name TwoDimensionalWordSearchTest().

##### Q3. Interval Sum 
You are given an array of numbers where each number occurs at least twice. You are asked to implement an algorithm that takes such an array as input and returns another array that contains the sum of the numbers between a number A[i] and the last occurrence of the same number in A[0..i-1]. If this is the first occurrence of a number, then the sum is 0.Your algorithm may use O(n) amount of extra space, and **must run in expected O(n) time**. If you implement the brute-force O(n2) algorithm, you will get 0 points.

##### Q4. Merge “k” Sorted Sequences
You are given “k” sorted sequences of integers. The total number of elements in all sequences is equal to “n”. Each sequence is designated by two iterators “start” that points to the first element of the sequence, and “end” that marks the end of the sequence. The element pointed to “end” does not belong to the sequence. In other words, the elements of the sequence line between [begin, end]. Each sequence may contain an arbitrary number of elements. Do not assume that all sequences have the same number of elements. Your job is to implement an algorithm that takes these “k” sorted sequences and merge them all into a single sorted sequence. Your algorithm must take at most O(nlogk) time. In this problem, go to Midterm.cpp, and fill in the function MergeKSortedSeqs. The test code for this function can be found in main.cpp with the name MergeKSortedSeqsTest. Make sure that you test your code thoroughly. During grading we will use other tests to test your code. Do not make any assumptions about “n” or “k”. They both may be very large numbers in the order of millions. So, implement your code efficiently. **Any implementation that does not work in O(nlogk) will get 0**.

### 5-Final (CS interview type questions and solutions)

##### Q1. Finding Medians Efficiently
You have a randomly generated dynamic (expanding) list of numbers. You would like to store these numbers in a DS that supports
 *	Insert operations in O(logN)
 *	Median queries in O(1) time
 *	Delete operations in O(logN)

##### Q2. Pair Sum
Given a sorted array of distinct integer values, find all pairs of numbers (x, y) s.t. x < y and  (x+y)%10 = k, 0<=k<=9. Your algorithm must return the number of such pairs, not the pairs themselves and run in O(n) time. For example:
 * A=[1,2,3,4,7,9,10,11,12,13,20,23,30], k=3
 * Pairs: (1, 2), (1, 12), (2, 11), (3, 10), (3, 20), (3, 30), (4, 9), (10, 13), (10, 23), (11, 12), (13, 20), (13, 30), (20, 23), (23, 30) of pairs: 14.

##### Q3. Sort Stack
You are given a stack of elements, and are asked to sort this stack in increasing order so that the smallest element is at the top, and the largest element is at the bottom of the stack. You only have the regular stack operations: push, pop, top, isEmpty. You may make use of an additional stack BUT are NOT allowed to copy all stack elements into an array, sort the array and copy the elements back to the stack.
Your algorithm must have a worst case running time performance of O(N2), and a best case running time of O(N). That is, if the stack is already sorted, **it must run in O(N)**.

##### Q4. Construct Binary Tree from Pre-Order and In-Order Sequences
You are given two sequences: One that corresponds to the pre-order traversal of a binary tree. Another sequence that corresponds to the in-order traversal of the same binary tree. You are asked to implement an algorithm that constructs the binary tree given these two sequences.

##### Q5. Minimum in a Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]). Find the minimum element. You may assume that the array has at least one element and that no duplicate exists in the array. Your algorithm must run in **O(logN)**, where N is the number of elements in the array. For example:
 * Input: [3,4,5,1,2] -> Output: 1
 * Input: [4,5,6,7,0,1,2] -> Output: 0






 
 







