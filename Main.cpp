#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<string>
#include<cstring>
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

bool isValidPassword(const char * password){
    int upper = 0;
    int lower = 0;
    int angka = 0;
    int n = strlen(password);
    if(n<3 || n>=50){
        return 0;
    }for (int i = 0;i<n;i++){
        if(islower(password[i])){
            lower++;
        }else if(isupper(password[i])){
            upper++;
        }else if(isdigit(password[i])){
            angka++;
        }
    }
    if(upper == 0 || lower == 0 || angka == 0){
        return 0;
    }
    return 1;
}

void Login(){
    string pass, un, UserName;
    char Password[50];
    bool status = false;

    cout << "LOGIN ^.^\n\n";
    cout << "Username\t: ";
    cin >> UserName;
    cout << "Password\t: ";
    cin >> Password;

    ifstream read("dataAcc.txt");
    while(read >> un >> pass){
        if(un == UserName && pass == Password){
        status = true;
        }
        else status = false;
    }

    if(status == true){ 
        cout << "Welcome " << UserName <<"!\n";
    }
    else{
        cout << "Error! Please check your username and password!\n";
    }   
}

void SignUp(){
    string UserName, ConfirmPassword;
    char Password[50];
    cout << "SIGN UP ^.^\n\n";
    cout << "Username\t\t: ";
    cin >> UserName;
    cout << "Password\t\t: ";
    cin >> Password;

    while(!isValidPassword(Password)){
        cout <<"Password setidaknya harus memiliki 1 huruf besar, 1 huruf kecil dan 1 angka !!"<<endl;
        cout <<"Masukkan Password: ";
        cin >> Password;
    }

    cout << "Confirm Your Password\t: ";
    cin >> ConfirmPassword;

    while(Password != ConfirmPassword){
        cout << "Passwords do not match. Please try again.\n";
        cout << "Confirm Your Password\t: ";
        cin >> ConfirmPassword;
    }

    ofstream file("dataAcc.txt", ios::app);
    file << UserName << " " << Password << endl;
    //system("cls");
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