#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
using namespace std;


void SortedBag::makePlace(int pos) { // function to make place in array for adding
	for (int i = nrOfElem - 1; i >= pos; i--) { //counting down preventing override
		arr[i + 1] = arr[i]; // shift right
	}
} // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


void SortedBag::remPlace(int pos) { // function to remove item at pos in array
	for (int i = pos; i <= nrOfElem - 2; i++) {
		arr[i] = arr[i + 1]; // shift right
	}
} // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


SortedBag::SortedBag(Relation r) {
	capacity = 2;
	nrOfElem = 0;
	arr = (TComp*)malloc(capacity * sizeof(TComp));
	rel = r;
}


void SortedBag::add(TComp e) {
	if (isEmpty()) { // if empty then pass
		nrOfElem++;
		arr[0] = e;
		return;
	}
	else { // non-empty gets a go
		//cap full fixing
		if (nrOfElem == capacity) { //not enough cap
			if (capacity == 0) {
				capacity = 1;
			}
			else {
				capacity *= 2;
			}
			arr =(TComp*)realloc(arr, capacity * sizeof(TComp));
		}

		//rel testing
		if (rel(e, arr[0])) { // fits first pos
			//adding on first pos
			makePlace(0); // shift to free pos 0
			nrOfElem++;
			arr[0] = e;
			return;
		}
		else { // fits from pos 2 to last pos
			for (int i = 1; i <= nrOfElem - 1; i++) {
				if (rel(arr[i - 1], e) && rel(e, arr[i])) {
					//adding on position i
					makePlace(i); // make place for e
					nrOfElem++; // inc nb of elements
					arr[i] = e;
					return;
				}
			}
			if (rel(arr[nrOfElem - 1], e)) { // fits last pos
			//adding on last pos
				makePlace(nrOfElem - 1);
				nrOfElem++;
				arr[nrOfElem - 1] = e;
				return;
			}
		}
	}
} // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


bool SortedBag::remove(TComp e) {
	for (int i = 0; i <= nrOfElem - 1; i++) {
		if (arr[i] == e) {
			remPlace(i);
			nrOfElem--;
			if (nrOfElem == capacity / 2) { // P is dec - always called
				capacity /= 2;
				arr = (TElem*)realloc(arr, capacity * sizeof(TElem)); // use of realloc is ok
			}
			return true;
		}
	}
	return false;
} // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


bool SortedBag::search(TComp elem) const {
	for (int i = 0; i <= nrOfElem - 1; i++) {
		if (arr[i] == elem) {
			return true; // skip ahead
		}
	}
	return false; // nothing found
} // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


int SortedBag::nrOccurrences(TComp elem) const {
	int cont = 0;
	for (int i = 0; i <= nrOfElem - 1; i++) { // iterating lol
		if (arr[i] == elem) {
			cont++; // raise count
		}
	}
	return cont;
}  // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


int SortedBag::size() const {
	return nrOfElem;
}  // All cases:Theta(1)

bool SortedBag::isEmpty() const {
	if (nrOfElem != 0) {
		return false;
	}
	else {
		return true;
	}
}  // All cases:Theta(1)


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	free(arr); // malloc version of delete
}  // All cases:Theta(1)


void SortedBag::printSortedBag() const {
	//prints the bag itself
	cout << endl;
	for (int i = 0; i <= nrOfElem - 1; i++) {
		cout << arr[i] << ", ";
	}
}  // All cases:Theta(1)
