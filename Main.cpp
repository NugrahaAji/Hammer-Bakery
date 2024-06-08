#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void Login(){
    string pass, un, Password, UserName;
    bool status = false;

    cout << "LOGIN ^.^\n\n";
    cout << "Username\t: ";
    cin >> UserName;
    cout << "Password\t: ";
    cin >> Password;

    ifstream read(UserName + ".txt");
    getline(read, un);
    getline(read, pass);

    if(un == UserName && pass == Password){
        status = true;
    }
    else status = false;

    cout << "Welcome " << UserName <<"!\n";
}

void SignUp(){
    string UserName, Password,ConfirmPassword;
    bool status = false;

    cout << "SIGN UP ^.^\n\n";
    cout << "Username\t\t: ";
    cin >> UserName;
    cout << "Password\t\t: ";
    cin >> Password;
    cout << "Confirm Your Password\t: ";
    cin >> ConfirmPassword;

    while(Password != ConfirmPassword){
        cout << "Passwords do not match. Please try again.\n";
        cout << "Confirm Your Password\t: ";
        cin >> ConfirmPassword;
    }
    
    ofstream file;
    file.open(UserName + ".txt");
    file << UserName << endl << Password;
    file.close();
    cout << "\nSigning Up succesfull\n";

}

int main(){
    char opt;
    cout << "1. Login\n2. Sign Up\n";
    cin >> opt;
    switch(opt){
        case '1':
            Login();
            break;
        case '2':
            SignUp();
            Login();
            break;
    }
}