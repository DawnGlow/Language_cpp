#include <iostream>

using namespace std;

class A {  // 추상클래스
   public:
    virtual void f() = 0;  // 0 또는 NULL
};

class B : public A {
   public:
    void f() {
        cout << "B::f()" << endl;
    }
};

int main() {
    // A* a = new A; // 에러 발생 (순수가상함수를 하나라도 가진 객체의 인스턴스를 생성할 수 없음!)
    // A같은 클래스를 추상 클래스라 한다.
    A *a = new B;
    a->f();
    delete a;
}