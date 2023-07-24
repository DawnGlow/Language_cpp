#include <iostream>
#include <string>
using namespace std;
namespace a {
int n;
}

namespace b {
int n;
}

void EX1(void) {
    // namespace : 이름들의 공간, 이름으로 치면 성, cout : 이름.
    std::cout << "Hello, World" << std::endl;
    // using namespace std; 사용  후
    cout << "hello world" << endl;
    int c, d;
    cin >> c >> d;
    cout << c << " + " << d << " = " << c + d << endl;
    a::n = 10;
    b::n = 20;
}

int main(void) {
    string str;
    str = "Hello";
    cout << str << endl;
    string name;
    cout << "이름 입력: ";
    cin >> name;
    string message = "안녕하세요, " + name + " 님!"; // string 끼리 더하기 가능.
    cout << message << endl;
}