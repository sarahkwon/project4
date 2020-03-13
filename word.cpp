//Word.cpp
//Sarah Kwon 2/14/2020

#include "word.h"
#include <iostream>
#include <string> 

using namespace std;

Word::Word(std::string word) {
	this->word = word;
	head = 0;
}

std::string Word::getWord() const {
	return word;
}

int Word::getSize() const {
	return currentSize;
}

dnode<File>* Word::getHead() const {
	return head;
} 

void Word::filesIncrement(std::string fileName) {
	if (head == NULL) return; 

	dnode<File>* currentNode = head;
	File* currentFile = currentNode->getData();
	while (currentNode != NULL) {
		if (currentFile->getFileName() == fileName) {
			currentFile->increment();
			return;	
		}
		currentNode = currentNode->getNext();
		if(currentNode != NULL) currentFile = currentNode->getData();
	}
}

void Word::insertFiles(Word* wordie) {
	if (wordie->getHead() == NULL) return;
	dnode<File>* current = wordie->getHead();
	File* currentFile = current->getData();
	while (current != NULL) {
		File* newFile = new File(currentFile->getFileName());
		dnode<File>* newNode = new dnode<File>(newFile);
		if(head == NULL) head = newNode;
		sortLexi(&head, newNode);
		cout << head->getData()->getFileName() << endl;
		current = current->getNext();
		if (current != NULL) currentFile = current->getData();
	}
}

bool Word::containsFile(std::string fileName) {
	if (head == NULL) return false;
	dnode<File>* currentNode = head;
	File* currentFile = currentNode->getData();
	for (int i = 0; i < currentSize; i++) {
		if (currentFile->getFileName() == fileName) {
			return true;
		}
		currentNode = currentNode->getNext();
		currentFile = currentNode->getData();
	}
	return false;
}

void Word::insert(string newEntry) {
	if (head == NULL) {
		File* newFile = new File(newEntry);
		head = new dnode<File>(newFile); 
	}
	dnode<File>* currentNode = head;
	File* currentFile = currentNode->getData();
	while (currentNode != NULL) {
		if (currentFile->getFileName() == newEntry) {
			currentFile->increment();
			return;
		}

		currentNode = currentNode->getNext();
		if (currentNode != NULL) currentFile = currentNode->getData();
	}
	File* newFile = new File(newEntry);
	dnode<File>* newNode = new dnode<File>(newFile);
	newFile->increment();
	sortLexi(&head, newNode); 
}

void Word::sortLexi( dnode<File>** head_ref, dnode<File>* newNode) {
	if (*head_ref == NULL) {
		*head_ref = newNode;
	} else if ((*head_ref)->getData()->getFileName() >= newNode->getData()->getFileName()) {
		newNode->setNext(*head_ref);
		dnode<File>* temp = newNode->getNext();
		temp->setPrev(newNode); 
		*head_ref = newNode; 
	} else {
		dnode<File>* current = *head_ref;
		File* currentFile = current->getData();
		while (current->getNext() != NULL && 
			currentFile->getFileName() < newNode->getData()->getFileName()) {
			current = current->getNext();
			currentFile = current->getData();
		}	
			newNode->setNext(current->getNext());

			if (current->getNext() != NULL) {
				dnode<File>* temp = newNode->getNext();
				temp->setPrev(newNode);
			}

			current->setNext(newNode);
			newNode->setPrev(current);
		
	}
	
}


int Word::sum() {
	int result = 0;
	dnode<File>* current = head;
	File* currentFile = current->getData();
	for (int i = 0; i < currentSize; i++ ){
		result += currentFile->getCount(); 
	}
	return result;
}

void Word::printWordThreshFiles(int t) {
	if (head == NULL) return;
	dnode<File>* current = head;
	File* currentFile = current->getData();
	while (current != NULL) {
		if (currentFile->getCount() >= t) {
			cout << currentFile->getFileName() << endl;
		}
		current = current->getNext();
		if (current != NULL) currentFile = current->getData();
	}
}

void Word::printFiles() {
	if (head == NULL) return;
	dnode<File>* current = head;
	File* currentFile = current->getData();
	while (current != NULL) {
		cout << currentFile->getFileName() << endl;
		current = current->getNext();
		if (current != NULL) currentFile = current->getData();
	}
}



//Word& Word::operator=(Word& source) {
	

//	return *this;

//}
