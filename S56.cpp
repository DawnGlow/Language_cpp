// 생성자 : 객체가 생성될 때 자동으로 호출되는 함수
// 소멸자 : 객체가 소멸될 때 자동으로 호출되는 함수

#include <iostream>
using namespace std;

class MyClass {
   public:       // 아무것도 안적어도 빈 생성자와 소멸자가 있음.
    MyClass() {  // 생성자
        cout << "생성자 호출" << '\n';
    }
    ~MyClass() {  // 소멸자
        cout << "소멸자 호출" << '\n';
    }
};

// MyClass globalobj;
//  메인함수 실행 전 전역변수 생성자 호출, 메인함수 끝나고 소멸자 호출

void testlocalobj() {
    cout << "testlocalobj started" << '\n';
    MyClass localobj;
    // 지역변수는 순서대로 생성자 호출되고, 지역변수가 속한 함수가 끝나면, 소멸자가 호출됨.
    cout << "testlocalobj end" << '\n';
}

int main() {
    cout << "main function started" << '\n';
    testlocalobj();
    cout << "main function end" << '\n';
}