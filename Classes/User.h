#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

class User {
private:
    std::string username;
    std::string password; // Note: For security reasons, store hashed passwords in a real application
    std::string email;
    std::unordered_set<User*> friends;
    std::unordered_set<User*> friend_requests;
public:
    // Constructors
    User();
    User(const std::string& username, const std::string& password, const std::string& email);
    
    // Getters
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getEmail() const;
    const std::unordered_set<User*>& getFriends() const;

    // Friend management
    void addFriend(User* friendUser);
    void rejectRequest(User* friendUser);
    bool isFriendWith(User* user) const;

    void sendFriendRequest(User* potentialFriend);
    // // Friend suggestion algorithm
    std::vector<User*> suggestFriends();

    // For demonstration purposes
    void printUserInfo() const;
};

#endif // USER_H
