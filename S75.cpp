// 상속
// 부모가 자식에게 상속하면, 부모의 멤버들을 전부 사용하고, 자식만의 고유한 멤버를 추가로 가질 수 있다.
/*
남자 ) 총각 이듯이 부모 ) 자식이다.
자식이 부모한테 포함되는거고, 부모의 멤버가 자식의 멤버에 포함되는 것이다.
*/

#include <iostream>
using namespace std;

class Base {
   public:
    void bFunc() {
        cout << "Hello!" << endl;
    }
    int bNum;
};

class Derived : public Base {  // Base를 부모로 하는 클래스
   public:
    void dFunc() {
        cout << "Hello?" << endl;
    }
    int dNum;
};

int main(void) {
    Base b;
    Derived d;

    b.bFunc();
    b.bNum = 1;

    d.bFunc();
    d.bNum = 2;
    d.dFunc();
    d.dNum = 3;
}