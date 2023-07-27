// 정적 바인딩
#include <iostream>
using namespace std;

class Base {
   public:
    void Print() {
        cout << "From Base!!!" << endl;
    }
};

class Derived : public Base {
   public:
    void Print() {
        cout << "From Derived!!!" << endl;
    }
};

class Derived2 : public Base {
};

// Derived d;
//  Base *b = &d;  // 에러 X. 부모클래스의 포인터가 자식클래스를 가리킬 수 있다.
//  Base : 남자, Derived : 총각. 남자-> 남자, 남자 -> 총각 문제가 없다. 남자)총각이니까.
int main() {
    Base *b = new Derived();
    b->Print();          // result : From Base!! Why?
    b = new Derived2();  // 만약 derived를 호출하게했다고치면, b가 derived2를 가리키게 됬을 때 아래 코드에서 에러를 호출하거나, 갑자기 부모꺼를 호출해야함. --> 일관성이 없고 모호해짐.
    b->Print();          // 그래서 부모의 함수를 출력한다. --> 어떤걸 호출해야하는지를 바인딩이라고 한다.
                         // 정적바인딩은 컴파일시간에 b->print가 Base.print 가되는걸, 정적 바인딩.
                         // b가 가리키는 객체가 부모인지, 자식인지 구별하기 힘드니, 부모클래스를 호출하라는게 정적 바인딩.
                         // 동적바인딩은 b가 Base가 될수도, derived가 될수도 derived2가 될수도 있게 하는 걸 동적 바인딩.
    delete b;
}