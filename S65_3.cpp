#include <iostream>
using namespace std;

class Vector2 {
   public:
    Vector2() : x(0), y(0) {
        cout << this << " : Vector2()" << '\n';
    }
    Vector2(const float x, const float y) : x(x), y(y) {
        cout << this << " : Vector2(float x, float y)" << '\n';
    }

    ~Vector2() {
        cout << this << " : ~Vector2()" << '\n';
    }

    float GetX() const {
        return x;
    }
    float GetY() const {
        return y;
    }

   private:
    float x;
    float y;
};

int main(void) {
    Vector2 s1 = Vector2();
    Vector2 s2 = Vector2(3, 2);
    Vector2 *d1 = new Vector2();
    Vector2 *d2 = new Vector2(3, 2);

    cout << "(" << d1->GetX() << ", " << d1->GetY() << ")" << '\n';
    cout << "(" << d2->GetX() << ", " << d2->GetY() << ")" << '\n';
    delete d1;
    delete d2;
    // 동적할당된 변수들이 먼저 소멸되고, s1, s2가 그 다음 소멸된다.
}