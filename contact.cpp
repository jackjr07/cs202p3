/*Jack Wanitkun CS202 Program#3
*/

#include "contact.h"
//base user class
user::user(){
    username = email = NULL;
    uid = phone = 0;
};
user::~user(){
    if(username) delete [] username;
    uid = phone = 0;
    if(email) delete [] email;
};
user * user::create_user(int uid_a, char * username_a, int phone_a, char * email_a){

    this ->uid = uid_a;
    this ->username = new char[strlen(username_a) +1];
    strcpy(this->username, username_a);
    this ->phone = phone_a;
    this -> email = new char[strlen(email_a) +1];
    strcpy(email, email_a);

    /*user * add = new user();
    add->uid = uid_a;
    add->username = new char[strlen(username_a) +1];
    strcpy(username, username_a);
    add->phone = phone_a;
    add->email = new char[strlen(email_a)+1];
    strcpy(email, email_a);
    */

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
    else if(new_user->uid >= curr->uid){
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
    if(curr->right){
        return display(curr->right);
    }
};

//Operation overload from^^^^^^^^^^^^
ostream &operator<<( ostream &output, const user * user_out){
   output << "User name: " << user_out->username << "\n" << "User Phone#: " <<user_out->phone << "\n" << "User Email: " << user_out->email << endl;
   return output;
};


user * user::update_phone(user * curr, int uid, int phone_a){
  if(!curr) return 0;
  if(curr->uid == uid){
    cout << "Current: \n" << curr << endl;
    curr->phone = phone_a;
    cout << "Update: \n" << curr << endl; // use operator overload
    return curr;
  }
  //Inorder
  if(uid < curr->uid){
    return update_phone(curr->left, uid, phone_a);
  }else{
    return update_phone(curr->right, uid, phone_a);
  }
};

user * user::update_email(user * curr, int uid, char * email_a){
    if(curr->uid == uid){
    delete [] curr->email;
    curr -> email = new char[strlen(email_a)+1];
    strcpy(curr->email, email_a);
    }
    if(uid < curr->uid){
      return update_email(curr->left, uid, email_a);
    }else{
      return update_email(curr->right, uid, email_a);
    }
    return this;
};

/////////////////////database///////////////////////////
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
        cout << "Start that root" << endl;
        root = new user();
        root->create_user(uid, name, phone, email);
        return root;
    }
    cout << "Passed to leaf" << endl;
    user * new_user = new user();
    new_user->create_user(uid, name, phone, email);
    new_user->add_leaf(new_user, root);
    return new_user;
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
    int uid;
    cout << "What is the current phone number that you want to update: ";
    cin >> uid; cin.ignore(100, '\n');
    uid = create_uid(uid);
    cout << "Do you want to update [1]Phone number or [2] Email: ";
    cin >> ans; cin.ignore(100, '\n');
    if(ans == 1){
        int phone;
        cout << "New Phone#: ";
        cin >> phone; cin.ignore(100,'\n');
        this->update_phone(root, uid, phone);
    }
    if(ans == 2){
        char email[30];
        cout << "New email: ";
        cin.get(email, 30); cin.ignore(100,'\n');
        this->update_email(root, uid, email);
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
