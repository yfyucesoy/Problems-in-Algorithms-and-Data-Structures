#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include "time.h"
#include <algorithm>

using namespace std;

struct BinaryTreeNode {
	int key;
	BinaryTreeNode* left, * right;

	BinaryTreeNode(int k) {
		key = k;
		left = right = NULL;
	} //end-TreeNode
};

extern BinaryTreeNode *ConstructTree(vector<int>& preOrderSeq, vector<int>& inOrderSeq);

void PreOrderTraversal(BinaryTreeNode* root, vector<int>& keys) {
	if (root == NULL) return;

	keys.push_back(root->key);
	PreOrderTraversal(root->left, keys);
	PreOrderTraversal(root->right, keys);
} //end-PreOrderTraversal

void InOrderTraversal(BinaryTreeNode* root, vector<int>& keys) {
	if (root == NULL) return;

	InOrderTraversal(root->left, keys);
	keys.push_back(root->key);
	InOrderTraversal(root->right, keys);
} //end-InOrderTraversal

///--------------------------------
/// Q4Test1
///
int Q4Test1() {
	vector<int> preOrderSeq = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> inOrderSeq = { 4, 3, 2, 6, 5, 1, 8, 9, 7, 10 };

	BinaryTreeNode *root = ConstructTree(preOrderSeq, inOrderSeq);

	// Check the tree for correctness
	vector<int> preOrder;
	vector<int> inOrder;

	PreOrderTraversal(root, preOrder);
	InOrderTraversal(root, inOrder);

	if (preOrder.size() != preOrderSeq.size()) return 0;
	if (inOrder.size() != inOrderSeq.size()) return 0;

	for (size_t i = 0; i < preOrder.size(); i++) {
		if (preOrder[i] != preOrderSeq[i]) return 0;
		if (inOrder[i] != inOrderSeq[i]) return 0;
	} //end-for

	return 10;
} //end-Q4Test1

///---------------------------------------------
/// Test2
///
int Q4Test2() {
	vector<int> preOrderSeq = { 6, 5, 1, 2, 3, 4, 9, 7, 8, 10 };
	vector<int> inOrderSeq = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	BinaryTreeNode* root = ConstructTree(preOrderSeq, inOrderSeq);

	// Check the tree for correctness
	vector<int> preOrder;
	vector<int> inOrder;

	PreOrderTraversal(root, preOrder);
	InOrderTraversal(root, inOrder);

	if (preOrder.size() != preOrderSeq.size()) return 0;
	if (inOrder.size() != inOrderSeq.size()) return 0;

	for (size_t i = 0; i < preOrder.size(); i++) {
		if (preOrder[i] != preOrderSeq[i]) return 0;
		if (inOrder[i] != inOrderSeq[i]) return 0;
	} //end-for

	return 15;
} //end-Q4Test2

///--------------------------------
/// Q4Test Code
///
int Q4Test() {
	int grade = 0;

	grade += Q4Test1();
	grade += Q4Test2();

	return grade;
} // end-Q4Test
