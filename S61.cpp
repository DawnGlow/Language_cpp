// 연산자 오버로딩
// 벡터
// 멤버 메서드

#include <iostream>
using namespace std;

class Vector2 {
   public:
    // Vector2() : x(0), y(0) {}
    Vector2();
    // Vector2(float x, float y) : x(x), y(y) {}
    Vector2(float x, float y);
    // get함수는 const로 선언하는 것이 좋음
    // float GetX() const { return x; }
    float GetX() const;

    // float GetY() const { return y; }
    float GetY() const;
    static Vector2 Sum(Vector2 a, Vector2 b);
    Vector2 Add(Vector2 rhs) {
        return Vector2(x + rhs.x, y + rhs.y);
        // rhs.GetX()를 사용 안해도 된다. 
        // 참조 : https://blog.naver.com/PostView.naver?blogId=tipsware&logNo=221667799577
    }

   private:
    float x;
    float y;
};

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}

float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }
// 정적 메소드 프로토타입
Vector2 Vector2::Sum(Vector2 a, Vector2 b) {
    return Vector2(a.x + b.x, a.y + b.y);
}

int main(void) {
    Vector2 a(2, 3);
    Vector2 b(-1, 4);
    cout << a.GetX() << " , " << a.GetY() << '\n';
    cout << b.GetX() << " , " << b.GetY() << '\n';
    Vector2 c = Vector2::Sum(a, b);
    Vector2 c2 = a.Add(b);
    cout << c.GetX() << " , " << c.GetY() << '\n';
    cout << c2.GetX() << " , " << c2.GetY() << '\n';
}