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
		return 0;
	}

private:
	const int LETTERCOUNT_MAX = 60;
};