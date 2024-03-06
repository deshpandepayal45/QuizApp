#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class Quiz{
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
int main()
{
    Admin payal;
    // Quiz quizes("math");
    vector<Quiz> quiz;

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
    cin>>topicName;
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

    return 0;
}