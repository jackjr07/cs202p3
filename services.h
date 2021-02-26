/*Jack Wanitkun CS202 Program#3
*/
#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

class sms;
class email;
class wk;


class services{
    public:
        services();
        ~services();
        virtual void display_s() const = 0;
        friend ostream &operator<<( ostream &output, const services * data);
        services * get_last();
        services * next;
};


class sms: public services{
    public:
        sms(int sender_phone_a, int reciever_phone_a, char * text_a, int cost_a);
        ~sms();
        virtual void display_s() const;
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
        email(int sender_email, int reciever_email, char * text);
        ~email();
        virtual void display_s() const ;
    private:
        int sender_email;
        int reciever_email;
        char * text;
        services * next;
};

class wk: public services{
    public:
        wk(int push_from, int push_to, int code);
        ~wk();
        virtual void display_s();
        friend istream &operator>>(istream & input, sms & wk_in);
    private:
        int push_from;
        int push_to;
        int code;
        services * next;
};
