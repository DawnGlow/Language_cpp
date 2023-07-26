// 이동 시맨틱(c++ 11)
// 이동 생성자
// 이동 대입 연산자
#include <iostream>
using namespace std;

class String {
   public:
    String() {
        cout << "String() : " << this << '\n';
        strData = NULL;
        len = 0;
    }  // 동적할당 하는바에 포인터에 널값을 대입
    String(const char *str) {
        cout << "String(const char *str) : " << this << '\n';
        // strData = str; --> 얕은 복사
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);  // 깊은 복사
    }

    // 복사 !!!생성자!!!의 작동
    String(const String &rhs) {  // String s2(s1); 사용시 발생하는 일., const string은 값을 수정하지 못하게 하는 역할도 해서 이동시맨틱이 없으면 r-value를 받는 역할도 한다.
        cout << "String(String &rhs) : " << this << '\n';
        // strData = rhs.strData; // 얕은 복사로 인해 메모리 해제 2번
        len = rhs.len;
        alloc(len);                    // 깊은 복사
        strcpy(strData, rhs.strData);  // 깊은 복사
    }

    // 이동 생성자(깊은 복사)
    String(String &&rhs) {  // 임시객체가 res로부터 복사를 받아야 함. res는 l-value이지만, res가 반환되는 동안에는 r-value로 취급됨.
        cout << "String(String&&) : " << this << '\n';
        len = rhs.len;
        strData = rhs.strData;  // 얕은 복사
        rhs.strData = NULL;     // res의 strData
    }

    ~String() {
        cout << "~String() : " << this << endl;
        release();
        strData = NULL;  // delete하고 해제된 메모리에 대한 접근을 막기위한 관습적 방법.
    }

    String &operator=(const String &rhs) {  // 레퍼런스 변수를 사용하지 않으면 rhs(s1)이라는 복사 생성자가 작동해서 복잡해짐.
        cout << "String &operator=(const String &rhs) : " << this << endl;
        if (this != &rhs) {  // 자기 자신을 대입하는 경우를 막기.
            // 만약 strData에 어떤 값이 존재한다면, delete해줘야 함.
            release();
            len = rhs.len;
            alloc(len);
            strcpy(strData, rhs.strData);  // 깊은 복사
        }                                  // 깊은 복사
        return *this;                      // this : 함수가 속한 객체의 주솟값. *this --> 객체
    }

    // 이동 대입 연산자
    String &operator=(String &&rhs) {  // a = 임시객체(r-value) 호출
        cout << "String &operator=(String &&) : " << this << '\n';
        len = rhs.len;
        strData = rhs.strData;
        rhs.strData = NULL;
        return *this;
    }

    char *GetStrData() const {
        return strData;
    }

    int GetLen() const {
        return len;
    }
    void SetStrData(const char *str) {
        cout << "void SetStrData(const char *str) : " << this << ", " << str << '\n';
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }

   private:
    void alloc(int len) {
        strData = new char[len + 1];
        cout << "strData allocated : " << (void *)strData << '\n';
    }
    void release() {
        delete[] strData;
        if (strData) cout << "strData released : " << (void *)strData << '\n';
    }

    char *strData;
    int len;
};

String getName() {
    cout << "===== 2 =====" << '\n';
    String res("Doodle");
    cout << "===== 3 =====" << '\n';
    return res;
}
int f() { return 5; }

int main(void) {
    String a;
    cout << "===== 1 =====" << '\n';
    a = getName();
    /*
    위 과정에서, getName함수는 res를 리턴하는데, res가 소멸하기 때문에 임시 객체에 복사되고, 임시객체에서 a로 복사된다.
    a에 이름을 넣기 위해, res, 임시 객체를 만들어 깊은 복사를 2번이나 하고 2개의 변수가 생성되고 소멸된다.
    --> 너무 비효율적.
    res에서 임시객체로 얕은복사, 임시객체에서 a로 얕은 복사
    얕은 복사를 하되, 한번만 delete하게 만들자. (이동 시멘틱 사용.)
    */

    /*
      임시 객체가 res의 strdata가 가리키는 곳을 가리키고, a의 strdata가 최종적으론 res의 strdata를 가리키자.
    */

    /*
    operator=에 rvalue를 매개변수로 갖는 연산자 오버로딩을 하자.
    */
    String &&r = getName();  // 임시객체 반환, &&r은 r-value 참조자이다.
    cout << "===== 4 =====" << '\n';
}
// r-value(등호에 우변에만 올 수 있는 값)
/*
int a = 5;
a = a --> a는 l-value(오른쪽, 왼쪽 다 올 수 있음)
5 = a 이런건 안됨 --> 5는 r-value

int x = 2
x + 3 = 5; // x + 3 은 r-value --> 연산의 결과값은 r-value이다.
f() = 1; // 리턴값 자체는 임시객체인데 왜 1을 대입을 못하냐? 리턴값은 수정할 수 없는 그냥 r-value이다.
*/