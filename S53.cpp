#include <iostream>
using namespace std;

int n;
void set();  // 프로토타입

namespace junseo {  // 프로토타입
int n;
void set();
}  // namespace junseo

namespace google {
int n;
void set();
}  // namespace google

void EX1(void) {
    ::set();
    junseo::set();
    google::set();
    cout << ::n << endl;
    cout << junseo::n << endl;
    cout << google::n << endl;
}

int main(void) {
    EX1();
}

void set() {
    ::n = 10;  // 명시적 전역변수
}

namespace junseo {
void set() {
    n = 20;  // 변수의 소속을 밝히지 않은 경우 네임스페이스 안에있는 변수를 사용한다. 여기선 junseo::n = 20;
}
}  // namespace junseo

/*
namespace google {
void set() {
   n = 30;
}
}
*/
// namespace google

void google::set() {
    n = 30;
}
