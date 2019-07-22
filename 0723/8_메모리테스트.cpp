#include <gtest/gtest.h>

// 특정 객체에 대해서 동작 수행 후 메모리가 제대로 해지되었는지 여부를
// 검증할 수 있다.
// -> C++은 클래스의 메모리 할당 연산을 재정의하는 것이 가능합니다.
//  : tcmalloc, jemalloc

class Image {
public:
	void* operator new(size_t size) {
		printf("객체 할당\n");
		return malloc(size);
	}

	void operator delete(void* p, size_t) {
		printf("객체 해지\n");
		free(p);
	}
};

void foo() {
	Image* img = new Image;
	printf(".....\n");
	delete img;
}

TEST(MemoryLeakTest, imageTest) {
	foo();
}








