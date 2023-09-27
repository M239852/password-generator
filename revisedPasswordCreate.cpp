#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

string getPassword(int passLength) { 
    string Password = "";
    string characters = "aquickbrownfoxjumpsoverthelazydogAQUICKBROWNFOXJUMPSOVERTHELAZYDOG0123654789!@#$%";
    int charSize = characters.size();
    srand(time(0));
    int randomIndex;
    for (int i = 0; i < passLength; i++) {
        randomIndex = rand() % charSize;
        Password = Password + characters[randomIndex];
    }
    return Password;
}

int main() {
    int passLength;
    cout << "Enter the desired length of the password: " << endl;
    cin >> passLength;
    string newpass = getPassword(passLength);
    cout << "Generated Password: " << newpass << endl;

    char userInput;
    cout << "Check strength of the old password? Y | N" << endl;
    cin >> userInput;
    if (userInput == 'Y' || userInput == 'y') {
        string oldPass;
        cout << "Enter your old password: ";
        cin >> oldPass;
        
        bool containsSpecialChar = false;
        string specialChars = "!@#$%";
        for (int i = 0; i < specialChars.size(); i++) {
            if (oldPass.find(specialChars[i]) != string::npos) {
                containsSpecialChar = true;
                break;
            }
        }

        if (containsSpecialChar) {
            cout << "Your password is: Strong" << endl;
        } else {
            cout << "Your password is: Weak" << endl;
            cout << "To make it stronger, you should try adding special characters!" << endl;

        }
    } else if (userInput == 'N' || userInput == 'n') {
        cout << "Have a good day!";
    }

    return 0;
}
