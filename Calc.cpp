#include <iostream>
#include <vector>
#include <list>
#include "Common.h"

using namespace std;

void Calc(string words, stringC& result) {
	int countWord = words.size();
	char firstLetter = words[0];
	char lastLetter = words[words.size() - 1];

	int *randArrayIndex{ new int[countWord] };

	randArrayIndex[0] = 0;
	for (int i = 0;i < countWord-2;i++) {
		randArrayIndex[i] = 0;
	}
	randArrayIndex[countWord - 1] = countWord - 1;

	int random;
	for (int i = 1; i < countWord - 1; i++)
	{
		for (;;)
		{
			bool good = true;
			random = rand() % countWord;
			for (int j = 0; j < countWord; j++)
			{
				if (random == randArrayIndex[j]) { good = false; break; }
			}
			if (good) break;
		}
		randArrayIndex[i] = random;

	}

	string* resultArray{ new string[countWord] };
	for (int i = 0;i < countWord;i++) {
		resultArray[i] = words[randArrayIndex[i]];
		result.setStr(resultArray[i]);
	}

  delete[] resultArray;
	delete[] randArrayIndex;
};