// 깊은 복사와 얕은 복사
/*
얕은 복사
int *a = new int(5);
int *b = new int(3);
a = b;
delete a;
delete b; // 문제점1. 두번 지움
// 문제점2. 3이 담겨있는 공간이 안지워짐.
이러한 걸 얕은 복사라 한다.(참조만 복사)
*/

/*
깊은 복사
int *a = new int(5);
int *b = new int(3);
*a = *b; // 깊은 복사
delete a;
delete b;
이렇게 값을 복사하는 걸 깊은 복사라고 한다.
*/

/*
얕은 복사의 대표적 예시
class Copy {
private:
  int *a;
};
Copy A, B;
여기에서
B = A;를 하게 되면...
B.a = A.a가 되어 얕은 복사가 일어나게 된다.
*/

// string class를 구현하는 코드
#include <iostream>

using namespace std;

class String {
   public:
    String() { strData = NULL; }  // 동적할당 하는바에 포인터에 널값을 대입
    String(const char *str) {
        // strData = str; --> 얕은 복사
        len = strlen(str);
        strData = new char[len + 1];  // 널문자가 있기 때문에 len + 1
        strcpy(strData, str);         // 깊은 복사
    }
    ~String() {
        delete[] strData;
    }

    char *GetStrData() const {
        return strData;
    }

    int GetLen() const {
        return len;
    }

   private:
    char *strData;
    int len;
};