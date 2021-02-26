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
    cout << "sender: " << sender_phone << endl;
    cout << "Reciever: " << reciever_phone << endl;
    cout << "Msg: " << text << endl;
    cout << "Cost: " << cost << endl;
}


/////////////EMAIL/////////////

email::email(char * sender_email_a, char * reciever_email_a, char * text_a){
    sender_email = new char[strlen(sender_email_a)+1];
    strcpy(sender_email, sender_email_a);
    reciever_email = new char[strlen(reciever_email_a) +1];
    strcpy(reciever_email, reciever_email_a);
    text = new char[strlen(text_a)+1];
    strcpy(text, text_a);
}
