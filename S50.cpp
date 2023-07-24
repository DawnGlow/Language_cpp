#include <iostream>
using namespace std;

void EX1(void) {
    // int a = 10;  // 초기화, a = 10 : 대입, int a : 선언
    int a(10);  // c++ 스타일 초기화
    // a(5)는 불가능(함수인지, 변수인지 알 수 없다)
    int b(a);
    cout << "a = " << a << " b = " << b << endl;
}

// 범위 기반 for문
void EX2(void) {
    int arr[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    // 배열의 각 칸을 변수처럼 사용하자.
    for (int n : arr) {  // arr안에 있는 모든 값을 n으로 놓고 쓰겠다.
        cout << n << endl;
        n++;  // arr을 루프마다 다시 받아서 의미가 없음.
    }
}

void EX3(void) {
    int arr[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    // 배열의 각 칸을 변수처럼 사용하자.
    for (int &n : arr) {  // arr안에 있는 모든 값을 n으로 놓고 쓰겠다.
        cout << n << endl;
        n++;  // 레퍼런스 변수를 사용하여 배열에 있는 값이 증가한다.
    }
}

// 레퍼런스 변수
void EX4(void) {
    // r-value : 수정할 수 없는 값(숫자 : 3)
    int a(5);
    int &r1 = a;
    // int &r2= 3; --> 불가능
    // int &r3 = a * a; ---> 불가능
    int &&r2 = 3;
    int &&r3 = a * a;  // 함수의 return값도 수정할 수 없는 값이므로 참조 가능.
    cout << a << endl;
    cout << r1 << endl;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    EX3();
}