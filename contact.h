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
        user();
        ~user();
        user * create_user(int uid, char * username_a, int phone_a, char * email_a);
        user * add_leaf(user * new_user, user * curr);
        void display(user * curr);
        user * update_phone(int phone_a);
        user * update_email(char * email_a);
        //int  remove(user * curr, char * username_r); // Wait for imp
        int add_service();
        int remove_service();

        friend ostream &operator << (ostream & output, const user &user_out);
        int uid;

    private:
        char * username;
        int phone;
        char * email;
        user * left;
        user * right;
};

//This will act like a node
class user_db: public user{
    public:
        user_db();
        ~user_db();

        int create_uid(int phone);
        user * add_user(char * name, int phone,char * email);
        user * user_cmp();
        void display_userdb();
        user * update_udb();
        user * remove_udb();

    private:
        user * root;
};

