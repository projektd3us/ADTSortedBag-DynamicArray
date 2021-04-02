#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
using namespace std;


void SortedBag::makePlace(int pos) { // function to make place in array for adding
	for (int i = this->nrOfElem - 1; i >= pos; i--) { //counting down preventing override
		this->arr[i + 1] = this->arr[i]; // shift right
	}
} // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


void SortedBag::remPlace(int pos) { // function to remove item at pos in array
	for (int i = pos; i <= this->nrOfElem - 2; i++) {
		this->arr[i] = this->arr[i + 1]; // shift right
	}
} // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


SortedBag::SortedBag(Relation r) {
	this->capacity = 10;
	this->nrOfElem = 0;
	this->arr = new TComp[capacity];
	this->rel = r;
}


void SortedBag::add(TComp e) {
	if (this->isEmpty()) { // if empty then pass
		this->nrOfElem++;
		this->arr[0] = e;
		return;
	}
	else { // non-empty gets a go
		//cap full fixing
		if (this->nrOfElem == this->capacity) { //not enough cap
			this->capacity *= 2; // increasing cap
			TComp* temp_arr = new TComp[this->capacity]; // creating new arr
			for (int i = 0; i <= this->nrOfElem - 1; i++) { // copying arr contents
				temp_arr[i] = this->arr[i];
			}
			delete[] this->arr; // removing pointer location arr
			this->arr = temp_arr; // changing pointer location arr
		}

		//rel testing
		if (this->rel(e, this->arr[0])) { // fits first pos
			//adding on first pos
			makePlace(0); // shift to free pos 0
			this->nrOfElem++;
			this->arr[0] = e;
			return;
		}
		else { // fits from pos 2 to last pos
			for (int i = 1; i <= this->nrOfElem - 1; i++) {
				if (this->rel(arr[i - 1], e) && this->rel(e, arr[i])) {
					//adding on position i
					makePlace(i); // make place for e
					this->nrOfElem++; // inc nb of elements
					this->arr[i] = e;
					return;
				}
			}
			if (this->rel(this->arr[this->nrOfElem - 1], e)) { // fits last pos
			//adding on last pos
				makePlace(this->nrOfElem - 1);
				this->nrOfElem++;
				this->arr[this->nrOfElem - 1] = e;
				return;
			}
		}
	}
} // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


bool SortedBag::remove(TComp e) {
	for (int i = 0; i <= this->nrOfElem - 1; i++) {
		if (this->arr[i] == e) {
			remPlace(i);
			this->nrOfElem--;
			return true;
		}
	}
	return false;
} // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


bool SortedBag::search(TComp elem) const {
	for (int i = 0; i <= this->nrOfElem - 1; i++) {
		if (this->arr[i] == elem) {
			return true; // skip ahead
		}
	}
	return false; // nothing found
} // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


int SortedBag::nrOccurrences(TComp elem) const {
	int cont = 0;
	for (int i = 0; i <= this->nrOfElem - 1; i++) { // iterating lol
		if (this->arr[i] == elem) {
			cont++; // raise count
		}
	}
	return cont;
}  // Best case:Theta(1), Worst case:Theta(n) = Average Case, General case = O(n)


int SortedBag::size() const {
	return this->nrOfElem;
}  // All cases:Theta(1)

bool SortedBag::isEmpty() const {
	if (this->nrOfElem != 0) {
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
	delete[] this->arr;
}  // All cases:Theta(1)


void SortedBag::printSortedBag() const {
	//prints the bag itself
	cout << endl;
	for (int i = 0; i <= this->nrOfElem - 1; i++) {
		cout << this->arr[i] << ", ";
	}
}  // All cases:Theta(1)
