//Bag.h
//Sarah kwon 2/14/2020

#ifndef _BAG_H
#define _BAG_H
#include "word.h"
#include <string>
#include "dnode.h"

#define LIMIT 1000 

class Bag {

public:
	void insert_word(std::string newEntry, std::string fileName);
	void print_words();
	void print(std::string word);

private:
	int bagSize = 0;
	dnode<Word>* head; 
};

#endif
