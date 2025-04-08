# CSC455 Term Project

## General Idea
The task is to create a PLMS, which we can accomplish with C++. We will create a CLI tool that allows for creating, removing, modifying, and storing users and roles. The result should allow the user to accomplish basic user-management and role-management tasks.

### Organization
- main.cpp: This is the main C++ file for the project. This will import the rest of the code, and will handle reading and saving data.
- userman.cpp: This handles the basic functionality for user-management.
- userreg.cpp: This handles registering users.
- roleman.cpp: This handles role management of users.
- useradd.cpp: Adding users, according to the format provided by the assignment.
- courseadd.cpp: Adding courses, according to the format provided by the assignment.
- roleenf.cpp: Role enforcement, preventing roles from acting beyond their intended scope.


## TODO:
- [ ] Create main.cpp
- [ ] Create userman.cpp
- [ ] Create userreg.cpp
- [ ] Create roleman.cpp
- [ ] Create useradd.cpp
- [ ] Create courseadd.cpp
- [ ] Create roleenf.cpp

### Extra Stuff:
- [ ] Create a Makefile
- [ ] Create some basic tests
- [ ] Add a "help" command