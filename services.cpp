/*Jack Wanitkun CS202 Program#3
*/

#include "services.h"

services::services(){
    next = NULL;
}

services::~services(){
    if(next){
        next = NULL;
    }
}

services * services::get_last(){
    if(this->next){
      return this->next->get_last();
    }
    return this;
};

ostream &operator << (ostream &output, const services * data){
    data->display_s();
    return output;
};

sms::sms(int sender_phone_a, int reciever_phone_a, char * text_a, int cost_a){
    sender_phone = sender_phone_a;
    reciever_phone = reciever_phone_a;
    text = new char[strlen(text_a) +1];
    strcpy(text, text_a);
    cost = cost_a;
    next = NULL;
};

sms::~sms(){
    sender_phone = reciever_phone = cost = 0;
    delete [] text; 
}

void sms::display_s() const {
    cout << "Your sms " <<endl;
    cout << "sender: " << sender_phone << endl;
    cout << "Reciever: " << reciever_phone << endl;
    cout << "Msg: " << text << endl;
    cout << "Cost: " << cost << endl;
}


/////////////EMAIL/////////////

emails::emails(int sender_email_a, int reciever_email_a, char * text_a){
    sender_email = sender_email_a;
    reciever_email = reciever_email_a;
    text = new char[strlen(text_a)+1];
    strcpy(text, text_a);
    next = NULL;
}

emails::~emails(){
    sender_email = reciever_email = 0;
    delete [] text;
}

void emails::display_s() const {
    cout << "Your Email" << endl;
    cout << "Sender: " << sender_email << endl;
    cout << "Reciever: " << reciever_email << endl;
    cout << "Msg: " << text << endl;
}

wk::wk(int push_from_a, int push_to_a, int code_a){
    push_from = push_from_a;
    push_to = push_to_a;
    code = code_a;
    next = NULL;
}

wk::~wk(){
    push_from = push_to = code = 0;
}

void wk::display_s() const{
    cout << "Your Walkie Talkie" << endl;
    cout << "Code Push from: " << push_from << endl;
    cout << "Code Push to: " << push_to << endl;
    cout << "Secret Code: " << code << endl;
}
