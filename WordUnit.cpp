#include "WordUnit.h"

WordUnit::WordUnit(string newWord){
	setWord(newWord);
	setCounter();
}

void WordUnit::setWord(string newWord){
	word = newWord;
}

string WordUnit::getWord(void) const{
	return word;
}

void WordUnit::setCounter(void){
	//When a word is create, make sure the counter is started at 1
	counter = 1;
}

void WordUnit::increaseCounter(void){
	counter++;
}

int WordUnit::getCounter(void) const{
	return counter;
}