#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Question {
    string statement;
    string choices[4];
    char correct_option;
};

void runQuiz(Question quiz[], int totalQuestions, string subjectName) {
    for (int i = 0; i < totalQuestions; i++) {
        int r = rand() % totalQuestions;
        Question temp = quiz[i];
        quiz [i] = quiz [r];
        quiz [r] = temp;
    }
    int score = 0;
    char userChoice;
    cout << "\n===== " << subjectName << " Quiz =====\n";

    for (int i = 0; i < totalQuestions; i++) {
        cout << "\nQ" << i + 1 << ": " << quiz[i].statement << endl;
        for (int j = 0; j < 4; j++) {
            cout << quiz[i].choices[j] << endl;
        }

        do {
            cout << "Choose option (A-D): ";
            cin >> userChoice;
            userChoice = toupper(userChoice);
        } while (userChoice < 'A' || userChoice > 'D');

        if (userChoice == quiz[i].correct_option) {
            score++;
        }
    }

    cout << endl;
    cout << "Final Score: " << score << " / " << totalQuestions << endl;
    float percentage;

    percentage = (score * 100.0) / totalQuestions;

    cout << "Percentage: " << percentage << "%" << endl;

    if (percentage >= 80) {
        cout << "Excellent!" << endl;
    }
    else if (percentage >= 60) {
        cout << "Good job!" << endl;
    }
    else {
        cout << "Keep practicing!" << endl;
    }
}

