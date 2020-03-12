//Bag.cpp
//Sarah Kwon 2/14/2020

#include "bag.h"
#include <iostream>
#include <string>

using namespace std;

void Bag::insert_word(string newEntry, std::string fileName) {
	if (head == NULL) {
		head = new dnode<Word>();
		Word* newWord = new Word(newEntry);
		head->setData(newWord);
		File* newFile = new File(fileName);
		newWord->insert(newFile);
		return;
	}  

	
	dnode<Word>* current = head;
	Word* currentWord = current->getData();
	dnode<Word>* lastNode = 0;
	while (current != NULL) {
		//if newEntry == current Node then increment file
		if (currentWord->getWord() == newEntry) {
			File* newFile = new File(fileName);
			currentWord->insert(newFile);
			return;
		}
		if (current->getNext() == 0) {
			lastNode = current;
		}
		current = current->getNext();
		if (current != NULL) currentWord = current->getData();
	}

	//if word DNE add to end of list
	dnode<Word>* newNode = new dnode<Word>();
	Word* newWord = new Word(newEntry);
	File* newFile = new File(fileName);
	newWord->insert(newFile);
	newNode->setData(newWord);
	lastNode->setNext(newNode);
}

void Bag::print_words() {
	if (head == NULL) return;
	dnode<Word>* current = head;
	Word* currentWord = current->getData();
	while (current != NULL) {
		cout << currentWord->getWord() << "::";
		currentWord->printFiles();
		current = current->getNext();
		if (current != NULL)
		currentWord = current->getData();
	}
}

void Bag::print(std::string input) {
	bool isThere = false;
	dnode<Word>* current = head;
	Word* currentWord = current->getData();
	for (int i = 0; i < bagSize; i++) {
		if (currentWord->getWord() == input) {
			cout << "Total Count: " << currentWord->sum() << endl;
			currentWord->printFiles();
			isThere = true; 
		}
		current = current->getNext();
		currentWord = current->getData();
	} 

	if (!isThere) {
		cout << "Word not found in database" << endl;
	}

}
