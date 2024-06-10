#include<iostream>
#include <conio.h>
#include <windows.h>
#include<fstream>
#include<string>
using namespace std;

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 29
#define WIN_WIDTH 70

#define BLACK 0
#define BLUE 1
#define CYAN 3
#define RED 4
#define PINK 13
#define YELLOW 14

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(Console, CursorPosition);
}

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

    if(status == true){
        cout << "Welcome " << UserName <<"!\n";
    }
    else{
        cout << "This Credentials do not found !"<<"!\n";
    }
    
}

void SignUp(){
    string UserName, Password,ConfirmPassword;

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