// const의 사용
// 1. 매개변수의 상수화 (모든 함수에서)
// 2. 메서드의 상수화 (멤버 메서드)
// ==> 실수 방지

#include <iostream>
using namespace std;

class Account {
   public:
    Account() : money(0) {}
    Account(int money) : money(money) {}
    void Deposit(const int d) {  // d는 절대 변하면 안되기 때문에 const를 사용한다.
        // d = money;               // 실수
        money += d;
        cout << d << " 원을 예금했다" << '\n';
    }
    void Draw(int d) {
        if (money >= d) {
            money -= d;
            cout << d << " 원을 인출했다!!!" << '\n';
        }
    }
    // const int ViewMoney()는 반환형이 const int라는 의미. 헷갈리지 말기. 메서드 상수화에서는 괄호뒤에 const를 붙히자,
    int ViewMoney() const {  // 멤버변수를 리턴해주는 함수인데 갑자기 값을 건드리는 실수를 해버릴 수 있어서, 이를 막기 위해 메서더의 상수화를 사용
        // money++;             // 실수(버그) --> const를 사용해서 에러 호출
        return money;
    }

   private:
    int money;
};

int main(void) {
    Account doodle(200);
    doodle.Deposit(100);
    doodle.Draw(20);
    cout << doodle.ViewMoney() << '\n';
}