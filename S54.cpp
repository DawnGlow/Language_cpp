// struct : 접근제어지시자를 사용하지 않으면, public
// class : 기본이 private.
// class(타입) = 자료저장 + 자료처리 = 변수 + 함수, 특정한 용도를 수행하기 위한 변수와 함수를 모아 둔 틀(자료형)
// 객체(오브젝트) : 틀을 이용하여 찍어낸 개체(변수, 메모리 상의 공간)
#include <iostream>
using namespace std;

// private, protected, public
struct TV {
   private:
    bool powerOn;
    int channel;
    int volume;
    // 함수를 사용하여 0 이상의 수만 사용하거나 최대 최소 범위를 설정하자.

   public:
    void on() {
        powerOn = true;
        cout << "TV를 켰습니다." << endl;
    }
    void off() {
        powerOn = false;
        cout << "TV를 껐습니다. " << endl;
    }
    void setVolume(int vol) {
        if (vol >= 0 && vol <= 100) {
            volume = vol;
            cout << "볼륨 : " << volume << endl;
        }
    }
    void setChannel(int ch) {
        if (ch >= 1 && ch <= 999) {
            channel = ch;
            cout << "채널 : " << channel << endl;
        }
    }
    // 그런데 그냥 ss.volume = 300 해버리면 막을 방법이 없음. --> 지시자를 사용하자.
};

void EX1() {
    TV lg;
    lg.on();
    lg.setChannel(100);
    lg.setVolume(33);
    lg.off();
}

int main(void) {
    EX1();
}