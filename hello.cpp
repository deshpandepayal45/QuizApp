#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
class AdminManager{
    private:
        std::map<std::string, std::string> adminCredentials;

    public:
        AdminManager(const std::string & filename)
        {
            std::ifstream file(filename);
            if(file.is_open()){
                std::string adminEmail,password;
                while(file >> adminEmail>>password)
                {
                    adminCredentials[adminEmail]=password;
                }
                file.close();
            }
        }
         void saveAdminCredentials(const std::string &fileName)
        {
            std::ofstream file(fileName);
            if(file.is_open())
            {
                for(const auto &entry:adminCredentials)
                {
                    file<<entry.first<<" "<<entry.second<<std::endl;
                    
                }file.close();
               
            } else{
                    std::cerr<<"Error in opening file\n";
                }
        }
        bool registerAdmin(const std::string &adminEmail, const std::string &adminPassword)
        {
            if(adminCredentials.count(adminEmail) && adminCredentials.count(adminPassword))
            {
                std::cout<<"admin already exist!!";
                return false;
            }
            adminCredentials[adminEmail]=adminPassword;
            saveAdminCredentials("admin.txt");
            return true;
        }
         bool loginAdmin(const std::string& adminName, const std::string& adminPassword) {
        return adminCredentials.count(adminName) && adminCredentials[adminName] == adminPassword;
    }
    bool isValidateEmail(const std::string &adminEmail)
    {
        if (!std::isalpha(adminEmail[0])) {
        return false;
        }
        size_t atPos = adminEmail.find('@');
        size_t dotPos = adminEmail.find('.', atPos);

        std::string domain = adminEmail.substr(atPos + 1);
        return (domain == "esko.com");
    }
       
};
class UserManager {
private:
    std::map<std::string, std::string> userCredentials;

public:
    UserManager(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string username, password;
            while (file >> username >> password) {
                userCredentials[username] = password;
            }
            file.close();
        }
    }

    bool registerUser(const std::string& username, const std::string& password) {
        if (userCredentials.count(username)&&userCredentials.count(password)) {
            std::cout << "User already exists." << std::endl;
            return false;
        }
        userCredentials[username] = password;
        saveUserCredentials("users.txt");
        return true;
    }

    bool loginUser(const std::string& username, const std::string& password) {
        return userCredentials.count(username) && userCredentials[username] == password;
    }

    void saveUserCredentials(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& entry : userCredentials) {
                file << entry.first << " " << entry.second << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Error saving user credentials." << std::endl;
        }
    }
};
using namespace std;
int main() {
    UserManager userManager("users.txt");
    AdminManager adminmanager("Admins.txt");

    std::string userName,password;
    std::string adminEmail,adminPassword;
    char ch;

    cout<<"1->Register User\n";
    cout<<"2->Login User\n"; 
    cout<<"3->Register Admin\n";
    cout<<"4->Login Admin\n"; 
    cout<<"3->Exit\n";

         cout<<"enter your choice\n";
         cin>>ch;
        
        if(ch=='1')
        {
            std::cout<<"enter username:\n";
            std::cin>>userName;

             std::cout<<"enter password\n";
             std::cin>>password;
            if(!userManager.registerUser(userName,password))
            {
                main();
            }
        }else if(ch=='2')
        {
            std::cout<<"enter username:\n";
            std::cin>>userName;

             std::cout<<"enter password\n";
             std::cin>>password;

             if (userManager.loginUser(userName,password)) {
                   std::cout << "Login successful!" << std::endl;
               } else {
                 std::cout << "Invalid credentials." << std::endl;
               }
        }else if(ch=='3')
        {
            std::cout<<"enter the specific email for accessing Admin panel:\n";
            std::cin>>adminEmail;

             if(!adminmanager.isValidateEmail(adminEmail))
            {
                cout<<"this is not a specific mail, so u can not access admin section\n";
                main();
            }

            std::cout<<"enter password\n";
            std::cin>>adminPassword;

           

             if(!adminmanager.registerAdmin(adminEmail,adminPassword))
            {
                cout<<"User already exist!!\n";
                main();
            }

        }
        else if(ch=='4')
        {
            std::cout<<"enter the specific email for accessing Admin panel:\n";
            std::cin>>adminEmail;

             if(!adminmanager.isValidateEmail(adminEmail))
            {
                cout<<"this is not a specific mail, so u can not access admin section\n";
                main();
            }

            std::cout<<"enter password\n";
            std::cin>>adminPassword;

            if (adminmanager.loginAdmin(adminEmail,adminPassword)) {
                   std::cout << "Login successful!" << std::endl;
               } else {
                 std::cout << "Invalid credentials." << std::endl;
               }
        }
        else{
            cout<<"Want to access Quiz without an account!!!!";
            cout<<"Let's get started";
        }
    

    return 0;
}
