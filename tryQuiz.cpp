#include <iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
class User {
public:
    std::string userName;
    std::string passWord;
};
class Admin {
public:
    std::vector<User> users;
    User newUser;
    void saveCredentials(const string &uName,const string &Password)
    {
        std::ofstream userFile("user.txt",std::ios::app);
        if(userFile)
        {
            userFile<<"UserName : "<<uName<<" PassWord : "<<Password<<endl;
            userFile.close();
        }else{
            std::cerr<<"Error in opening file."<<endl;
        }
        
    }
    void registerUser()
    {
        
        cout << "Enter a user name:\n";
        cin >> newUser.userName;
       cout << "Enter a password:\n";
        cin >> newUser.passWord;
        

        saveCredentials(newUser.userName,newUser.passWord);
        users.push_back(newUser);
        cout<<"Registration successful!\n";

    }
    bool validCredentials(const string &uName, const string &uPass)
    {
        std::ifstream userFile("user.txt");
        if(!userFile)
        {
            std::cerr<<"File does not existtt!"<<endl;
            return false;
        }
        std::string storedUsername, storedPassword;
        while(userFile>>storedUsername>>storedPassword)
        {
            if(uName==storedUsername && uPass==storedPassword)
            {
                userFile.close();
                return true;
            }
        }
        userFile.close();
        return false;
    }
    bool loginUser()
    {
        
        string uName,uPass; 
      
        cout << "Enter a user name:\n";
        cin >> uName;
        cout << "Enter a password:\n";
        cin >> uPass;

        if(validCredentials(uName,uPass)==true)
        {
            cout<<"Login successful !!!"<<endl;
            return true;
        }else{
        cout << "Invalid credentials , please try again..\n";
        }
        return false;
    }
};
int main()
{
    Admin payal;
    char ch;
    cout<<"1->Register User\n";
    cout<<"2->Login User\n";
    cout<<"3->Skip for now\n";
    do{
    cout<<"Enter your choice..\n";
    cin>>ch;
    
    switch(ch)
    {
        case '1':
            cout<<"Haven't registered yet...!!\n";
             payal.registerUser();

        case '2':
             cout<<"Already have an account..!!\n";
            payal.loginUser();
        default:
            break;

    }
    }while(ch>=3);
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
