#include <iostream>
using namespace std;

class Time {
   public:
    // Time(5) // 5초
    // Time(5,0) //5분
    // Time(2, 37, 54); // 2시간 37분 54초
    // 생성자 매개변수에 0을 넣으면 헷갈림. 생성자를 매개변수 1개일땐 초로, 2개일땐 분, 초, 3개일때 시간 분 초 로 만들기 위해 각각의 생성자를 선언
    // 겹치는걸 줄이기 위해 생성자 위임 사용
    // 생성자 위임
    Time() : h(0), m(0), s(0) {}
    // 콜론 : 다음 내용을 먼저 실행하고, 괄호 안의 코드를 실행.
    Time(int s_) : Time() {
        s = s_;
    }
    Time(int m_, int s_) : Time(s_) {
        m = m_;
    }
    Time(int h_, int m_, int s_) : Time(m_, s_) {
        h = h_;
    }

   private:
    int h;
    int m;
    int s;
};

int main(void) {
    Time t1;
    Time t2(5);
    Time t3(3, 10);
    Time t4(2, 42, 15);
}