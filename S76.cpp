// 상속이 필요한 이유
// 메신저 앱 : 텍스트, 이미지

#include <iostream>
#include <string>

using namespace std;

class Image {
   public:
    operator string() {
        return "사진";
    }
};
class TextMessage {
   public:
    TextMessage(int sendTime, string sendName, string text) {
        this->sendTime = sendTime;  // this->sendTime을 안쓰고 sendTime을 쓰면 매개변수 값을 매개변수에 넣는 꼴.
        this->sendName = sendName;
        this->text = text;
    }

    int GetSendTime() const { return sendTime; }
    string GetSendName() const { return sendName; }
    string GetText() const { return text; }

   private:
    int sendTime;
    string sendName;
    string text;
};

class ImageMessage {
   public:
    ImageMessage(int sendTime, string sendName, Image *image) {
        this->sendTime = sendTime;
        this->sendName = sendName;
        this->image = image;
    }

    int GetSendTime() const { return sendTime; }
    string GetSendName() const { return sendName; }
    Image *GetImage() const { return image; }

   private:
    int sendTime;
    string sendName;
    Image *image;
};

int main() {
    // 두들 : "안녕"
    // 두들 : "강아지 사진"
    Image *p_dogImage = new Image();
    TextMessage *hello = new TextMessage(10, "두들", "안녕");
    ImageMessage *dog = new ImageMessage(20, "두들", p_dogImage);

    cout << "보낸 시간 : " << hello->GetSendTime() << endl;
    cout << "보낸 사람 : " << hello->GetSendName() << endl;
    cout << "내용 : " << hello->GetText() << endl;
    cout << endl;

    cout << "보낸 시간 : " << dog->GetSendTime() << endl;
    cout << "보낸 사람 : " << dog->GetSendName() << endl;
    cout << "내용 : " << (string)*dog->GetImage() << endl;
    cout << endl;

    delete hello;
    delete dog;
    delete p_dogImage;
}
