#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<string>
#include<cstring>
#include<map>
#include<ctime>
#include <vector>
#include <algorithm>

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

void cls() {
    system("cls");
}

void LowerCase(std::string& inputString) {
    for (char* ptr = &inputString[0]; *ptr != '\0'; ++ptr) {
        *ptr = std::tolower(*ptr);
    }
}

class User{
    private:
        string UserName, Password; 
        vector<string> transaction_history;
    public:
        User(string UserName, string Password){
            this -> UserName = UserName;
            this -> Password = Password;
        }

        void setUserName(string UserName){
            this -> UserName = UserName;
        }

        void setPassword(string Password){
            this -> Password = Password;
        }

        string getUserName(){
            return UserName;
        }

        string getPassword(){
            return Password;
        }
  
        void addTransaction(const string& transaction) {
            transaction_history.push_back(transaction);
            ofstream file;
            file.open(UserName + "_history.txt", ios::app);
            file << transaction << endl;
            file.close();
        }

        void viewTransactionHistory() {
            ifstream file(UserName + "_history.txt");
            string line;
            if (file.is_open()) {
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            } else {
                cout << "No transaction history found." << endl;
            }
        }
  
};

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

bool Login(){
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
        return 1;
    }
    else{
        cout << "Error! Please check your username and password!\n";
        return 0;
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
        cout <<"Password must contain lower case, upper case, and number!"<<endl;
        cout <<"Password\t\t: ";
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

void Catalogue(){
  // 1. Cheese Cake
  // 2. Tart
  // 3. Black Forest
  // 4. Butter Cake
  // 5. Pound Cake
  // 6. Chiffon Cake
  // 7. Red Velvet Cake
  // 8. Flourless Cake
  // 9. Victoria Sponge Cake
  // 10. Tiramisu
vector<string> cakeName = {"Cheese Cake", "Tart", "Black Forest", "Butter Cake", "Pound Cake", "Chiffon", "Red Velver", "Flourless Cake", "Victoria Sponge Cake", "Tiramisu"};
  
map<int, int> cake;
cake[1] = 40000;
cake[2] = 50000;
cake[3] = 50000;
cake[4] = 45000;
cake[5] = 60000;
cake[6] = 50000;
cake[7] = 65000;
cake[8] = 40000;
cake[9] = 70000;
cake[10] = 50000;

map<string, int> size;
size["s"] = 0;
size["m"] = 7000;
size["l"] = 16000;
size["xl"] = 24000;

vector<string> cakeTopping = {"none", "sprinkle", "darkchoco", "cheese", "strawberry", "whitechoco", "cherry", "almond", "marshmallows", "chocolatechips", "whippedcream", "reaspberries", "hazelnuts"};
map<string, int> topping;
topping["none"] = 0;
topping["sprinkle"] = 4000;
topping["darkchoco"] = 6000;
topping["cheese"] = 5000;
topping["strawberry"] = 7000;
topping["whitechoco"] = 6000;
topping["cherry"] = 5000;
topping["almond"] = 3000;
topping["marshmallows"] = 4000;
topping["chocolatechips"] = 4000;
topping["whippedcream"] = 7000;
topping["raspberries"] = 4000;
topping["hazelnuts"] = 5000;

  
    cout <<"1. " << cakeName.at(0) << endl;
    cout << "A cake with a soft texture and rich cheese flavor, usually made with cream cheese, eggs, and sugar."<<endl;
    cout <<"Price\t: " << cake.at(1) << " IDR" << endl;
    cout <<"Size\t: _________________________________ S/M/L/XL\n"; 
    cout <<"Topping\t: Sprinkle,Cheese,White Choco\n\n\n";

    cout <<"2. " << cakeName.at(1) << endl;
    cout <<"A cake with a crispy pastry base and various fillings such as fruits, custard, or chocolate."<<endl;
    cout <<"Price\t:" << cake.at(2) << " IDR" << endl;
    cout <<"Size_________________________________ S/M/L/XL\n";
    cout <<"Topping\t: Strawberry,Cherry,Raspberries\n\n\n";

    cout <<"3. " << cakeName.at(2) << endl;
    cout <<"A layered cake consisting of chocolate cake layers, whipped cream, and cherries."<<endl;
    cout <<"Price\t:" << cake.at(3) << " IDR" << endl;
    cout <<"Size\t: _________________________________ S/M/L/XL\n";
    cout <<"Topping\t: Dark Choco,Chocolatte Chips,Almond\n\n\n";

    cout <<"4. " << cakeName.at(3) << endl;
    cout <<"A dense and soft cake with a strong buttery flavor."<<endl;
    cout <<"Price\t:" << cake.at(4) << " IDR" << endl;
    cout <<"Size\t: _________________________________ S/M/L/XL\n";
    cout <<"Topping\t: Marshmallows,Whipped Cream,Almond\n\n\n";

    cout <<"5. " << cakeName.at(4) << endl;
    cout << "A dense and soft cake, usually made with equal parts of four main ingredients: flour, butter, eggs, and sugar."<<endl;
    cout <<"Price\t:" << cake.at(5) << " IDR" << endl;
    cout <<"Size\t: _________________________________ S/M/L/XL\n";
    cout <<"Topping\t: chocolateChips,hazelnuts,cherry\n\n\n";

    cout <<"6. " << cakeName.at(5) << endl;
    cout <<"A light and soft cake made from vegetable oil, eggs, sugar, flour, baking powder, and flavoring."<<endl;
    cout <<"Price\t:" << cake.at(6) << " IDR" << endl;
    cout <<"Size\t: _________________________________ S/M/L/XL\n";
    cout <<"Topping\t: strawberry,marshmallows,sprinkle\n\n\n";

    cout <<"7. " << cakeName.at(6) << endl;
    cout <<"A red-colored cake with a light chocolate flavor, usually layered with cream cheese frosting."<<endl;
    cout <<"Price\t:" << cake.at(7) << " IDR" << endl;
    cout <<"Size\t: _________________________________ S/M/L/XL\n";
    cout <<"Topping\t: whippedcream,cheese,raspberries\n\n\n";
    
    cout <<"8. " << cakeName.at(7) << endl;
    cout <<"A dense and soft chocolate cake made without flour, often having an intense chocolate flavor."<<endl;
    cout <<"Price\t:" << cake.at(8) << " IDR" << endl;
    cout <<"Size\t: _________________________________ S/M/L/XL\n";
    cout <<"Topping\t: cherry,darkchoco,sprinkle\n\n\n";

    cout <<"9. " << cakeName.at(8) << endl;
    cout <<"A classic English cake consisting of two sponge cake layers filled with strawberry or raspberry jam and whipped cream."<<endl;
    cout <<"Size\t: _________________________________ S/M/L/XL\n";
    cout <<"Price\t:" << cake.at(9) << " IDR" << endl;
    cout <<"Topping\t: chocolatechips,strawberry,sprinkle\n\n\n";
    
    cout <<"10. " << cakeName.at(9) << endl;
    cout << "An Italian dessert made from layers of ladyfinger biscuits soaked in coffee, mascarpone cream, and dusted with cocoa powder."<<endl;
    cout <<"Price\t:" << cake.at(10) << " IDR" << endl ;
    cout <<"Size\t: _________________________________ S/M/L/XL\n";
    cout <<"Topping\t: whitechoco,whippedcream,almond\n\n\n";
    
    vector<string> cartCake;
    vector<string> cartSize;
    vector<string> cartTopping;
    vector<string> cartTotal;
    int Cake, Total = 0;
    string Fix, Size, Topping;
    Fix = "y";
    while(Fix == "y"){
       cout << "Choose your cake by the number: ";
       cin >> Cake;
       if(Cake > 0 && Cake < 11){
         cartCake.push_back(cakeName.at(Cake));
         Total += cake.at(Cake);
         bool isSize = false;
         while(!isSize){
         cout << "Size\t: ";
         cin >> Size;
         LowerCase(Size);
         	if(Size == "s" ||  Size == "m" || Size == "l" || Size == "xl"){
                isSize = true;
                Total += size.at(Size);
         		cartSize.push_back(Size);
                
                bool isTopping = false;
                while(!isTopping){
         		cout << "Topping\t: ";
         		cin >> Topping;
                LowerCase(Topping);
                   if (std::find(cakeTopping.begin(), cakeTopping.end(), Topping) != cakeTopping.end()){
                       isTopping = true;
                       Total += topping.at(Topping);
         			   cartTopping.push_back(Topping);
                   }
                   else{
                       cout << "Topping is not on the chart.\n";
                   }
                }
         		
         	}
         	else{
           		cout << "Size is not on the chart.\n";
         	}
         }          
       }
       else{
         cout << "Your cake is not in our list.";
       }
       cout <<"Do you want to add another cake ?(Y/N) :";
       cin >> Fix;
       LowerCase(Fix);
    }
}

void TransactionHistory(){
  //view
}

void Homepage(){
  char opt;
  cout << "1. Cake Catlogue\n";
  cout << "2. Transaction history\n";
  cout << "3. Log Out\n";
  cout << "Your Choice\t: ";
  cin >> opt;
  
  if(opt == '1'){
    Catalogue();
  }
  else if(opt == '2'){
   TransactionHistory();
  }
  else if(opt == '3'){
    return ;
  }
}

int main(){
  bool exit = false;
  cls();
  
  do{
    char opt;
        cout << "\n\t\t\t =================================================" << endl;
        cout << "\t\t\t\t %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
        cout << "\n\t\t\t\t       Welcome to Hammer Bakery";
        cout << "\n\t\t\t %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
        cout << "\n\t\t\t =================================================" << endl;
        cout << "\n\n\n\t\t\t\t          )           " << endl;
        cout << "\t\t\t\t         (.)          " << endl;
        cout << "\t\t\t\t         .|.          " << endl;
        cout << "\t\t\t\t         l7J          " << endl;
        cout << "\t\t\t\t         | |          " << endl;
        cout << "\t\t\t\t     .--| |--.      " << endl;
        cout << "\t\t\t\t  .-';  ;`-'& ; `&.   " << endl;
        cout << "\t\t\t\t & &  ;  &   ; ;   \\ " << endl;
        cout << "\t\t\t\t \\      ;    &   &_/ " << endl;
        cout << "\t\t\t\t  F'''---...---'''J   " << endl;
        cout << "\t\t\t\t  | | | | | | | | |   " << endl;
        cout << "\t\t\t\t  J | | | | | | | F   " << endl;
        cout << "\t\t\t\t   `---.|.|.|.---'    " << endl;
        cout << "\n\n\t\t\t\t      1. Login" << endl;
        cout << "\n\t\t\t\t      2. Sign Up" << endl;
        cout << "\n\t\t\t\t      3. Exit" << endl;
        cout << "\n\t\t\t\t      Enter option: ";
    cin >> opt;
    switch(opt){
        case '1':
            if(Login() == 1)Homepage();
            break;
        case '2':
            SignUp();
            if(Login() == 1)Homepage();
            break;
      	case '3':
        	exit = true;
    }
  }while(!exit);
  return 0;
}