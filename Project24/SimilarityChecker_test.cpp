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

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}