/*Jack Wanitkun CS202 Program#3
 * This is the second one from the feedback on the partial credit. 
 * Since I don't need to worrie about ADT, I will use just LLL, so it would be much easier
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
        //copy constructor
        //user(const user & user_obj);

        user * create_user(int uid, char * username_a, int phone_a, char * email_a);
        user * add_leaf(user * new_user, user * curr);
        int display(user * curr);
        user * update_phone(user * curr, int uid, int phone_a);
        user * update_email(user * curr, int uid, char * email_a);
        int  remove(user * curr, int uid);
        int add_service();
        int remove_service();

        //overwrite assignment for copy constructor
        user * operator=(const user& user_c);
        //overwrite cout 
        friend ostream &operator << (ostream & output, const user * user_out);
        int uid;

    private:
        char * username;
        int phone;
        char * email;
        user * next;
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

