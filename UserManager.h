#pragma once
#include "Graph.h"
#include <map>
#include <string>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class User
{
private:
    string userName, password;
    int id;
public:
    User();
    User(string, string, int);
    Graph g;
    string getName() const;
    string getPassword() const;
    int getId() const;
    void setUserName(string);
    void setPassword(string);
    void setId(int);
    // getters and setters for graph
};

class UserManager
{
public:
    static User* user;
    static int uId;
    UserManager();
    static map<string, User> namesAndUsers;
    static void MakeUser(string, string);
    static bool AvailableUserName(string&);
    static bool CheckCredentials(string, string);
    static void Login(User&);

    static bool SaveStateToFile(const string& filename);
    static bool LoadStateFromFile(const string& filename);  
private:
     static json toJson();
     static void fromJson(const json& j);
};

 void to_json(json& j, const User& u);
 void from_json(const json& j, User& u);
