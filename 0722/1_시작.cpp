// 1. include
#include <gtest/gtest.h>

// main을 직접 작성하는 것이 아니라, 이미 제공하는 main을 정적 라이브러이에 포함해서 사용하고 싶다.
#if 0
// 2. main
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
#endif