int main() {
    srand (time(0));
    string menu_choice;

    Question english[11] = {
        {"Synonym of \"Rapid\"", {"A. Slow", "B. Quick", "C. Heavy", "D. Silent"}, 'B'},
        {"Antonym of \"Generous\"", {"A. Kind", "B. Mean", "C. Polite", "D. Curious"}, 'B'},
        {"Correct punctuation?",
         {"A. apples oranges and bananas",
          "B. apples, oranges and bananas",
          "C. apples, oranges, and bananas",
          "D. apples oranges, bananas"}, 'C'},
        {"Correct spelling", {"A. Recieve", "B. Receive", "C. Receeve", "D. Receve"}, 'B'},
        {"She ___ to school daily", {"A. go", "B. going", "C. goes", "D. gone"}, 'C'},
        {"\"Break the ice\" means?",
         {"A. Start conversation", "B. Freeze water", "C. End talk", "D. Argue"}, 'A'},
        {"Correct sentence?",
         {"A. He don't like tea", "B. She doesn't likes tea",
          "C. She doesn't like tea", "D. He doesn't likes tea"}, 'C'},
        {"Which is a noun?", {"A. Quickly", "B. Happiness", "C. Run", "D. Beautiful"}, 'B'},
        {"Opposite of include", {"A. Exclude", "B. Insert", "C. Add", "D. Join"}, 'A'},
        {"Correct article", {"A. A", "B. An", "C. The", "D. None"}, 'B'},
        {"Good ___ math", {"A. in", "B. at", "C. on", "D. with"}, 'B'}
    };

    Question math[11] = {
        {"5 + 7 =", {"A. 10", "B. 11", "C. 12", "D. 13"}, 'C'},
        {"Square root of 64", {"A. 6", "B. 7", "C. 8", "D. 9"}, 'C'},
        {"15 / 3 =", {"A. 5", "B. 4", "C. 6", "D. 3"}, 'A'},
        {"9 x 6 =", {"A. 52", "B. 54", "C. 56", "D. 60"}, 'B'},
        {"Value of Pi", {"A. 2.14", "B. 3.14", "C. 4.14", "D. 5.14"}, 'B'},
        {"12 - 4 =", {"A. 6", "B. 7", "C. 8", "D. 9"}, 'C'},
        {"8 squared", {"A. 56", "B. 60", "C. 64", "D. 68"}, 'C'},
        {"Next prime after 7", {"A. 9", "B. 10", "C. 11", "D. 12"}, 'C'},
        {"20% of 50", {"A. 8", "B. 9", "C. 10", "D. 11"}, 'C'},
        {"Angles of triangle", {"A. 180", "B. 360", "C. 90", "D. 270"}, 'A'},
        {"Factorial of 5", {"A. 120", "B. 100", "C. 80", "D. 60"}, 'A'}
    };

    Question computer[11] = {
        {"CPU stands for?", {"A. Central Processing Unit", "B. Computer Unit", "C. Control Unit", "D. Core Unit"}, 'A'},
        {"Main OS function?", {"A. Manage resources", "B. Store data", "C. Internet", "D. Games"}, 'A'},
        {"Programming language?", {"A. HTML", "B. CSS", "C. Python", "D. HTTP"}, 'C'},
        {"RAM stands for?", {"A. Random Access Memory", "B. Rapid Memory", "C. Read Memory", "D. Run Memory"}, 'A'},
        {"Input device?", {"A. Monitor", "B. Keyboard", "C. Printer", "D. Speaker"}, 'B'},
        {"Firewall purpose?", {"A. Security", "B. Speed", "C. Storage", "D. Display"}, 'A'},
        {"Output device?", {"A. Keyboard", "B. Monitor", "C. Mouse", "D. Scanner"}, 'B'},
        {"HTML means?", {"A. HyperText Markup Language", "B. HighText", "C. HyperTool", "D. Hyper Machine"}, 'A'},
        {"Windows by?", {"A. Apple", "B. Microsoft", "C. Google", "D. IBM"}, 'B'},
        {"URL is?", {"A. Uniform Resource Locator", "B. Universal Link", "C. Web Link", "D. Net Link"}, 'A'},
        {"SSD stands for?", {"A. Solid State Drive", "B. Serial Drive", "C. Speed Disk", "D. Storage Disk"}, 'A'}
    };

    Question physics[11] = {
        {"Unit of force", {"A. Newton", "B. Joule", "C. Watt", "D. Pascal"}, 'A'},
        {"Speed of light", {"A. 3x10^8", "B. 3x10^6", "C. 3x10^5", "D. 3x10^7"}, 'A'},
        {"Laws of motion by?", {"A. Einstein", "B. Newton", "C. Galileo", "D. Tesla"}, 'B'},
        {"Kinetic energy?", {"A. 1/2mv^2", "B. mv^2", "C. mgh", "D. 2mv"}, 'A'},
        {"SI unit of current", {"A. Volt", "B. Ohm", "C. Ampere", "D. Watt"}, 'C'},
        {"Bending of light", {"A. Reflection", "B. Refraction", "C. Diffraction", "D. Dispersion"}, 'B'},
        {"Gravity on Earth", {"A. 9.8", "B. 8.9", "C. 10", "D. 7.8"}, 'A'},
        {"Negative charge", {"A. Proton", "B. Neutron", "C. Electron", "D. Photon"}, 'C'},
        {"Unit of frequency", {"A. Hertz", "B. Newton", "C. Pascal", "D. Joule"}, 'A'},
        {"Action-reaction law", {"A. First", "B. Second", "C. Third", "D. Energy"}, 'C'},
        {"Do not allow current", {"A. Conductors", "B. Insulators", "C. Semi", "D. Super"}, 'B'}
    };

    do {
        cout << "\n===== Quiz Application =====\n";
        cout << "1. English" << endl;
        cout << "2. Math" << endl;
        cout << "3. Computer" << endl;
        cout << "4. Physics" << endl;
        cout << "5. About" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> menu_choice;

        if (menu_choice == "1") {
            runQuiz(english, 11, "English");
        }
        else if (menu_choice == "2") {
            runQuiz(math, 11, "Math");
        }
        else if (menu_choice == "3") {
            runQuiz(computer, 11, "Computer");
        }
        else if (menu_choice == "4") {
            runQuiz(physics, 11, "Physics");
        }
        else if (menu_choice == "5") {
            cout << "\nThis is a first semester quiz project and my SAP ID is 75531. \n";
            cout << "Concepts used which I have user are arrays, structures, loops, functions." << endl;
            cout << "It was a great opportunity to test myself and learn somme on hand experience doing this Project!" << endl;
        }
        else if (menu_choice == "6") {
            cout << "\nThank you for using the Quiz Application.\n";
        }
        else {
            cout << "Invalid choice." << endl;
        }
    } while (menu_choice != "6");
    return 0;
}