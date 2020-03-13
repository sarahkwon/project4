//Bag.h
//Sarah kwon 2/14/2020

#ifndef _BAG_H
#define _BAG_H
#include "word.h"
#include "file.h"
#include <string>

#define LIMIT 1000 

class Bag {

public:
	void insert_word(std::string newEntry, std::string fileName);
	void print_words();
	void printResult(std::string input);
	void print(std::string word);
	void printFilesWithWordThresh(std::string word, int t);
	void printWordUnion(std::string word1, std::string word2);
private:
	int bagSize = 0;
	dnode<Word>* head = 0; 
};

#endif
