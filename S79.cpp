// 상속이 필요한 이유 2
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
    virtual string GetContent() const { return ""; }

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
    string GetContent() const { return text; }

   private:
    string text;
};

class ImageMessage : public Message {
   public:
    ImageMessage(int sendTime, string sendName, Image *image) : Message(sendTime, sendName), p_image(image) {}

    Image *GetImage() const { return p_image; }
    string GetContent() const { return (string)*p_image; }

   private:
    Image *p_image;
};

void printMessage(Message &m) {  // 레퍼런스도 동적바인딩 가능, 만약 레퍼런스 없이 하면 객체가 복사되어, Message의 GetContent출력하게됨.
    cout << "보낸 시간 : " << m.GetSendTime() << endl;
    cout << "보낸 사람 : " << m.GetSendName() << endl;
    cout << "내용 : " << m.GetContent() << endl;  // 가상함수 동적바인딩.
    cout << endl;
}

/*void printMessage(Message *m) {  // 상속과 오버라이딩을 통해 오버로딩을 하지 않아도 하나의 함수로 다 출력 가능.
    cout << "보낸 시간 : " << m->GetSendTime() << endl;
    cout << "보낸 사람 : " << m->GetSendName() << endl;
    cout << "내용 : " << m->GetContent() << endl;  // 가상함수 동적바인딩.
    cout << endl;
}
*/

/*void printMessage(TextMessage *m) {
    cout << "보낸 시간 : " << m->GetSendTime() << endl;
    cout << "보낸 사람 : " << m->GetSendName() << endl;
    cout << "내용 : " << m->GetText() << endl;
    cout << endl;
}

void printMessage(ImageMessage *m) {
    cout << "보낸 시간 : " << m->GetSendTime() << endl;
    cout << "보낸 사람 : " << m->GetSendName() << endl;
    cout << "내용 : " << (string)*m->GetImage() << endl;
    cout << endl;
}
*/
int main() {
    // 두들 : "안녕"
    // 두들 : "강아지 사진"
    Image *p_dogImage = new Image();

    Message *messages[] = {
        // 포인터배열을 통해 여러 메세지 가리키키
        new TextMessage(10, "두들", "안녕"),
        new TextMessage(11, "두들", "안녕"),
        new TextMessage(12, "두들", "안녕"),
        new ImageMessage(20, "두들", p_dogImage)};

    for (Message *m : messages) {
        printMessage(*m);
    }

    TextMessage *hello = new TextMessage(10, "두들", "안녕");
    ImageMessage *dog = new ImageMessage(20, "두들", p_dogImage);

    printMessage(*hello);
    printMessage(*dog);

    delete hello;
    delete dog;
    delete p_dogImage;

    for (Message *m : messages) {
        delete m;
    }
}
