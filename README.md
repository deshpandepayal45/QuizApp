# QuizApp

Detailed requirements for implementing an Quiz Application as a C++ console application:

User Authentication:

Users should be able to log in or register for an account.

classes → User , Admin

User → User’s information

Admin → RegisterUser(), saveUserCredentials(), loginUser(),validateCredentials()

 User credentials (username and password) should be securely stored and validated.

 Quiz Management: 

The application should support multiple quizzes on various topics. Each quiz should have a title, description, and a set of questions.

 Questions can be multiple-choice or true/false.

 Each question should have options and the correct answer(s).

 3.  Quiz Taking:

 Users should be able to select a quiz from the available options.

Once a quiz is selected, the questions should be presented one at a time.

 Users should be able to choose an answer for each question.

 After answering all questions, users should receive feedback on their performance, including their score and the correct answers.

Scoring and Feedback: 

Scores should be calculated based on the number of correct answers.

 Feedback should be provided to users after completing the quiz, indicating the number of correct and incorrect answers.

User Progress Tracking:

 The application should track users' progress, including the quizzes they've taken and their scores.

 Users should be able to view their past quiz attempts and scores.

Administrative Features:

 An administrator should be able to add, edit, or remove quizzes and questions. Administrative privileges should be required to manage quizzes and questions.

User Interface:

 The console interface should be user-friendly and easy to navigate.

 Menus should be provided for user authentication, quiz selection, and quiz-taking. Clear prompts and messages should guide users through the quiz-taking process.

8.Error Handling:

 The application should handle invalid input gracefully and provide appropriate error  messages.

Error handling mechanisms should be in place to prevent crashes or unexpected behavior.

Testing:

Test the application thoroughly to ensure it functions as expected under various scenarios.
