#include "WordHistogram.h"

WordHistogram::WordHistogram(string newFileName){
	setFileName(newFileName);
}

////////////////////

void WordHistogram::addWord(string word){
	WordUnit newWord(word);
	wordList.push_back(newWord);
}

bool WordHistogram::checkWord(string word){
	vector<WordUnit>::iterator it = wordList.begin();
	while(it != wordList.end()){
		if(it->getWord() == word){
			return true;
		}
		it++;
	}
	return false;
}

WordUnit& WordHistogram::getWord(string word){
	//GetWord can only be called after checkWord
	//That is so it always returns a word
	vector<WordUnit>::iterator it = wordList.begin();
	while(it != wordList.end()){
		if(it->getWord() == word){
			return *it;
		}
		it++;
	}
}

void WordHistogram::makeHistogram(void){
   ifstream infile; 
   infile.open(filename); 
   string word;
   //Loop through every word in the file
   while (infile >> word)
   {
   		//check if the word has been added
      if(!this->checkWord(word)){
      	//if it hasn't been added, add it
         this->addWord(word);
      } else {
      	//if it has been added, increase the counter by 1
         this->getWord(word).increaseCounter();
      }
   }
   infile.close();
}

///////////////

void WordHistogram::setFileName(string newFileName){
	filename = newFileName;
}

string WordHistogram::getFileName(void){
	return filename;
}

void WordHistogram::exportHistogram(string textFile){
	ofstream YourOutputFileObject(textFile, ios::out);
	vector<WordUnit>::iterator it = wordList.begin();
	while(it != wordList.end()){
		YourOutputFileObject << it->getWord() << " " << it->getCounter() << endl;
		it++;
	}
}

/////////////

bool sortAlpha(const WordUnit &lhs, const WordUnit &rhs){
	return lhs.getWord() < rhs.getWord();
}

void WordHistogram::sortAlphaHistogram(void){
	sort(wordList.begin(),wordList.end(),sortAlpha);
}

bool sortFreq(const WordUnit &lhs, const WordUnit &rhs){
	return lhs.getCounter() > rhs.getCounter();
}

void WordHistogram::sortFreqHistogram(void){
	sort(wordList.begin(),wordList.end(),sortFreq);
}

bool sortFreqAlpha(const WordUnit &lhs, const WordUnit &rhs){
	if(lhs.getCounter() == rhs.getCounter()){
		return lhs.getWord() < rhs.getWord();
	}
	return lhs.getCounter() > rhs.getCounter();
}

void WordHistogram::sortFreqAlphaHistogram(void){
	sort(wordList.begin(),wordList.end(),sortFreqAlpha);
}

//////////////

void WordHistogram::printList(void){
	vector<WordUnit>::iterator it = wordList.begin();
	while(it != wordList.end()){
		cout << it->getWord() << " " << it->getCounter() << endl;
		it++;
	}
}