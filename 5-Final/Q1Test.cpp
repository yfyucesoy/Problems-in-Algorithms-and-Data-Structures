#include <stdio.h>
#include <iostream>
#include <vector>
#include "Q1.h"

using namespace std;

int Q1Test1() {
	try {
		vector<int> keys1 = { 1, 3, 14, 11, 7};
		vector<double> medians1 = { 1, 2, 3, 7, 7 };
		Q1DS ds;

		for (size_t i = 0; i < keys1.size(); i++) {
			ds.insert(keys1[i]);

			if (ds.median() != medians1[i]) return 0;
		} //end-for

		// 1 14
		vector<int> keys2 = { 11, 3, 7, 1, 14 };
		vector<double> medians2 = { 5, 7, 7.5, 14};

		for (size_t i = 0; i < keys1.size()-1; i++) {
			ds.erase(keys2[i]);

			if (ds.median() != medians2[i]) return 0;
		} //end-for

		ds.erase(keys2[keys2.size() - 1]);
		if (ds.empty() == false) return 0;

	}
	catch (exception & e) {
		cout << "Error: " << e.what() << endl;
		return 0;
	} // end-catch

	return 100;
} //end-Q1Test1


int Q1Test() {
	int grade = 0;
	
	grade += Q1Test1();

	return grade;
} //end-Q1Test