// 접근 제어
// private protected public
// public :    외부 접근 O 자식클래스 o
// protected : 외부 접근 x 자식클래스 o
// private :   외부 접근 x 자식클래스x

#include <iostream>
using namespace std;

class Base {
   public:
    int bPublic;

   protected:
    int bProtected;

   private:
    int bPrivate;
};

class Derived : public Base {  // Protected Base의 경우 Protected 보다 더 공개된 멤버들을 Protected 공개수준으로 낮춤.
                               // Private Based의 경우 public이랑 protected 가 privated 공개수준으로 바뀜.
   public:
    int dPublic;
    void DFunc() {
        bPublic = 1;
        bProtected = 2;
        // bPrivate X
        dPublic = 4;
        dPrivate = 5;
    }

   private:
    int dPrivate;
};

int main(void) {
    Base b;
    Derived d;

    b.bPublic = 1;
    // b.bProtected X
    d.bPublic = 1;
    // d.bPrivate, d.bProtected x
    d.dPublic = 1;
}