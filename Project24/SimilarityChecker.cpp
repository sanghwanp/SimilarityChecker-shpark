#include <string>
#include <iostream>

class SimilarityChecker {
public:
	int getLetterCount(std::string letter) {
		return letter.length();
	}

	int getLetterCountScore(std::string letter1, std::string letter2) {
		int count1 = getLetterCount(letter1);
		int count2 = getLetterCount(letter2);

		if (count1 == count2) {
			return LETTERCOUNT_MAX;
		}

		int longcount, shortcount;
		if (count1 > count2) {
			longcount = count1;
			shortcount = count2;
		}
		else {
			longcount = count2;
			shortcount = count1;
		}

		if (longcount >= shortcount * 2)
			return LETTERCOUNT_MIN;

		return getLetterCountPatialScore(longcount, shortcount);
	}

	int getLetterCountPatialScore(int longcount, int shortcount) {
		return round((1 - static_cast<double>(longcount - shortcount) / shortcount) * 60);
	}

private:
	const int LETTERCOUNT_MAX = 60;
	const int LETTERCOUNT_MIN = 0;
};