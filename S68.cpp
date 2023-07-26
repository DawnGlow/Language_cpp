// string class를 구현하는 코드
#include <iostream>

using namespace std;

class String {
   public:
    String() {
        cout << "String() 생성자 호출" << '\n';
        strData = NULL;
        len = 0;
    }  // 동적할당 하는바에 포인터에 널값을 대입
    String(const char *str) {
        cout << "String(const char *str) 생성자 호출" << '\n';
        // strData = str; --> 얕은 복사
        len = strlen(str);
        strData = new char[len + 1];                          // 널문자가 있기 때문에 len + 1
        cout << "strData 할당: " << (void *)strData << endl;  // strData는 char 포인터인지(주소출력), 문자열을 가리키는건지(문자열출력) cout을 보고 컴파일러가 문자열로 인식
        // 따라서 (void*)strData 사용
        /*
        void *ptr = strData;
        *ptr = 'A'; 는 불가능. void*는 주솟값만 가지고 있기때문에, char형인지 int형인지 알 수 없기 때문.
        */
        strcpy(strData, str);  // 깊은 복사
    }

    // 복사 !!!생성자!!!의 작동
    String(const String &rhs) {  // String s2(s1); 사용시 발생하는 일.
        cout << "String(String &rhs) 생성자 호출" << '\n';
        // strData = rhs.strData; // 얕은 복사로 인해 메모리 해제 2번
        strData = new char[rhs.len + 1];  // len의 크기를 모르기 때문에 len + 1 로 문자열 크기를 정할 수 없다. rhs.len을 사용하자.
        cout << "strData할당: " << (void *)strData << endl;
        strcpy(strData, rhs.strData);  // 깊은 복사
        len = rhs.len;                 // 깊은 복사
    }

    String &operator=(const String &rhs) {  // 레퍼런스 변수를 사용하지 않으면 rhs(s1)이라는 복사 생성자가 작동해서 복잡해짐.
        if (this != &rhs) {                 // 자기 자신을 대입하는 경우를 막기.
            // 만약 strData에 어떤 값이 존재한다면, delete해줘야 함.
            delete[] strData;  // strData가 NULL이면 어차피 작동 X
            strData = new char[rhs.len + 1];
            cout << "strData할당: " << (void *)strData << endl;
            strcpy(strData, rhs.strData);  // 깊은 복사
            len = rhs.len;
        }              // 깊은 복사
        return *this;  // this : 함수가 속한 객체의 주솟값. *this --> 객체
    }
    ~String() {
        cout << "~String() 소멸자 호출" << endl;
        delete[] strData;
        cout << "strData 해제됨: " << (void *)strData << endl;
        strData = NULL;  // delete하고 해제된 메모리에 대한 접근을 막기위한 관습적 방법.
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

int main() {
    String s1("안녕");
    String s2(s1);  // 복사 생성자
    // 기본적으로 소멸은 선언의 역순
    String s3;

    /*
    int a = 5;
    int b;
    int c = b = a; --> b에 a의 값을 대입하고 5를 return해서 c = 5가 된다.
    */
    // s3.operator=(s1)
    s3 = s1;  // 연산자 오버로딩 사용
    String s4("Hello");
    s4 = s4;  // hello 문자열을 해제하면 len만 남아서 strdata 할당이 되서 쓰레기값만 들어있는데, 쓰레기값이 strcpy를 만나 쓰레기값이 저장됨.
    cout << s1.GetStrData() << '\n';
    cout << s2.GetStrData() << '\n';
    cout << s3.GetStrData() << '\n';
    cout << s4.GetStrData() << '\n';  // 예외처리 안하면 쓰레기값 출력
}