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

    // 멤버 연산자
    // 문제점 1. 선언 정리 분리 안됨 / 2. const 사용하고 싶음 / 3, 매개변수도 const
    Vector2 operator+(Vector2 rhs) const;      // 프로토타입
    Vector2 operator-(Vector2 rhs) const;      // 프로토타입
    Vector2 operator*(const float rhs) const;  // 프로토타입(벡터에 실수 곱하는 함수)
    Vector2 operator/(const float rhs) const;  // 프로토타입(벡터에 실수 나누는 함수)
    float operator*(Vector2 rhs) const;        // 연산자 오버로딩
                                               /*
                                                   return Vector2(x + rhs.x, y + rhs.y);
                                                   // rhs.GetX()를 사용 안해도 된다.
                                                   // 참조 : https://blog.naver.com/PostView.naver?blogId=tipsware&logNo=221667799577
                                               */

   private:
    float x;
    float y;
};

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}

float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }
// 비 멤버연산자
Vector2 operator*(const float a, const Vector2 b) {  // ex) 1,6 * Vector2typeclass
    return Vector2(a * b.GetX(), a * b.GetY());      // 전역함수라 get 함수 사용.
}
// 멤버연산자
Vector2 Vector2::operator+(const Vector2 rhs) const {
    return Vector2(x + rhs.x, y + rhs.y);
}
Vector2 Vector2::operator-(const Vector2 rhs) const {
    return Vector2(x - rhs.x, y - rhs.y);
}
Vector2 Vector2::operator*(const float rhs) const {  // ex) Vector2typeclass * 1.6
    return Vector2(x * rhs, y * rhs);
}
Vector2 Vector2::operator/(const float rhs) const {
    return Vector2(x / rhs, y / rhs);
}
float Vector2::operator*(const Vector2 rhs) const {  // Vector의 내적. Vector 각 성분끼리 곱의 합.
    return x * rhs.x + y * rhs.y;
}

int main(void) {
    Vector2 a(2, 3);
    Vector2 b(-1, 4);
    cout << a.GetX() << " , " << a.GetY() << '\n';
    cout << b.GetX() << " , " << b.GetY() << '\n';
    Vector2 c = a - b;
    Vector2 c2 = a * 1.6;  // 1.6 * a는 에러 발생
    Vector2 c3 = a / 2;
    float c4 = a * b;
    Vector2 c5 = 1.6 * a;
    cout << c.GetX() << " , " << c.GetY() << '\n';
    cout << c2.GetX() << " , " << c2.GetY() << '\n';
    cout << c3.GetX() << " , " << c3.GetY() << '\n';
    cout << c4 << '\n';
    cout << c5.GetX() << " , " << c5.GetY() << '\n';
}