//Word.h
//Sarah Kwon 2/14/2020

#ifndef WORD_H
#define WORD_H

#include <string>
#include "file.h"
#include "dnode.h"

#define MAX 10 //max amount of files per Word 

class Word {


public:
	Word() {word = ""; head = 0; } 
	Word(std::string word); 
	std::string getWord() const;
	int getSize() const;
	dnode<File>* getHead() const;
	void insert(std::string newEntry);
	bool containsFile(std::string fileName);
	void filesIncrement(std::string fileName);
	int sum();
	void printFiles();
	void sortLexi(dnode<File>** head_ref, dnode<File>* newNode); 
	void printWordThreshFiles(int t); 

private:  
	std::string word;
	dnode<File>* head = 0;
	int currentSize = 0; //max index of Word 
};

#endif
