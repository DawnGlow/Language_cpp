#include <iostream>

using namespace std;

class Ice {
   public:
    Ice() { cout << "Ice()" << endl; }
    ~Ice() { cout << "~Ice()" << endl; }
};

class Pat {
   public:
    Pat() { cout << "Pat()" << endl; }
    ~Pat() { cout << "~Pat()" << endl; }
};

class Bingsoo {
   public:
    Bingsoo() {
        cout << "Bingsoo()" << endl;
        ice = new Ice;
    }
    virtual ~Bingsoo() {
        cout << "~Bingsoo()" << endl;
        delete ice;
    }

   private:
    Ice *ice;  // ice 객체가 아니기 때문에 ice 생성자가 호출되지 않음. ice = new Ice에서 호출됨.
};

class PatBingsoo : public Bingsoo {
   public:
    PatBingsoo() {
        cout << "PatBingsoo()" << endl;
        pat = new Pat;
    }
    ~PatBingsoo() {
        cout << "~PatBingsoo()" << endl;
        delete pat;  // 멤버 변수가 소멸하기 전에 소멸자를 호출해야 함. Patbingsoo -> pat
    }

   private:
    Pat *pat;
};

int main() {
    Bingsoo *p = new PatBingsoo;
    delete p;  // 변수 타입이 빙수인데 빙수를 가리키는지, 팥빙수를 가리키는지 몰라서 정적바인딩이 일어남. 그래서 Bingsoo의 소멸자만 호출됨.
    // virtual Bingsoo로 하면, Patbingsoo의 소멸자가 호출된다.
    /*
    ice
    bingsoo
    pat
    patbingsoo
    ~patbingsoo
    ~pat
    ~bingsoo
    ~ice

    bingsoo
    ice
    patbingsoo
    pat
    ~patbingsoo
    ~pat
    ~bingsoo
    ~ice
    소멸자 : 일반적으론 생성자 역순(클래스 내부에서는 상황에 따라 다름.)
    클래스를 만들기 위해 멤버들이 필요함 --> 멤버를 먼저 생성한 후  클래스 생성자 호출
    */
}