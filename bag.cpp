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
		newWord->insert(fileName);
		return;
	}  

	
	dnode<Word>* current = head;
	Word* currentWord = current->getData();
	dnode<Word>* lastNode = 0;
	while (current != NULL) {
		if (currentWord->getWord() == newEntry) {
			currentWord->insert(fileName);
			return;
		}
		if (current->getNext() == NULL) {
			lastNode = current;
		}
		current = current->getNext();
		if (current != NULL) currentWord = current->getData();
	}

	//if word DNE add to end of list
	dnode<Word>* newNode = new dnode<Word>();
	Word* newWord = new Word(newEntry);
	newWord->insert(fileName);
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

void Bag::printFilesWithWordThresh(std::string word, int t) {
	if (head == NULL) return;
	dnode<Word>* current = head;
	Word* currentWord = current->getData();
	while (current != NULL) {
		if (currentWord->getWord() == word) {
			//make word member function that iterates through linked list and prints 
			currentWord->printWordThreshFiles(t);
			return;
		}
		current = current->getNext();
		if (current != NULL) currentWord = current->getData();
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

void Bag::printWordUnion(std::string word1, std::string word2) {
	if (head == NULL) return; 

	dnode<Word>* wordOne = 0;
	dnode<Word>* wordTwo = 0;
	dnode<Word>* current = head;
	Word* currentWord = current->getData();
	while (current != NULL) {
		if (currentWord->getWord() == word1) {
			wordOne = current;
		}
		if (currentWord->getWord() == word2 && wordOne->getData()->getWord() != currentWord->getWord()) {
			wordTwo = current;
		}
		current = current->getNext();
		if (current != NULL) currentWord = current->getData();
	
	

	}


	Word* dummyWord = new Word();
	if (wordOne != NULL && wordTwo != NULL) {
		dummyWord->insertFiles(wordOne->getData());
		//dummyyWord->insertFiles2(wordTwo->getData());
		
	} else if (wordTwo != NULL) { 
		wordTwo->getData()->printFiles();
	} else {
		wordOne->getData()->printFiles();
	}
	

}
