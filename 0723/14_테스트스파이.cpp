
#include <stdio.h>
#include <string>
#include <vector>

// 분산 로거
//  : 전달된 로깅 메시지를 등록된 타겟에게 전파하는 역활
enum DLogLevel {
	INFO, WARN, ERROR,
};

struct DLogTarget {
	virtual void Write(DLogLevel level, const std::string& message) = 0;
	virtual ~DLogTarget() {}
};

class DLog {
	std::vector<DLogTarget*> targets;
public:
	void AddTarget(DLogTarget* p) { targets.push_back(p); }
	
	void Write(DLogLevel level, const std::string& message) {
		for (DLogTarget* e : targets) {
			e->Write(level, message);
		}
	}
};

