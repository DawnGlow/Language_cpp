// cpp style 함수
// over load : 다중 정의
// 함수 오버로딩 : 함수 매개변수의 형을 분석해서 알맞는 함수를 실행시킴
#include <iostream>
// using namespace std; // std namespace 안에 swap함수가 존재해서 사용 x

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(double &a, double &b) {  // 함수 오버로딩
    double tmp = a;
    a = b;
    b = tmp;
}
// 포인터가 가리키는 값을 변경시키는 함수라서, 포인터 자체를 레퍼런스 변수로 받아야한다.
void swap(int *(&c), int *(&d)) {  // 문법적으로 어떤 느낌이냐면, int형 a와 b를 바꿀때 레퍼런스로 받아서 변경했다. int*형을 바꾸는게 우리 목표이므로, 레퍼런스앞에 *를 추가해주는것.
                                   // 레퍼런스 변수를 사용하지 않으면 a,b변수 값만 바꾸는게 되버림.
    /*
    의미적으론, pa와 pb가 가리키는 변수를 바꾸려면, 즉 pa와 pb의 값을 바꾸는건데, 일단 pa와 pb를 call by reference를 해야함. 아래처럼 이중 포인터를 사용하거나, 레퍼런스변수를 쓴다.
    pa와 pb는 int형 변수의 주소를 담고 있는 변수이므로, int *(&c) = pa; 이런 식으로 받아야한다. 그래서
    (int *(&c), int *(&d))가 되는거다.
    */
    int *tmp = c;  // *c가 아닌 이유는, c는 레퍼런스 변수로 받았기에 c가 pa, pb와 같은 역할을 하고, c의 값이 a의 주소이다.
    c = d;
    d = tmp;
}
// 극심화 버전
void swap(int **c, int **d) {  // 포인터가 가리키는 변수를 바꾸게 하는 방법. c 스타일 이중포인터 사용
    int *tmp = *c;
    *c = *d;
    *d = tmp;
}

void EX1() {
    int a = 20, b = 30;
    double da = 2.22, db = 3.33;
    int *pa = &a;
    int *pb = &b;
    /*
    int *tmp = a;
    a = b;
    b = a; --> 함수로 보내서 변경할때는 call by reference 필요.
    */
    swap(a, b);
    std::cout << "swap result : " << a << " , " << b << std::endl;
    swap(pa, pb);
    std::cout << "swap result : " << *pa << " , " << *pb << std::endl;
    swap(da, db);
    swap(&pa, &pb);
    std::cout << "swap result : " << *pa << " , " << *pb << std::endl;
}

int inventory[64] = {0};
int score;  // 전역변수와 정적변수는 자동으로 0으로 초기화되지만, 지역변수는 쓰레기 값이 들어간다.
/*
void GetItem(int ItemID) {
    inventory[ItemID]++;
}

void GetItem(int ItemID, int cnt) {
    inventory[ItemID] += cnt;
}
*/
void GetItem(int ItemID, int cnt = 1, int sc = 0 /* ,int a */) {  // 값이 들어오지 않으면 1, 0으로 초기화. // 디폴트 값은 오른쪽부터 입력해야함.
    inventory[ItemID] += cnt;
    score += sc;
}

void EX2() {
    GetItem(6, 5);
    GetItem(3, 2);
    GetItem(3);
    GetItem(11, 34, 7000);
    std::cout << score << std::endl;
    for (int i = 0; i < 16; i++) {
        std::cout << inventory[i] << ' ';
    }
    std::cout << std::endl;
}
int main(void) {
    EX2();
}