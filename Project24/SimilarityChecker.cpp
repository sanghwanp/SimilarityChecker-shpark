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

		int big, small;
		if (count1 > count2) {
			big = count1;
			small = count2;
		}
		else {
			big = count2;
			small = count1;
		}

		if (big >= small * 2)
			return 0;

		return getLetterCountPatialScore(big, small);
	}

	int getLetterCountPatialScore(int big, int small) {
		return round((1 - static_cast<double>(big - small) / small) * 60);
	}

private:
	const int LETTERCOUNT_MAX = 60;
};