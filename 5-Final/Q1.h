#ifndef _Q1_H_

// You may assume that the "key"s will be unique
struct Q1DS {

	// Returns "true" if the DS is empty
	bool empty();

	// Insert "key" in O(logn)
	void insert(int key);

	// Delete "key" in O(logn)
	void erase(int key);

	// Return the median in O(1)
	double median();
};

#endif _Q1_H_