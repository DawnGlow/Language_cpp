// 8부 : 성능 개선. 시간과 공간 절약.
// 동적 할당 dynamic allocation : 프로그램 실행 중에 변수를 메모리에 할당하는 것

/*
함수의 샐행과는 상관없이 원할 때 공간 사용, 사용X
*/

#include <iostream>
using namespace std;

int main(void) {
    // int a = int(5);
    int *a = new int(5);  // new 는 연산자.
                          /*
                          작동원리:
                          int(5)에서 메모리 상에 인트형을 저장하는 공간이 생겨나 5가 들어감(200번지). new가 이 공간의 주솟값(200번지)을 a에 넘겨줌.
                          */
    cout << a << endl;
    cout << *a << endl;
    *a = 10;
    cout << a << endl;
    cout << *a << endl;

    delete a; // 메모리 해제
}