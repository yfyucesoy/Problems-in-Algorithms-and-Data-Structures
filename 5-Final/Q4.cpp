/*
	@author: Yusuf Furkan Yucesoy
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include<set>

using namespace std;

///----------------------------------------------------------------------
/// You are given two sequences:
/// One that corresponds to the pre - order traversal of a binary tree.
/// Another sequence that corresponds to the in-order traversal 
/// of the same binary tree.
/// You are asked to implement an algorithm that constructs 
/// the binary tree given these two sequences
///
struct BinaryTreeNode {
	int key;
	BinaryTreeNode* left, * right;

	BinaryTreeNode(int k) {
		key = k;
		left = right = NULL;
	} //end-TreeNode
};
set<BinaryTreeNode*> nextright;
stack<BinaryTreeNode*> visitedpath;
BinaryTreeNode* ConstructTree(vector<int>& preOrderSeq, vector<int>& inOrderSeq){
	BinaryTreeNode* root = NULL;
	int numberofelmnt = inOrderSeq.size();
	for (int pre = 0, in = 0; pre < numberofelmnt;) {
		BinaryTreeNode* node = NULL;
		do
		{
			node = new BinaryTreeNode(preOrderSeq[pre]);
			if (root == NULL) {
				root = node;
			}
			if (visitedpath.size() > 0) {
				if (nextright.find(visitedpath.top()) != nextright.end()) {
					nextright.erase(visitedpath.top());
					visitedpath.top()->right = node;
					visitedpath.pop();
				}
				else {
					visitedpath.top()->left = node;
				}
			}
			visitedpath.push(node);
		} while (preOrderSeq[pre++]!=inOrderSeq[in] && pre<numberofelmnt);
		node = NULL;
		while (visitedpath.size() > 0 && in < numberofelmnt && visitedpath.top()->key == inOrderSeq[in]) {
			node = visitedpath.top();
			visitedpath.pop();
			in++;
		}
		if (node != NULL) {
			nextright.insert(node);
			visitedpath.push(node);
		}

	}
    
	return root;
} //end-ConstructTree
