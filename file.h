  
//File.h
//Sarah Kwon 3/11/2020

#ifndef FILE_H
#define FILE_H

#include <string>

class File {

public:
	File();
	File(std::string fileName);
	int getCount() const;
	std::string getFileName() const;
	void setCount(int cunt);
	void increment();
private:
	std::string fileName;
	int count = 0; //number of times the word appeared in this file. 

};

#endif
