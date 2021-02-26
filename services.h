/*Jack Wanitkun CS202 Program#3
*/
#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

class sms;


class services{
    public:
        services();
        ~services();
        virtual void display_s() const = 0;
        friend ostream &operator<<( ostream &output, const services * data);
        services * get_last();
        services * next;
};


//= copy 
//!= return bool
//== return bool
//+ add-cost
class sms: public services{
    public:
        sms(int sender_phone_a, int reciever_phone_a, char * text_a, int cost_a);
        ~sms();
        virtual void display_s() const;
        //friend ostream &operator<<( ostream &output, const sms * sms_out);
        friend istream &operator>>(istream & input, sms & sms_send);
    private:
        int sender_phone;
        int reciever_phone;
        char * text;
        int cost;
        services * next;
};

class email: public services
{
    public:
        email(char * sender_email, char * reciever_email, char * text);
        ~email();
        //virtual int display_s();
        friend ostream &operator<<( ostream &output, const email & email_out);
        friend istream &operator>>(istream & input, sms & email_in);
    private:
        char * sender_email;
        char * reciever_email;
        char * text;
        services * next;
};

class wk: public services{
    public:
        wk(int push_from, int push_to, int code);
        ~wk();
        //virtual int display_s();
        friend ostream &operator<<( ostream &output, const wk & wk_out);
        //virtual int write_s();
        friend istream &operator>>(istream & input, sms & wk_in);
    private:
        int push_from;
        int push_to;
        int code;
        services * next;
};
