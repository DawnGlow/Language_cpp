#include <iostream>
using namespace std;
// using namespace junseo; // set()이라는 함수가 junseo와 전역으로 2개가 있어서 모호성이 발생, junseo::는 생략할 수 없지만, junseo::google은 google::로 생략 가능
int n;
void set() {
    n = 10;
}

namespace junseo {
int n;
void set() {
    n = 20;
}
namespace google {
void set() {
    n = 30;  // junseo의 n을 30으로 초기화.
}
int n;  // 컴파일러가 set을 만난 후에 n이 선언됨을 확인해서 set함수로 초기화 x. 하지만 프로토타입 사용 시에는 네임스페이스 안의 변수에 대입.
}  // namespace google
}  // namespace junseo

void EX1() {
    ::set();
    junseo::set();
    junseo::google::set();

    cout << ::n << endl;
    cout << junseo::n << endl;
    cout << junseo::google::n << endl;
}

int main() {
    EX1();
}
/* 프로토타입 선언시 위에 순서에 의해 값이 바뀌는일은 발생하지 않는다.
void junseo::set() {
    n = 20;
}

void junseo::google::set() {
    n = 30;
}
*/