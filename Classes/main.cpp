#include <iostream>
#include "User.h"

int main() {
    // Create users
    User alice("Alice", "password1", "alice@example.com");
    User bob("Bob", "password2", "bob@example.com");
    User charlie("Charlie", "password3", "charlie@example.com");
    User david("David", "password4", "david@example.com");

    // Establish friendships
    alice.sendFriendRequest(&bob);
    bob.addFriend(&alice);
    bob.sendFriendRequest(&charlie);
    charlie.addFriend(&bob);
    charlie.sendFriendRequest(&bob);
    bob.addFriend(&charlie);

    // Display user information
    std::cout << "User Information:" << std::endl;
    alice.printUserInfo();
    bob.printUserInfo();
    charlie.printUserInfo();
    david.printUserInfo();

    for(auto x:alice.suggestFriends())
        std::cout<<x->getUsername()<<" ";
    return 0;
}
