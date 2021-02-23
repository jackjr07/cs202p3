/*Jack Wanitkun CS202 Program#3
*/

#include "contact.h"
//base user class
user::user(const char * username_a, int phone_a, char * email_a){
    username = new char[strlen(username_a) +1];
    strcpy(username, username_a);
    phone = phone_a;
    email = new char[strlen(email_a) + 1];
    strcpy(email, email_a);
};
user::~user(){
    if(username) delete [] username;
    phone = 0;
    if(email) delete [] email;
};

//Use inorder
void user::display(user * curr){
    if(curr->left){
        return display(curr->left);
    }
    cout << curr << endl;
    /*
    cout << "User name: " << username << endl;
    cout << "User Phone phone: " << phone << endl;
    cout << "User Email: " << email << endl;
    */
    if(curr->right){
        return display(curr->right);
    }
};

//Operation overload from^^^^^^^^^^^^
ostream &operator<<( ostream &output, const user &user_out){
   output << "User name: " << user_out.username << "\n" << "User Phone#: " <<user_out.phone << "\n" << "User Email: " << user_out.email << endl;
   return output;
};


user * user::update_phone(int phone_a){
    phone = phone_a;
    return this;
};

user * user::update_email(char * email_a){
    delete email;
    email = new char[strlen(email_a)+1];
    strcpy(email, email_a);
    return this;
};

//database
user_db::user_db(char * username_a, int phone_a, char * email_a):user(username_a, phone_a, email_a){
};

user_db::~user_db(){
    if(root){
        delete root;
    }
};

int user_db::create_uid(char * username){
    if(!username) return 0;
    int uid = atoi(username);
    return uid;
}

void user_db::display_userdb(){
    if(!root){
        cout << "Nothing in the database" << endl;
    }
    root->display(root);
};

user * user_db::update_udb(){
    int ans;
    cout << "Do you want to update [1]Phone number or [2] Email: ";
    cin >> ans;
    if(ans == 1){
        int phone;
        cout << "New Phone#: ";
        cin >> phone; cin.ignore(100,'\n');
        this->update_phone(phone);
    }
    if(ans == 2){
        char email[30];
        cout << "New email: ";
        cin.get(email, 30); cin.ignore(100,'\n');
        this->update_email(email);
    }
    return this;
};

user * user_db::remove_udb(){
    char username[30];
    cout << "What username you want to remove: ";
    cin.get(username, 30); cin.ignore(100,'\n');
    //this->remove(root, username);
    return this;
}
