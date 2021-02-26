/*Jack Wanitkun CS202 Program#3
*/

#include "contact.h"
//base user class
user::user(){
    username = email = NULL;
    uid = phone = 0;
    left = NULL;
    right = NULL;
    head = NULL;
}

user::~user(){
    if(username) delete [] username;
    uid = phone = 0;
    if(email) delete [] email;
    if(left){
        delete left;
        left = NULL;
    }
    if(right){
        delete right;
        right = NULL;
    }
    head = NULL;
}

user * user::create_user(int uid_a, char * username_a, int phone_a, char * email_a){

    this ->uid = uid_a;
    this ->username = new char[strlen(username_a) +1];
    strcpy(this->username, username_a);
    this ->phone = phone_a;
    this -> email = new char[strlen(email_a) +1];
    strcpy(email, email_a);
    this->left = NULL;
    this->right = NULL;
    head = NULL;
    return this;
}

user * user::add_leaf(user * new_user, user * curr){
    //first time curr = root
    if(!new_user && !curr) return 0;

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
}

//Operation overload from^^^^^^^^^^^^
ostream &operator<<( ostream &output, const user * user_out){
   output << "User name: " << user_out->username << "\n" << "User Phone#: " <<user_out->phone << "\n" << "User Email: " << user_out->email << endl;
   return output;
}

//Operation overload = 
user * user::operator=(const user *& user_c){
    username = new char[strlen(user_c->username) +1];
    strcpy(username, user_c->username);
    phone = user_c->phone;
    email = new char[strlen(user_c->email)+1];
    strcpy(email, user_c->email);
    left = user_c->left;
    right = user_c->right;
    head = user_c->head;

    return this;
}

double user::operator+=(const int text_lenght){
    return text_lenght * 2;
}

user * user::update_phone(user * curr, int uid, int phone_a){
  if(!curr) return 0;
  //preorder
  if(curr->uid == uid){
    cout << "Current: \n" << curr << endl;
    curr->phone = phone_a;
    cout << "Update: \n" << curr << endl; // use operator overload
    return curr;
  }
  //inorder
  if(uid < curr->uid){
    return update_phone(curr->left, uid, phone_a);
  }else{
    return update_phone(curr->right, uid, phone_a);
  }
}

user * user::update_email(user * curr, int uid, char * email_a){
    if(curr->uid == uid){
        cout << "Current: \n" << curr << endl;
        delete [] curr->email;
        curr -> email = new char[strlen(email_a)+1];
        strcpy(curr->email, email_a);
        cout << "Updated: \n" << curr << endl;
        return curr;
    }
    if(uid < curr->uid){
      return update_email(curr->left, uid, email_a);
    }else{
      return update_email(curr->right, uid, email_a);
    }
    return this;
}

user *  user::remove(user *& root, int uid){
    if(!root) return 0;
    if(uid < root->uid){
        root->left = remove(root->left, uid);
    }
    else if(uid > root->uid){
        root->right = remove(root->right, uid);
    }
    else{
        if(!root->left){
           root = root->right; 
           return root;
        }
        else if(!root->right){
            root = root->left;
            return root;
        }
    user * temp  = min(root->right);
    root->uid = temp ->uid;
    root->username = new char[strlen(temp->username) +1];
    strcpy(root->username, temp->username);
    root->phone = temp->phone;
    root->email = new char[strlen(temp->email)+1];
    strcpy(root->email, temp->email);
    root->right = remove(root->right, temp->uid);
    }
    return root;
}

user * user::min(user * curr){
    if(curr->left){
        return min(curr->left);
    }
    return curr;
}

user * user::find_user(user * curr, int uid){
    if(curr->uid == uid){
        return curr;
    }
    if(uid < curr->uid){
        curr->left = find_user(curr->left, uid);
    }else{
        curr->right = find_user(curr->right, uid);
    }
}

int user::service(int ans){
    //[1] sms, [2] email, [3] wk
    if(ans == 1){
        int send_to;
        char msg[200];
        double cost = 1;
        cout << "What number you want to send sms to: " << endl;
        cin >> send_to; cin.ignore(100,'\n');
        cout << "What message you want to sent to: " << endl;
        cin.get(msg,200); cin.ignore(100, '\n');
        int text_len = strlen(msg)+1;
        cout << text_len << endl;
        cost+=text_len;

        //Add at head
        if(!this->head){
          this->head = new sms(this->phone, send_to, msg, cost);
          cout << this->head << endl;
          return 11;
        }
        if(this->head){
            services * temp = this->head;
            temp->get_last();
            temp->next = new sms(this->phone, send_to, msg, cost);
            cout << temp->next << endl;
            return 12;
        }
    }
    if(ans == 2){
        int send_to;
        char msg[200];
        cout << "What number you want to send email to: ";
        cin >> send_to; cin.ignore(100,'\n');
        cout << "What is your email text: " ;
        cin.get(msg,200); cin.ignore(100, '\n');
        if(!this->head){
            this->head = new emails(this->phone, send_to, msg);
            cout << this->head << endl;
            return 21;
        }
        if(this->head){
            services * temp = this->head;
            temp->get_last();
            temp->next = new emails(this->phone, send_to, msg);
            cout << temp->next << endl;
            return 22;
        }
    }
    if(ans == 3){
        int push_to;
        int code;
        cout << "What number you want to send a secret code to: ";
        cin >> push_to; cin.ignore(100,'\n');
        cout << "What is the secret code[int]: ";
        cin >> code; cin.ignore(100,'\n');
        if(!this->head){
          this->head = new wk(this->phone, push_to, code);
          cout << this->head << endl;
          return 31;
        }
        if(this->head){
          services * temp = this->head;
          temp->get_last();
          temp->next = new wk(this->phone, push_to, code);
          cout << temp->next << endl;;
          return 32;
        }
    }
}

int user::display_all_s(user * curr){
        if(!curr) return 0;
            return display_all_s(curr->head);
}

int user::display_all_s(services * curr){
      if(!curr) return 0;
      cout << curr << endl;
      return display_all_s(curr->next);
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
    int uid = (phone * 3) % 1000;
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
    int  uid;
    cout << "What Phone number you want to remove: ";
    cin >> uid; cin.ignore(100,'\n');
    uid = create_uid(uid);
    this->remove(root, uid);
    return this;
}

int user_db::add_service(){
    int ans;
    int uid;
    cout << "What is your current phone number: ";
    cin >> uid; cin.ignore(100,'\n');
    uid = create_uid(uid);
    cout << "What kind of service you want to linked to this phone number?\n";
    cout << "[1] sms\n [2] Email\n [3] Walkie Talkie\n Answer: ";
    cin >> ans; cin.ignore(100,'\n');
    user * curr = find_user(root, uid);        
    curr->service(ans);
    return 11;
}

void user_db::display_services(){
    int phone;
    int uid;
    cout << "What is your current phone number: ";
    cin >> uid; cin.ignore(100,'\n');
    uid = create_uid(uid);
    user * curr = find_user(root, uid);
    curr->display_all_s(curr);
}



/*
user(...):username(username_a)
 
 */
