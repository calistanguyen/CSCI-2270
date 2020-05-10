#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std; 

struct wordItem //each word struct stores what word it is and how many times the word appears (count)
{
	string word; 
	int count; 
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]);
bool isStopWord(string word, string ignoreWords[]);
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length);
void arraySort(wordItem uniqueWords[], int length);   
void printNext10(wordItem uniqueWords[], int topN, int totalNumWords);

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		string ignoreWords[50];
		getStopWords(argv[3], ignoreWords);
		int n = 100; 
		int idx = 0; 
		int arrayDoubleCounter = 0;
		wordItem *uniqueWords = new wordItem[n];

		ifstream myfile;
		myfile.open(argv[2]);

		if (myfile.is_open())
		{ 
			string line = "";
			while(getline(myfile, line))
			{
				stringstream str(line); 
				string temp; 

				while(getline(str, temp, ' '))
				{
					if (idx == n)
					{
						//do array doubling 
						arrayDoubleCounter++; 
						wordItem *temp = new wordItem[2*n];

						for (int i = 0; i < n; i++)
						{
							temp[i] = uniqueWords[i];
						}

						delete [] uniqueWords; 
						uniqueWords = temp; 
						n = 2*n;

					}

					if (isStopWord(temp, ignoreWords) == 0)
					{
						int check = 0; //checks if word exists in array or not 
						for (int i = 0; i < n; i++)
						{
							if (uniqueWords[i].word == temp)//if the word already exists 
							{
								uniqueWords[i].count ++; //incrament the count of that word 
								check++; //incrament check
							}
		
						}

						if (check == 0) //if check is never incramented, then add the word to the array
						{
							uniqueWords[idx].word = temp;
							uniqueWords[idx].count = 1; 
							idx++; //incrament the idx
						}

					}

				}

				
			}

		}
		myfile.close(); 

		arraySort(uniqueWords, idx);

		cout << "Array doubled: " << arrayDoubleCounter << endl; 
		cout << "#" << endl; 
		cout << "Unique non-common words: " << idx << endl; 
		cout << "#" << endl; 
		cout << "Total non-common words: " << getTotalNumberNonStopWords(uniqueWords, n) << endl; 
		cout << "#" << endl; 
		cout << "Probability of next 10 words from rank " << argv[1] << endl; 
		cout << "---------------------------------------" << endl; 
		printNext10(uniqueWords, stoi(argv[1]), getTotalNumberNonStopWords(uniqueWords, n));

	}


	else
	{
		
		cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl; 
	}


}

void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{
	 
	ifstream myfile; 
	myfile.open(ignoreWordFileName); 
	if (myfile.is_open())
	{
		string temp; 
		int x = 0;
		while (x < 50)
		{
			getline(myfile, temp, '\n');
			ignoreWords[x] = temp;
			x++; 
		}
	}

	myfile.close();

}


bool isStopWord(string word, string ignoreWords[])
{
	for (int i = 0; i < 50; i++)
	{
		if (word == ignoreWords[i])
		{
			return 1;
		}
	}

	return 0; 
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
	int numWords = 0; 
	for (int i = 0; i < length; i++)
	{
		numWords = numWords + uniqueWords[i].count; 
	}
	return numWords;
}
void arraySort(wordItem uniqueWords[], int length)
{
	int x = 0;
	while (x <= length)
	{
		for (int i = 0; i < length - 1; i++) //used bubble sorting 
		{
			wordItem word1 = uniqueWords[i]; 
			wordItem word2 = uniqueWords[i+1];

			if (word1.count < word2.count)
			{
				uniqueWords[i+1] = word1;
				uniqueWords[i] = word2; 
			}
		}
		x++;
	}
}

void printNext10(wordItem uniqueWords[], int topN, int totalNumWords)
{
	for (int i = 0; i < 10; i++)
	{
		int idx = topN + i;
		float probability = uniqueWords[idx].count / (float)totalNumWords; 
		printf("%.4f", probability);
		cout << " - " << uniqueWords[idx].word << endl;

	}

}











