#ifndef WordUnit_H
#define WordUnit_H

#include <string>
#include <iostream>
using namespace std;

class WordUnit{
	public:
		//Constructor
		explicit WordUnit(string newWord);
		//Functions for string of word
		void setWord(string newWord);
		string getWord(void) const;
		//Functions for counter
		void setCounter(void);
		void increaseCounter(void);
		int getCounter(void) const;
	private:
		string word;	//Word being held
		int counter;	//Number of occurences in the text
};

#endif