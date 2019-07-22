// 3A
//  : 테스트 함수를 구성하는 방법.
#include <gtest/gtest.h>


// SUT(System Under Test)
//  : 테스트 대상 코드
class Calculator {
public:
	void Enter(double value) {}
	void PressPlus() {}
	void PressMinus() {}
	
	double Display() { return 0; }
};
//------------------------------------

// 3A
// 1. Arrange
//  : 객체를 생성하고, 필요한 경우에 적절하게 설정하고 준비한다.
// 2. Act
//  : 객체에 작용을 가한다.
// 3. Assert
//  : 기대하는 바를 단언한다.
              
// $  g++ 2_3A.cpp -I. -lgtest -L. -pthread
// Calculator -> CalculatorTest (TestCaseName) 
TEST(CalculatorTest, Test1) {
	// Arrange
	Calculator* calc = new Calculator;

	// Act
	calc->Enter(2);
	calc->PressPlus();
	calc->Enter(2);

	// Assert
	if (calc->Display() != 4) {
		FAIL() << "2 + 2 == 4";
	}
}



