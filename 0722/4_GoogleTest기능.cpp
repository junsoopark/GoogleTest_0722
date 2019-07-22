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
	int expected2 = 2;

	// Act
	// ASSERT_EQ(expected1, 11) << "Reason 1";  // !!
	// ASSERT_EQ(expected2, 22) << "Reason 2";
	EXPECT_EQ(expected1, 11) << "Reason 1";  // !!
	EXPECT_EQ(expected2, 22) << "Reason 2";
}
