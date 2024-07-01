#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, pair<string, string>> users; // Stores username with password and email

void showMenu() {
    cout << "\n1. REGISTER \n2. LOGIN \n3. FORGOT PASSWORD \n4. Exit\n ENTER YOUR CHOICE : ";
}

void showSuccessMessage(const string& message) {
    cout << message << endl;
}

void registerUser() {
    string username, password, email;
    cout << "Enter a username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Enter a password: ";
    getline(cin, password);
    cout << "Enter your email ID: ";
    getline(cin, email);

    if (users.find(username) != users.end()) {
        cout << "Username already exists. Try again." << endl;
    } else {
        users[username] = make_pair(password, email);
        showSuccessMessage("REGISTRATION SUCCESSFULL.........!");
    }
}

void loginUser() {
    string username, password;
    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Enter your password: ";
    getline(cin, password);

    if (users.find(username) != users.end() && users[username].first == password) {
        showSuccessMessage("LOGIN SUCCESSFULL...........!");
    } else {
        cout << "Invalid username or password. Try again." << endl;
    }
}

void forgotPassword() {
    string username, email;
    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Enter your email: ";
    getline(cin, email);

    if (users.find(username) != users.end() && users[username].second == email) {
        cout << "YOUR PASSWORD IS : " << users[username].first << endl<<endl;
        showSuccessMessage("PASSWORD RETRIVAL SUCCESSFULL.........!");
    } else {
        cout << "Username or email not found or do not match. Try again." << endl;
    }
}

int main() {
    cout << ".................WELCOME TO THE LOGIN AND REGISTRATION PAGE.................." << endl;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: 
                registerUser(); 
                break;
            case 2: 
                loginUser(); 
                break;
            case 3: 
                forgotPassword(); 
                break;
            case 4: 
                cout << "Exiting the program." << endl; 
                break;
            default: 
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


