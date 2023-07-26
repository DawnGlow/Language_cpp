// 상속을 사용한 코드
// 장점 : 공통적인 내용을 상속해서 부모 코드만을 수정해 자식 코드도 수정할 수 있다.
#include <iostream>
#include <string>

using namespace std;

class Message {
   public:
    Message(int sendTime, string sendName) {
        this->sendTime = sendTime;  // this->sendTime을 안쓰고 sendTime을 쓰면 매개변수 값을 매개변수에 넣는 꼴.
        this->sendName = sendName;
    }

    int GetSendTime() const { return sendTime; }
    string GetSendName() const { return sendName; }

   private:
    int sendTime;
    string sendName;
};

class Image {
   public:
    operator string() {
        return "사진";
    }
};
class TextMessage : public Message {
   public:
    TextMessage(int sendTime, string sendName, string text) : Message(sendTime, sendName) {
        this->text = text;
    }

    string GetText() const { return text; }

   private:
    string text;
};

class ImageMessage : public Message {
   public:
    ImageMessage(int sendTime, string sendName, Image *image) : Message(sendTime, sendName) {
        this->image = image;
    }

    Image *GetImage() const { return image; }

   private:
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
