// 다운 캐스팅
// static_cast, dynamic_cast
// double -> int / int -> double 이런건 static_cast : 컴파일시간에 완료

#include <iostream>

using namespace std;

class Base {
   public:
    int a = 1;
};

class Drv1 : public Base {
   public:
    void f() {
        cout << "Drv::f()" << endl;
        cout << b << endl;
    }
    float b = 3.14;
};

class Drv2 : public Base {
   public:
    void f() {
        cout << "Drv2::f()" << endl;
        cout << c << endl;
    }
    int c = 3;
};

int main() {
    /*
      Base *b = new Drv1;
      // 다운 캐스팅 : Drv1 *d1 = b; 자동으로 허용 X
      int *a = new int(5);
      Drv1 *d1 = static_cast<Drv1 *>(b);

      Base *c = new Drv2;
      Drv2 *d2 = static_cast<Drv2 *>(c);
      d1->f();
      d2->f();
      */
    /*
    실수로 아래 상황이 생겼다고 해보자
    */
    Base *b = new Drv1;
    Drv2 *d2 = static_cast<Drv2 *>(b);  // 실제론 drv1을 가리키는데 drv2를 가리키고 있다고 착각하고있음. (dynamic cast로 런타임시 체크 가능함. 다음 코드에서)
    // 정상적이였다면 d2의 주소를 받아 c의 3이 출력됨
    // 하지만 drv1을 가리키고 있으니, c를 출력하려고 하니 3.14가 있네? 그래서 이진법으로 저장된 수를 int로 해석해서 출력해버림.
    d2->f();
    delete b;
}