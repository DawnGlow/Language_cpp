#include <iostream>
using namespace std;

class Weapon {
   public:
    Weapon(int power) : power(power) {
        cout << "Weapon(int)" << endl;
    }

    virtual void Use() {  // virtual : 가상
        cout << "Weapon::Use()" << endl;
    }

   protected:
    int power;
};

class Sword : public Weapon {
   public:
    Sword(int power) : Weapon(power) {
        cout << "Sword(int)" << endl;
    }
    void Use() {
        cout << "Sword::Use()" << endl;
        Swing();
    }

   private:
    void Swing() {
        cout << "Swing sword" << endl;
    }
};

class Magic : public Weapon {
   public:
    Magic(int power, int manaCost) : Weapon(power), manaCost(manaCost) {
        cout << "Magic(int, int)" << endl;
    }

    void Use() {
        cout << "Magic::Use()" << endl;
        Cast();
    }

   private:
    void Cast() {
        cout << "Cast magic." << endl;
    }
    int manaCost;
};
int main(void) {
    Sword mySword(10);
    Magic myMagic(15, 7);
    mySword.Use();
    myMagic.Use();

    Weapon *currentWeapon;

    currentWeapon = &mySword;
    currentWeapon->Use();  // 원래는 정적바인딩에 의해 부모의 Use가 호출되지만, virtual 키워드를 부모의 Use에 붙히면, 가상함수가 되어, mySword.Use()가 호출
    /*
    일단 부모 클래스의 Use의 선언부로 가는데, virtual 키워드가 있어서 실행될지 안될지 모르니 컴파일할때 결정하지 않음.
    프로그램이 실행될 때는 currentWepon이 mySword를 가리킴을 확인할 수 있음으로 mySword의 Use를 실행함.
    */
    currentWeapon = &myMagic;
    currentWeapon->Use();
}