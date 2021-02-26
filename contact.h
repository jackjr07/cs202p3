/*Jack Wanitkun CS202 Program#3
*/
#include "services.h"

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
        user * update_phone(user * curr, int uid, int phone_a);
        user * update_email(user * curr, int uid, char * email_a);
        //int  remove(user * curr, char * username_r); // Wait for imp
        user *  remove(user *& root, int uid);
        user * min(user * curr); //inorder successor
        user * find_user(user * curr, int uid);
        int service(int ans);
        int remove_service();
        int display_all_s(user * curr);

        //overwrite assignment for copy constructor
        user * operator=(const user *& user_c);
        //overwrite cout 
        friend ostream &operator << (ostream & output, const user * user_out);

        int uid;
    private:
        int display_all_s(services * curr);
        char * username;
        int phone;
        char * email;
        user * left;
        user * right;
        services * head;
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
        int add_service();
        void display_services();

    private:
        user * root;
};

