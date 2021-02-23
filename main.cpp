/*Jack Wanitkun CS202 Program#3
*/
#include<iostream>
#include<cstring> 
#include<cctype>
using namespace std;

int menu();

int main(){
    int answer;
    cout << "Welcome to Jack Wanitkun Program 3" << endl;
    cout << "Choose your options" << endl;

    return 0;
}

int menu(){
    int ans;
    cout << "[1] Create User\n";
    cout << "[2] Update User\n";
    cout << "[3] Update your service\n";
    cout << "[4] Send messages\n";
    cout << "[5] Display all messages\n";

    cout << "[9] Exit\n";
    
    cout << "Your option: ";
    cin >> ans; cin.ignore(100,'\n');
    return ans;
}
