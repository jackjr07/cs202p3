/*Jack Wanitkun CS202 Program#3
*/
#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

//Base class
//Container for user
//I will use BST
class user{
    public: 
        user(const char * username_a, int phone_a, char * email_a);
        ~user();
        void display(user * curr);
        user * update_phone(int phone_a);
        user * update_email(char * email_a);
        //int  remove(user * curr, char * username_r); // Wait for imp
        int add_service();
        int remove_service();
        user * find_user();

        friend ostream &operator << (ostream & output, const user &user_out);
    private:
        user * go_right();
        user * go_left();

        char * username;
        int phone;
        char * email;
        user * left;
        user * right;
};

//This will act like a node
class user_db: public user{
    public:
        user_db(char * username_a, int phone_a, char * email_a);
        ~user_db();

        int create_uid(char * username);
        user_db & user_cmp();
        void display_userdb();
        user * update_udb();
        user * remove_udb();

    private:
        user * root;
};

