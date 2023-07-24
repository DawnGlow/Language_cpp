#include <iostream>
using namespace std;

class MyClass {
   public:
    // 객체 하나 하나 마다 함수를 따로 만드는게 아니라, 하나의 함수를 만들어 놓고, 각각의 개체에 따라 호출되는 것이다.
    void PrintThis() {  // 보이지 않는 매개변수로 this를 항상 가지고 있다.
        cout << "나의 주소는 " << this << " 입니다." << endl;
    }
    void PrintThis2(MyClass *ptr) {
        cout << "나의 주소는 " << ptr << " 입니다." << endl;
    }
};

void EX1() {
    MyClass a, b;
    cout << "a의 주소는 " << &a << endl;
    cout << "b의 주소는 " << &b << endl;
    a.PrintThis();
    b.PrintThis();
}

int main(void) {
    EX1();
}