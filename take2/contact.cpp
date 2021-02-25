/*Jack Wanitkun CS202 Program#3
 * Updated from BST to LLL
*/

#include "contact.h"
//base user class
user::user(){
    username = email = NULL;
    uid = phone = 0;
    next = NULL;
}

user::~user(){
    if(username) delete [] username;
    uid = phone = 0;
    if(email) delete [] email;
    if(next){
        user * temp = new user();
        delete next;
        next = temp;
    }
}

user * user::create_user(int uid_a, char * username_a, int phone_a, char * email_a){

    this ->uid = uid_a;
    this ->username = new char[strlen(username_a) +1];
    strcpy(this->username, username_a);
    this ->phone = phone_a;
    this -> email = new char[strlen(email_a) +1];
    strcpy(email, email_a);
    this ->next = NULL;
    return this;
}

user * user::add_leaf(user * new_user, user * curr){
    if(!curr && !new_user) return 0;
    if(curr->next){
        return add_leaf(new_user, curr->next);
    }
    curr->next = new user();
    curr->next = new_user;

    return curr->next;
}

int user::display(user * curr){
    if(!curr)return 0;
    cout << curr << endl;
    return display(curr->next);
}

//Operation overload from^^^^^^^^^^^^
ostream &operator<<( ostream &output, const user * user_out){
   output << "User name: " << user_out->username << "\n" << "User Phone#: " <<user_out->phone << "\n" << "User Email: " << user_out->email << endl;
   return output;
}

user * user::operator=(const user& user_c){
    username = new char[strlen(user_c.username) +1];
    phone = user_c.phone;
    email = new char[strlen(user_c.email)+1];
    next = NULL;
    return this;
};


user * user::update_phone(user * curr, int uid, int phone_a){
  if(!curr) return 0;

  if(uid != curr->uid){
        return update_phone(curr->next, uid, phone_a);
  }
    cout << "Current: \n" << curr << endl;
    curr->phone = phone_a;
    cout << "Update: \n" << curr << endl; // use operator overload
    return curr;
}

user * user::update_email(user * curr, int uid, char * email_a){
    if(!curr) return 0;
    if(uid != curr->uid){
        return update_email(curr->next, uid, email_a);
    }
    cout << "Current: \n" << curr << endl;
    delete [] curr->email;
    curr -> email = new char[strlen(email_a)+1];
    strcpy(curr->email, email_a);
    cout << "Update: \n" << curr << endl; //use operator overload
    return curr;
}

int user::remove(user * curr, int uid){
    cout << curr << endl;
   if(!curr) return 0;
   if(curr->uid != uid){
        return remove(curr->next, uid);
   }
   if(curr->uid == uid){
       if(!curr->next){
            user * temp = NULL;
            delete curr;
            curr = temp;
            return 2;
       }else{
           user * temp = curr->next;
           delete curr;
           curr = temp;
            return 3;
       }
    }
   return 1;
}

/////////////////////database///////////////////////////
user_db::user_db(){
    root = NULL;
}

user_db::~user_db(){
    if(root){
        delete root;
    }
}

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
}

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
}

user * user_db::remove_udb(){
    int uid_r;
    cout << "What phone number account you want to remove: ";
    cin >> uid_r; cin.ignore(100, '\n');
    uid_r = create_uid(uid_r);
    this->remove(root, uid_r);
    return this;
}






/*
user(...):username(username_a)
 
 */
