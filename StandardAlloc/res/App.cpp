#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

bool relation_test(TComp r1, TComp r2) {
	return r1 <= r2;
}

int main() {
	testAll();
	testAllExtended();

	cout << "Test over" << endl;
	system("pause");
}
