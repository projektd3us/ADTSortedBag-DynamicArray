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



	//SortedBag f(relation_test);
	//if (f.isEmpty()) {
	//	cout << "this bitch empty" << endl;
	//}
	//f.printSortedBag();

	//f.add(1);
	//f.printSortedBag();
	//f.add(5);
	//f.printSortedBag();
	//f.add(11);
	//f.printSortedBag();
	//f.add(27);
	//f.printSortedBag();
	//f.add(12);
	//f.printSortedBag();
	//f.add(0);
	//f.printSortedBag();
	//f.add(4);
	//f.printSortedBag();

	//f.add(4);
	//f.add(4);
	//f.add(4);
	//f.printSortedBag();
	//f.remove(0);
	//f.printSortedBag();
	//f.remove(2);
	//f.printSortedBag();
	//cout << endl;

	//cout << "the number 4 occured: " << f.nrOccurrences(4) << " times.";
	//cout << endl;

	//if (f.search(1)) {
	//	cout << "found a one" << endl;
	//}
	//cout << endl;

	//cout << "the size of the bag is: " << f.size() << endl;

	//if (!f.isEmpty()) {
	//	cout << "this bitch not empty" << endl;
	//}

	cout << "Test over" << endl;
	system("pause");
}
