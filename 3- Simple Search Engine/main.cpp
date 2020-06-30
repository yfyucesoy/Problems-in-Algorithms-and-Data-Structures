#include <stdio.h>
#include <iostream>
#include <vector>

#include "Index.h"

using namespace std;

int main() {
	vector<string> files = { "01.txt", "02.txt", "03.txt", "04.txt", "05.txt" };

	CreateIndex(files);

	vector<string> keywords = { "science" };
	Search(keywords);
	printf("------------------------------------------------------------\n");

	keywords = { "computer", "science" };
	Search(keywords);
	printf("------------------------------------------------------------\n");

	keywords = { "network", "router", "switch" };
	Search(keywords);
	printf("------------------------------------------------------------\n");

	return 0;
} //end-main