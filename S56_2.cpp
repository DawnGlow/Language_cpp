#include <iostream>
using namespace std;

// 생성자 : 멤버 변수 초기화

// 복소수(real, imag)

class Complex {
   public:
    Complex() {
        real = 0;
        imag = 0;
    }
    Complex(double real_, double imag_) {
        real = real_;
        imag = imag_;
    }
    double GetReal() {
        return real;
    }
    double GetImag() {
        return imag;
    }
    void SetReal(double real_) {
        real = real_;
    }
    void SetImag(double imag_) {
        imag = imag_;
    }

   private:
    double real;
    double imag;
};

int main(void) {
    Complex c1;
    Complex c2 = Complex(2, 3);  // 이 코드랑 아래코드랑 같은 값을 갖는 표현.
    Complex c3(2, 3);
    // Complex c4 = {2, 3};
    // Complex c5 = Complex{2, 3};
    // Complex c6{2, 3};
    cout << "c1 = " << c1.GetReal() << " , " << c1.GetImag() << '\n';
    cout << "c2 = " << c2.GetReal() << " , " << c2.GetImag() << '\n';
    cout << "c3 = " << c3.GetReal() << " , " << c3.GetImag() << '\n';
}