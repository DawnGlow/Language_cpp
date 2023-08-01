// 부모 클래스 포인터가 자식 클래스를 가리킬 수 있음.
// Upcasting : 자식 클래스 포인터 -> 부모 클래스 포인터(묵시적)
/*
Derived *d = new Derived;
Base *b = d;
*/
#include <iostream>
using namespace std;
class Animal {
   public:
    float xpos = 1;
    float ypos = 2;
};

class FlyingAnimal : public Animal {
   public:
    float zpos = 3;
};

void printAnimals(Animal **a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "(" << a[i]->xpos << ", " << a[i]->ypos << ")" << endl;
    }
}

int main(void) {
    // FlyingAnimal *a = new FlyingAnimal[10];
    // 해결코드
    Animal **a = new Animal *[10];  // 포인터배열, Flying Animal을 가리키는 포인터들의 배열을 만들자.(배열에는 flying animal의 주소를 가지고 있음.)
    for (int i = 0; i < 10; i++) {
        a[i] = new FlyingAnimal;
    }
    printAnimals(a, 10);  // Animal 클래스는 4바이트짜리 2개지만, FlyingAnimal은 3개라서, for문을 돌면서 2칸씩 주소가 증가해버려서 z가 다음 배열의 x가 되버림.
    // 부모 포인터가 자식 포인터를 가리키면 배열에서 문제가 발생함.
    for (int i = 0; i < 10; i++) {
        delete a[i];
    }
    delete[] a;
}