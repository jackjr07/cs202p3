/*Jack Wanitkun CS202 Program#3
*/

#include "contact.h"
//base user class
user::user(){
    username = email = NULL;
    phone = 0;
};
user::~user(){
    if(username) delete [] username;
    phone = 0;
    if(email) delete [] email;
};
user * user::create_user(int uid_a, char * username_a, int phone_a, char * email_a){
    this ->uid = uid_a;
    this ->username = new char[strlen(username_a) +1];
    strcpy(this->username, username_a);
    this ->phone = phone_a;
    this -> email = new char[strlen(email_a) +1];
    strcpy(email, email_a);
    return this;
}

user * user::add_leaf(user * new_user, user * curr){
    //first time curr = root
    if(new_user->uid < curr->uid){
        if(!curr->left){
            curr->left = new_user;
            return curr->left;
        }
        return add_leaf(new_user, curr->left);
    }
    if(new_user->uid >= curr->uid){
        if(!curr->right){
            curr->right = new_user;
            return curr->right;
        }
        return add_leaf(new_user, curr->right);
    }
}

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
user_db::user_db(){
    root = NULL;
};

user_db::~user_db(){
    if(root){
        delete root;
    }
};

user * user_db::add_user(char * name, int phone, char * email){
    int uid = create_uid(phone);

    if(!root){
        root->create_user(uid, name, phone, email);
        return root;
    }
    else{user * new_user;
    new_user->create_user(uid, name, phone, email);
    new_user->add_leaf(new_user, root);
    return new_user;
    }
}

int user_db::create_uid(int phone){
    int uid = (phone * 7) % 1000;
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






/*
user(...):username(username_a)
 
 */
