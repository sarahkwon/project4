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
	count = 1; 
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
