#include <string>

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

		return -1;
	}

private:
	const int LETTERCOUNT_MAX = 60;
};