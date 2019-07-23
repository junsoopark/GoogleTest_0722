
// 13_Fake Object

#include <string>

class User {
private:
	std::string name;
	int age;

public:
	User(const std::string& n, int a) : name(n), age(a) {}

	std::string getName() const {
		return name;
	}

	int getAge() const {
		return age;
	}
};

struct IDatabase {
	virtual void Save(const std::string& name, int age) = 0;
	virtual User* Load(const std::string& name) = 0;

	virtual ~IDatabase() {}
};

// User 객체를 데이터베이스 저장하고, 불러오는 역활.
class UserManager {
private:
	IDatabase* database;
public:
	UserManager(IDatabase* p) : database(p) {}

	void Save(User* p) {
		database->Save(p->getName(), p->getAge());
	}

	User* Load(const std::string& name) {
		return database->Load(name);
	}
};

#include <gtest/gtest.h>












