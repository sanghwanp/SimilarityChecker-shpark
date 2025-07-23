#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, getLetterCount) {
	EXPECT_EQ(5, checker.getLetterCount("12345"));
	EXPECT_EQ(3, checker.getLetterCount("abc"));
}

TEST_F(SimilarityCheckerFixture, getLetterCountScoreSame) {
	EXPECT_EQ(60, checker.getLetterCountScore("abc", "abc"));
	EXPECT_EQ(60, checker.getLetterCountScore("1234", "4235"));
}

TEST_F(SimilarityCheckerFixture, getLetterCountScoreZero) {
	EXPECT_EQ(0, checker.getLetterCountScore("abc", "abcabcabc"));
	EXPECT_EQ(0, checker.getLetterCountScore("1234123412341234", "4235"));
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}