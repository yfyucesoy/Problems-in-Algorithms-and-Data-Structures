/*
	@author: Yusuf Furkan Yucesoy		
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include "Q1.h"

using namespace std;
map<int, std::list<int>::iterator> m;
list<int> l;
map<int, std::list<int>::iterator>::iterator medianPtr;

// Returns "true" if the DS is empty
bool Q1DS::empty() {
	return l.size() == 0;
 }

// Insert "key" in O(logn)
void Q1DS::insert(int key) {
	if (l.empty()) {
		l.push_back(key);
		m.insert(make_pair(key, l.begin()));
		medianPtr = m.begin();
		return;
	} else if (medianPtr->first < key && l.size() % 2 != 0) {
		auto mapiter = (m.insert(make_pair(key, l.begin()))).first;
		auto tmp = mapiter;
		mapiter--;
		tmp->second=l.insert(std::next((mapiter->second)), key);
	}
	else if (medianPtr->first<key && l.size()%2 == 0){
		auto mapiter = (m.insert(make_pair(key, l.begin()))).first;
		auto tmp = mapiter;
		mapiter--;
		tmp->second = l.insert(std::next((mapiter->second)), key);
		medianPtr++;
	}
	else if (medianPtr->first > key && l.size()%2 != 0) {
		auto mapiter = (m.insert(make_pair(key, l.begin()))).first;
		auto tmp = mapiter;
		mapiter--;
		tmp->second = l.insert(std::next((mapiter->second)), key);
		medianPtr--;
	}
	else if (medianPtr->first > key && l.size() % 2 == 0) {
		auto mapiter = (m.insert(make_pair(key, l.begin()))).first;
		auto tmp = mapiter;
		mapiter--;
		tmp->second = l.insert(std::next((mapiter->second)), key);
		
	}

	
} //end-insert

// Delete "key" in O(logn)
void Q1DS::erase(int key) {
	if (l.size() == 0) {
		throw "Size is zero";
	}
	else {
		if (medianPtr->first <= key && l.size() % 2 != 0) {
			auto tmp=m.find(key);
			medianPtr--;
			l.erase(tmp->second);
			m.erase(key);
			
		}
		else if (medianPtr->first < key && l.size() % 2 == 0) {
			auto tmp = m.find(key);
			l.erase(tmp->second);
			m.erase(key);
		}
		else if (medianPtr->first > key && l.size() % 2 != 0) {
			auto tmp = m.find(key);
			l.erase(tmp->second);
			m.erase(key);
		}
		else if (medianPtr->first >= key && l.size() % 2 == 0) {
			auto tmp = m.find(key);
			medianPtr++;
			l.erase(tmp->second);
			m.erase(key);
			
		}
	
	}
} // end-erase

// Return the median in O(1)
double Q1DS::median() {
	
	double medianvalue;
	if (l.size() % 2 == 0)
	{
		map<int, std::list<int>::iterator>::iterator medianPtrTmp = medianPtr;
		medianPtrTmp++;
		medianvalue = (double)((medianPtr->first) + (medianPtrTmp->first))/2;		
		return medianvalue;
	}
	else
	{
		medianvalue = medianPtr->first;
		return medianvalue;
	}
	
	return 0;
} //end-median
