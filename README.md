# nectify-social-networking
A Social Networking console application for connecting with friends and sharing posts. The application is built on C++, and has features like user registration, friend requests, and friend suggestions. The application demonstrates the use of Object-Oriented Programming (OOP) and Data Structures and Algorithms (DSA).

## Features

- **User Management**: Create and manage users with details like username, password, and email.
- **Friend Management**: Add and manage friendships between users.
- **Friend Suggestions**: Suggest friends based on mutual connections using graph traversal algorithms.

## Classes

### User

Represents a user in the social network with attributes like username, password, and email. It also manages the user's friend list.

### FriendNetwork

Manages the entire network of users and their connections. It provides methods to add users, manage friendships, and suggest friends.

### Post

Represents a post made by a user, including the content, timestamp, and user who made the post.

## Getting Started

### Prerequisites

- C++ Compiler (e.g., g++)
- Visual Studio Code (optional)

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/vanditshah111/nectify-social-networking.git
   cd social-networking-app
2. Ensure you have a C++ compiler installed. If not, install g++.
3. Open the project in Visual Studio Code.

### Building and Running
* Open the project in Visual Studio Code.

* Configure the build tasks:

* Go to Terminal > Configure Tasks > Create tasks.json file from template.

* Add the following configuration to tasks.json:
  ```
  {
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "src/Main.cpp",
                "src/User.cpp",
                "src/Post.cpp",
                "-o",
                "social_networking_app"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"],
            "detail": "Generated task by User"
        }
      ]
  } ```
* Go to Terminal > Run Build Task... or press Ctrl+Shift+B.
* Open the integrated terminal in VS Code and run:
  ```
  ./social_networking_app
  ```
## License
This project is licensed under the MIT License
