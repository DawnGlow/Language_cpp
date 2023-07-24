// static : 정적 <-> 동적
// 동적 : 객체에 포함. 각각 붕어빵 마다 팥의 양이 다른 것이 해당
// 정적 : 붕어빵 틀에 해당하는 멤버.

// 정적 메소드 : 전역 함수가 클래스와 밀접한 관련이 있고, 멤버 변수에 접근해야 하는 경우에 사용
#include <iostream>
using namespace std;

// 0~1 float R G B
class Color {
   public:
    Color() : r(0), g(0), b(0) {}
    Color(float r, float g, float b) : r(r), g(g), b(b) {}
    float GetR() { return r; }
    float GetG() { return g; }
    float GetB() { return b; }

    static Color MixColors(Color a, Color b) {  // 컬러랑 밀접한 관계라서 컬러 멤버에 함수를 넣고 싶음.
        return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
    }

   private:
    float r;
    float g;
    float b;
};

/*
Color MixColors(Color a, Color b) {  // 컬러랑 밀접한 관계라서 컬러 멤버에 함수를 넣고 싶음.
    return Color((a.GetR() + b.GetR()) / 2, (a.GetG() + b.GetG()) / 2, (a.GetR() + b.GetR()) / 2);
}
*/

int main() {
    Color blue(0, 0, 1);
    Color red(1, 0, 0);
    // Color purple = MixColors(blue, red);
    Color purple = Color::MixColors(blue, red);
    cout << "r = " << purple.GetR() << " g = " << purple.GetG() << " b = " << purple.GetB() << '\n';
}
