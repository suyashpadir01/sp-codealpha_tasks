#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check if username already exists
bool userExists(string username)
{
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass)
    {
        if (user == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Registration Function
void registerUser()
{
    string username, password;

    cout << "\n===== User Registration =====\n";

    cout << "Enter Username: ";
    cin >> username;

    // Check for duplicate username
    if (userExists(username))
    {
        cout << "Error: Username already exists!\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    // Basic validation
    if (username.empty() || password.empty())
    {
        cout << "Error: Username and Password cannot be empty!\n";
        return;
    }

    ofstream file("users.txt", ios::app);

    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    file << username << " " << password << endl;
    file.close();

    cout << "Registration Successful!\n";
}

// Login Function
void loginUser()
{
    string username, password;
    string storedUser, storedPass;
    bool found = false;

    cout << "\n===== User Login =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    if (!file)
    {
        cout << "No registered users found!\n";
        return;
    }

    while (file >> storedUser >> storedPass)
    {
        if (storedUser == username && storedPass == password)
        {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Login Successful! Welcome, " << username << "!\n";
    else
        cout << "Invalid Username or Password!\n";
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 3);

    return 0;
}