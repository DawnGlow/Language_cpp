// 예전엔 int arr[1000]; 처럼 넉넉히 할당했음.
#include <iostream>

using namespace std;

int main(void) {
    int *arr;
    int len;
    cout << "동적할당할 배열의 길이 입력: ";
    cin >> len;
    arr = new int[len];  // int(5), int[len] 이런 차이.
    for (int i = 0; i < len; i++) {
        arr[i] = len - i;
    }
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }

    delete[] arr;  // delete arr하면 배열 첫번째 칸만 삭제됨.
}