// 묵시적(암시적) 형변환 implicit conversion
// 명시적 형변환 explicit conversion

#include <iostream>
#include <string>
using namespace std;

class Item {
   public:
    Item(int num) : num(num) {  // 변환 생성자
        cout << "Item(int)" << '\n';
    }
    Item(string name) : name(name) {  // 변환 생성자
        cout << "Item(string)" << '\n';
    }
    Item(int num, string name) : num(num), name(name) {
        cout << "Item(int, string)" << '\n';
    }
    void print() {
        cout << num << " : " << name << endl;
    }

   private:
    int num;
    string name;
};

int main(void) {
    Item i1 = Item(1);
    Item i2(2);
    Item i3 = 3;
    i3 = 3;  // int형 3을 i3에 ??
    // 3을 item객체로 변환시킴(임시객체 생성) --> 이동생성자를 통해 i3로 대입
    // 묵시적 변환

    Item i4 = (Item)4;  // Item(int num) 생성자가 형 변환까지 하고 있음.
    // 명시적 변환

    Item i5(5);
    // i5 = "stone"; 에러 발생 : const char형 생성자를 만들어줘야함.
    i5 = (string) "stone";

    Item i6(1, "grass");
    Item i7 = {2, "dirt"};
    i7 = {2, "dirt"};  // c++11 문법
    Item i8{3, "wood"};

    i1.print();
    i2.print();
    i3.print();
    i4.print();
    i5.print();
    i6.print();
    i7.print();
    i8.print();
}