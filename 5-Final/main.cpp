#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

extern int Q1Test();
extern int Q2Test();
extern int Q3Test();
extern int Q4Test();
extern int Q5Test();

int main() {
	double grade = 0;

	grade += 0.25*Q1Test();
	grade +=  Q2Test();
	grade += Q3Test();
	grade += Q4Test();
	grade += Q5Test();

	printf("Your final grade is: %.1lf\n", grade);
} //end-main