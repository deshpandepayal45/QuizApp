#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include<vector>
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
class Quiz
{
    public:
        std::string topic,description;
        std:: vector<std::string> questions;
        Quiz(const std::string &topic,const std::string &description)
        {
            this->topic=topic;
            this->description=description;
        }
        void addQuestion(const std::string &newQuestion )
        {
            questions.push_back(newQuestion);
        }
        void saveToFile(std::ofstream& outFile) const {
        outFile << topic << "\n" << description<<"\n";
        for (const std::string& question : questions) {
            outFile << "\n" << question;
        }
        outFile << std::endl;
        }
};
class Admin{
    public:
    void addQuiz(std::vector<Quiz> &quizzes,const std::string &topic,const std::string &description)
    {
        quizzes.push_back(Quiz(topic,description));
        std::cout<<"New Quiz on "<<topic<<" added successfully.\n";
    }
    void editQuiz( Quiz &quiz,const std::string &newQuestion)
    {
        quiz.addQuestion(newQuestion);
         std::cout<<"Question added successfully!"<<endl;
    }    
};
class Menu{
         private:
         Admin payal;
            public:

            void display(vector<Quiz> &quiz)
            {
                 char ch='1';
                while(ch=='1') {
                cout<<"1->contniue adding quizzes to console\n";
                cout<<"2->Exit\n";
   
                cout<<"Enter your choice\n";
                cin>>ch;
                if(ch!='1')
                {
                    break;
                }
                std::string topicName,description;
                cout<<"Enter the topic name:\n";
                getline(cin,topicName);
                cin.ignore();
                cout<<"Enter topic description:\n";
                 getline(cin,description);
                payal.addQuiz(quiz,topicName,description);
                cout<<"Enter 10 Questions regarding "<<topicName<<" \n";
 
                for(int qNo=0;qNo<10;++qNo)
                {   
                    string question;
                    getline(cin,question);
                    payal.editQuiz(quiz.back(),question);
                }
                }
            
            }

            void saveToFiles(vector<Quiz> &quiz)
            {
                std::ofstream outFile("quizzes.txt",std::ios::app);
                if (outFile.is_open()) {
                for (const Quiz& quiz : quiz) {
                quiz.saveToFile(outFile);
                 }
                    outFile.close();
                std::cout << "Quizzes saved to quizzes.txt" << std::endl;
                } else {
                 std::cerr << "Error opening file for writing." << std::endl;
                    }
            }
};
int main() {
    UserManager userManager("users.txt");
    AdminManager adminmanager("Admins.txt");

    Admin payal;
    // Quiz quizes("math");
    vector<Quiz> quiz;

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

            if (adminmanager.loginAdmin(adminEmail,adminPassword)) 
            {
                   std::cout << "Login successful!" << std::endl;
               } else {
                 std::cout << "Invalid credentials." << std::endl;
               }

               Menu menu;
               menu.display(quiz);
               menu.saveToFiles(quiz);
        }
        else
        {
            cout<<"Want to access Quiz without an account!!!!";
            cout<<"Let's get started";
        }
    

    return 0;
}
