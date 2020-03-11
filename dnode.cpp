#include "dnode.h"
#include <cstddef>

using namespace std;


template<typename T>
dnode<T>* dnode<T>::getNext() {
	return next;
}

template<typename T>
dnode<T>* dnode<T>::getPrev() {
	return prev;
}

template<typename T>
void dnode<T>::setNext(dnode<T>* newNext) {

	dnode<T>* nextNext = 0;
	if (this->next->next != NULL) {
		nextNext = this->next->next;
	}
	delete this->next; 
	
	this->next = nextNext;
	newNext->prev = *this; 
		
}

template<typename T>
void dnode<T>::setPrev(dnode<T>* newPrev) {

	dnode<T>* prevPrev = 0;
	if (this->prev->prev != NULL) {
		prevPrev = *this->prev->prev;
	}
	delete this->prev;

	this->prev = prevPrev;
	newPrev->prev = *this;
}

template<typename T>
void dnode<T>::setData(T newData) {
	data = newData; 
}

template<typename T>
T* dnode<T>::getData() {
	return *data; 
}

