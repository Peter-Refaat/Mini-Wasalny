#include "UserManager.h"
#include <iostream>
 #include <fstream>
 #include <tuple>
 #include <stdexcept>

using namespace std;


// --- User Implementation ---
User::User() {}
User::User(string userName, string password, int id) {
    this->userName = userName;
    this->password = password;
    this->id = id;
    this->g = Graph();
}

string User::getName() const {
    return this->userName;
}

string User::getPassword() const {
    return this->password;
}

int User::getId() const {
    return this->id;
}

void User::setUserName(string userName) {
    this->userName = userName;
}

void User::setPassword(string password) {
    this->password = password;
}

void User::setId(int id) {
    this->id = id;
}

// --- UserManager Implementation ---
int UserManager::uId = 1;
map<string, User> UserManager::namesAndUsers;
User* UserManager::user = new User();

UserManager::UserManager()
{
    // EDIT: Commented out JSON loading
     UserManager::LoadStateFromFile("userdata.json");
}

bool UserManager::AvailableUserName(string &userName)
{
    bool x = (namesAndUsers.find(userName) == namesAndUsers.end()) ? false : true;
    return x;
}

void UserManager::MakeUser(string userName, string password)
{
    User user = User(userName, password, uId);
    uId++;
    namesAndUsers[userName] = user;
}

bool UserManager::CheckCredentials(string userName, string password) {
    if (AvailableUserName(userName) && namesAndUsers[userName].getPassword() == password)
    {
        Login(namesAndUsers[userName]);
        return true;
    }
    return false;
}

void UserManager::Login(User& u) {
    UserManager::user = &u;
}


// USER serialization(already present, now it should work)
void to_json(json & j, const User & u) {
    j = json{
        {"userName", u.getName()},
        {"password", u.getPassword()},
        {"id", u.getId()},
        {"graph", u.g} // This will now use the to_json for Graph
    };
}

void from_json(const json& j, User& u) {
    try {
        u.setUserName(j.at("userName").get<string>());
        u.setPassword(j.at("password").get<string>());
        u.setId(j.at("id").get<int>());
        if (j.contains("graph")) {
            j.at("graph").get_to(u.g); // This will now use the from_json for Graph
        }
        else {
            u.g = Graph();
        }
    }
    catch (json::exception& e) { // Changed from json::exception to json::exception
        cerr << "Error deserializing User: " << e.what() << endl;
        throw;
    }
}


json UserManager::toJson() {
    json j;
    j["uId"] = UserManager::uId;
    j["namesAndUsers"] = UserManager::namesAndUsers;
    return j;
}

void UserManager::fromJson(const json& j) {
    try {
        j.at("uId").get_to(UserManager::uId);
        j.at("namesAndUsers").get_to(UserManager::namesAndUsers);

    }
    catch (json::exception& e) { // Changed from json::exception to json::exception
        cerr << "Error parsing UserManager state from JSON: " << e.what() << endl;
        throw;
    }
}

// Saves the current static state to a file
bool UserManager::SaveStateToFile(const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open file '" << filename << "' for writing." << endl;
        return false;
    }

    try {
        json data = UserManager::toJson(); // Changed from json to json
        outputFile << data.dump(2); // Using 2 spaces for indentation
        outputFile.close();
        return true;
    }
    catch (json::exception& e) { // Changed from json::exception to json::exception
        cerr << "Error: Failed to serialize data to JSON: " << e.what() << endl;
        outputFile.close(); // Close file even on error
        return false;
    }
    catch (const exception& e) { // Catching exception for broader file I/O issues
        cerr << "Error during file writing: " << e.what() << endl;
        outputFile.close();
        return false;
    }
}

// Loads the static state from a file
bool UserManager::LoadStateFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Info: Could not open file '" << filename << "'. Starting with defaults." << endl;
        UserManager::uId = 1; // Ensure defaults
        UserManager::namesAndUsers.clear();
        return true; // Not an error, just means no previous state to load.
    }

    try {
        json data; // Changed from json to json
        inputFile >> data;
        inputFile.close();

        UserManager::fromJson(data);
        return true;

    }
    catch (json::parse_error& e) { // More specific catch for parse errors
        cerr << "Error: Failed to parse JSON from '" << filename << "': " << e.what() << endl;
        inputFile.close();
        UserManager::uId = 1;
        UserManager::namesAndUsers.clear();
        return false; // Indicate that loading failed due to parsing error
    }
    catch (json::exception& e) { // Catch other json exceptions (e.g., type errors)
        cerr << "Error: JSON data processing error from '" << filename << "': " << e.what() << endl;
        inputFile.close();
        UserManager::uId = 1;
        UserManager::namesAndUsers.clear();
        return false; //failure
    }
    catch (const exception& e) { // Catch other exceptions
        cerr << "Error during file reading or processing: " << e.what() << endl;
        inputFile.close();
        UserManager::uId = 1;
        UserManager::namesAndUsers.clear();
        return false; //failure
    }
}
