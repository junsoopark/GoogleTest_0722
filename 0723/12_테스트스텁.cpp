// 12_테스트스텁_12.cpp
#include <exception>

class IOException : public std::exception {
public:
	virtual const char* what() {
		return "Bad connection";
	}
};

class User;
struct IConnection {
	virtual void Move(int x, int y) = 0;
	virtual void Attack(User* p) = 0;
};

class TCPConnection : public IConnection {
	// 현재 네트워크 연결이 존재하지 않을 경우, IOException 던집니다.
	virtual void Move(int x, int y) {}
	virtual void Attack(User* p) {}
};

class User {
	IConnection* conn;
public:
	User(IConnection* p) : conn(p) {}

	void Move(int x, int y) {
		// ....
		conn->Move(x, y);
	}

	void Attack(User* user) {
		// ....
		conn->Attack(user);
	}
};

//-----------------------------
// 네트워크 연결이 존재하지 않을 때, User Move의 동작이 예외를 던지는지 확인하고 싶다.
// => 특수한 상황에서 SUT의 동작을 확인하고 싶다.
#include <gtest/gtest.h>

class UserTest : public ::testing::Test {
};


TEST_F(UserTest, MoveTest) {
	TCPConnection conn;
	User user(&conn);

	ASSERT_THROW(user.Move(10, 32), IOException);
}
















