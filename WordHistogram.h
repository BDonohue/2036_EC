#ifndef WordHistogram_H
#define WordHistogram_H

#include "WordUnit.h"
#include <vector> //Stores WordUnits
#include <algorithm> //Used to sort vectors
#include <iostream>	//Cout, Used to debug
#include <fstream> //Needed to read/write files
using namespace std;

class WordHistogram{
	public:
		//Constructor
		explicit WordHistogram(string newFileName);
		//Functions relating to Words
		void addWord(string word); //add a Word to histogram
		bool checkWord(string word); //Check if a word is in the histogram
		WordUnit& getWord(string word);  //Get a word from the histogram
		void makeHistogram(void); //make a histogram
		//Functions relating to Files 
		void setFileName(string newFileName); //set the filename
		string getFileName(void); //get the filename
		void exportHistogram(string textFile); //export the histogram to said filename
		//Functions relating to sorting
		void sortAlphaHistogram(void);	//sorts histogram alphabetically
		void sortFreqHistogram(void); 	//sorts histogram by frequency
		void sortFreqAlphaHistogram(void);	//sorts histogram by frequency, then alphabetically
		//Other
		void printList(void);	//prints list to iostream
	private:
		string filename;	//filename
		vector<WordUnit> wordList; //Vector of words
};

#endif