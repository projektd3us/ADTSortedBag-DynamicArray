#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	this->current = 0;
}

TComp SortedBagIterator::getCurrent() {
	if (!this->valid()) {
		throw exception();
	}
	return this->bag.arr[this->current];
}

bool SortedBagIterator::valid() {
	if (this->current < this->bag.nrOfElem) {
		return true;
	}
	else {
		return false;
	}
}

void SortedBagIterator::next() {
	if (!this->valid()) {
		throw exception();
	}
	else {
		this->current++;
	}
}

void SortedBagIterator::first() {
	this->current = 0;
}

