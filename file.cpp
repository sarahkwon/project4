//File.cpp
//Sarah Kwon 2/14/2020

#include "file.h"
#include <iostream>
#include <string>

using namespace std;

File::File() {
	fileName = "";
}

File::File(std::string fileName) {
	this->fileName = fileName; 
}

void File::setCount(int cunt) {
	count = cunt;
}

int File::getCount() const {
	return count;
}

std::string File::getFileName() const {
	return fileName; 
}

void File::increment() {
	count++;
}
