#include <string>

// 스위트 픽스쳐
class Database {
public:
	void Connect() {}
	void Disconnect() {}

	void Login(const std::string& id, const std::string& password) {}
	void Logout() {}

	bool IsLogin() { return false; }
};

//--------------------------------------
#include <gtest/gtest.h>

class DatabaseTest : public ::testing::Test {
protected:
	static std::string test_id;
	static std::string test_password;

	Database* database;
	virtual void SetUp() override {
		database = new Database;
		database->Connect();
	}

	virtual void TearDown() override {
		database->Disconnect();
		delete database;
	}
};

std::string DatabaseTest::test_id = "test_id";
std::string DatabaseTest::test_password = "test_password";

TEST_F(DatabaseTest, LoginTest) {
	database->Login(test_id, test_password);

	ASSERT_TRUE(database->IsLogin());
}

TEST_F(DatabaseTest, LogoutTest) {
	database->Login(test_id, test_password);
	database->Logout();

	ASSERT_FALSE(database->IsLogin());
}

#if 0
TEST_F(DatabaseTest, LoginTest) {
	Database* database = new Database;
	database->Connect();
	std::string test_id = "test_id";
	std::string test_password = "test_password";

	database->Login(test_id, test_password);

	ASSERT_TRUE(database->IsLogin());

	database->Disconnect();
	delete database;
}

TEST_F(DatabaseTest, LogoutTest) {
	Database* database = new Database;
	database->Connect();
	std::string test_id = "test_id";
	std::string test_password = "test_password";

	database->Login(test_id, test_password);
	database->Logout();

	ASSERT_FALSE(database->IsLogin());

	database->Disconnect();
	delete database;
}
#endif













