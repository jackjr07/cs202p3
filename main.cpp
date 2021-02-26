/*Jack Wanitkun CS202 Program#3
*/
#include "contact.h"

using namespace std;

int menu();
int create_user(user_db & db_obj);

int main(){
    int ans = 0;
    user_db db_obj;
    cout << "Welcome to Jack Wanitkun Program 3" << endl;
    cout << "Choose your options" << endl;
    do{
        ans = menu();
        if(ans == 1){
            create_user(db_obj);
        }
        if(ans == 2){
            db_obj.display_userdb();
        }
        if(ans == 3){
            db_obj.update_udb();
        }
        if(ans == 4){
            db_obj.remove_udb();
        }
    }while(ans != 9);
    return 0;
}

int menu(){
    int ans;
    cout << "[1] Create User\n";
    cout << "[2] Display all user\n";
    cout << "[3] Update User\n";
    cout << "[4] Remove User\n";

    cout << "[3] Update your service\n";
    cout << "[4] Send messages\n";
    cout << "[5] Display all messages\n";

    cout << "[9] Exit\n";
    
    cout << "Your option: ";
    cin >> ans; cin.ignore(100,'\n');
    return ans;
}

int create_user(user_db & db_obj){
    char username[40];
    int phone;
    char email[40];
    cout << "Your name: ";
    cin.get(username, 40); cin.ignore(100,'\n');
    cout << "Your phone number: ";
    cin >> phone; cin.ignore(100,'\n');
    cout << "Your email: ";
    cin.get(email,40); cin.ignore(100,'\n');
    db_obj.add_user(username, phone, email);
    //db_obj.display_userdb();
};
