// override : 우선하다
// overload: 다중정의할때
// overwrite : 덮어쓰다.
#include <iostream>
using namespace std;

class Base {
   public:
    int a = 10;  // Base() : a(10) {}이랑 똑같음.
    void Print() {
        cout << "From Base!!!" << endl;
    }
};

class Derived : public Base {
   public:
    int a = 20;
    void Print() {
        cout << "From Derived!!!" << endl;
    }
};

int main(void) {
    Base b;
    Derived d;

    cout << b.a << endl;           // result : 10
    cout << d.a << endl;           // result : 20, 자기 고유멤버가 상속멤버보다 우선순위가 높음.
    cout << d.Base::a << endl;     // result : 10 : d의 멤버중에 Base에 속해있는 a를 출력해
    cout << d.Derived::a << endl;  // result : 20

    d.Print();
    d.Base::Print();  // Base 명시
    d.Derived::Print();
}