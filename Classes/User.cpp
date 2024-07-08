#include "User.h"
#include <unordered_map>
#include <algorithm>
// Default constructor
User::User() {
    username = "";
    password = "";
    email = "";
}

// Parameterized constructor
User::User(const std::string& username, const std::string& password, const std::string& email) {
    this->username = username;
    this->password = password;
    this->email = email;
}

// Getters
std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

std::string User::getEmail() const {
    return email;
}

const std::unordered_set<User*>& User::getFriends() const {
    return friends;
}

// Friend management
void User::addFriend(User* friendUser) {
    if(friend_requests.find(friendUser)!=friend_requests.end())
    {
        friends.insert(friendUser);
        friendUser->friends.insert(this);
        friend_requests.erase(friendUser);
    }    
}
void User::rejectRequest(User* friendUser)
{
    if(friend_requests.find(friendUser)!=friend_requests.end())
    {
        friend_requests.erase(friendUser);
    }  
}
bool User::isFriendWith(User* user) const {
    return friends.find(user) != friends.end();
}

void User::sendFriendRequest(User* user)
{
    user->friend_requests.insert(this);
}
bool sortByMapValueDesc(const std::pair<User*, int>& a, const std::pair<User*, int>& b) {
    return a.second > b.second; 
}
std::vector<User*> User::suggestFriends()
{
    std::unordered_map<User*,int> suggestions;

    for (auto friendUser : friends) 
    {
        for(auto mutual:friendUser->getFriends())
        {
            if(mutual==this||mutual->isFriendWith(this))
                continue;
            if(suggestions.find(mutual)==suggestions.end())
            {
                suggestions[mutual]=0;
            }
            else
            {
                suggestions.find(mutual)->second++;
            }
        }
    }
    std::vector<std::pair<User*,int>> ans(suggestions.begin(),suggestions.end());
    std::sort(ans.begin(), ans.end(), sortByMapValueDesc);
    std::vector<User*> result;
    for(auto x:ans)
    {
        result.push_back(x.first);
    }
    return result;
}
// For demonstration purposes
void User::printUserInfo() const {
    std::cout << "Username: " << username << std::endl;
    std::cout << "Password: " << password << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Friends: ";
    for (auto friendUser : friends) {
        std::cout << friendUser->getUsername() << " ";
    }
    std::cout << std::endl;
}
