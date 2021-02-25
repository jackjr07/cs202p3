/*Jack Wanitkun CS202 Program#3
*/

#include "services.h"

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

ostream &operator << (ostream &output, const sms & sms_out){
    output << "Sender: " << sms_out.sender_phone << endl;
    output << "Reciever: " << sms_out.reciever_phone << endl;
    output << "Text: " << sms_out.text << endl;
    return output;
};

/////////////EMAIL/////////////

email::email(char * sender_email_a, char * reciever_email_a, char * text_a){
    sender_email = new char[strlen(sender_email_a)+1];
    strcpy(sender_email, sender_email_a);
    reciever_email = new char[strlen(reciever_email_a) +1];
    strcpy(reciever_email, reciever_email_a);
    text = new char[strlen(text_a)+1];
    strcpy(text, text_a);
}
