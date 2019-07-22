#include <gtest/gtest.h>

// 1. 단언 매크로
//    ASSERT_EQ / NE / LT / GT / LE / GE ...
//    주의할 점
//     -> 단언문이 실패할 경우, 이후의 코드는 수행되지 않습니다.

// 테스트 함수 안에서는 하나의 테스트 단언문만 존재해야 한다.
//  => 너무 많은 테스트 함수가 만들어질 수 있다.

// 구글 테스트는 다른 형태의 단언 매크로를 제공하고 있습니다.
//  => EXPECT를 사용하면, 테스트가 실패하더라도, 이후의 코드를 수행합니다.
TEST(GoogleTestSamle, Test1) {
	int expected1 = 1;
	int expected2 = 22;

	// Act
	// ASSERT_EQ(expected1, 11) << "Reason 1";  // !!
	// ASSERT_EQ(expected2, 22) << "Reason 2";
	EXPECT_EQ(expected1, 11) << "Reason 1";  // !!
	EXPECT_EQ(expected2, 22) << "Reason 2";
}

#include <string> // C++
                  // C: const char* / char[]

// 2. 문자열 비교 단언문
TEST(GoogleTestSample, Test2) {
	std::string s1 = "Hello";
	std::string s2 = "Hello";

	ASSERT_EQ(s1, s2);     // ==
	// EQ(==), NE(!=), LE(<=), GE(>=), LT(<), GT(>)
	//  : 사용자 정의 객체에 대해서 단언 매크로를 사용할 경우,
	//    위의 연산이 '연산자 오버로딩'을 통해 제공되어야만 합니다.

	const char* s3 = "Hello";
	const char* s4 = s2.c_str();

	// C의 문자열은 ASSERT_EQ / EXPECT_EQ를 통해 비교할 경우,
	// 제대로 동작하지 않을 수 있습니다.
	// ASSERT_EQ(s3, s4);
	ASSERT_STREQ(s3, s4);
}

// 3. 부동 소수점
TEST(GoogleTestSample, Test3) {
	double a = 0.7;
	double b = 0.1 * 7;

	// ASSERT_DOUBLE_EQ(a, b);
	ASSERT_NEAR(a, b, 0.00000000001);

#if 0
	if (a == b) {
		printf("Same\n");
	} else {
		printf("Diff\n");
	}
#endif

	// ASSERT_EQ(a, b);
}


























