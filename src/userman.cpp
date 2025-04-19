// The user-management component of the LMS
    // Daniel Teberian

    #include "userman.h"
    #include <iostream>
    #include <string>
    #include <regex>
    #include <vector>

    // Assuming you have a global vector of Users
    std::vector<User> users;

    // Function for creating a new user
    void ureg() {
        std::cout << "\nREGISTER USER\n";

        // Strings for the user struct
        std::string username, fname, sname, dob;

        // Role selection
        int rolesel;
        UserRole role;

        // Ask for the role
        std::cout << "ROLE (0: ADMINISTRATOR, 1: INSTRUCTOR, 2: STUDENT): ";
        // Store selection in the rolesel variable
        std::cin >> rolesel;

        if (rolesel == 0) {
            role = ADMINISTRATOR;
        } else if (rolesel == 1) {
            role = INSTRUCTOR;
        } else if (rolesel == 2) {
            role = STUDENT;
        } else {
            std::cout << "[ERR] INVALID ROLE SELECTION. DEFAULTING TO THE STUDENT ROLE.\n";
            role = STUDENT;
        }

        // Whether a username is valid or not. Defaults to false
        bool valid_username = false;

        do {
            // Ask for the username
            std::cout << "USERNAME: ";
            // Store user-input in the username variable
            std::cin >> username;

            // Validate the username
            if (validate_username(username, role) && unique_username(username)) {
                valid_username = true;
            } else {
                std::cout << "[ERR] INVALID USERNAME.\n";
            }
        } while (!valid_username);

        // Whether or not provided first name is valid. Defaults to false
        bool valid_fname = false;

        do {
            // Ask for the first name
            std::cout << "FIRST NAME: ";
            // Store user-input in the fname variable
            std::cin >> fname;

            if (validate_name(fname)) {
                valid_fname = true;
            } else {
                std::cout << "[ERR] INVALID NAME.\n";
            }
        } while (!valid_fname);

        // Whether or not provided surname is valid. Defaults to false
        bool valid_sname = false;

        do {
            // Ask for the surname
            std::cout << "SURNAME: ";
            // Store user-input in the sname variable
            std::cin >> sname;

            if (validate_name(sname)) {
                valid_sname = true;
            } else {
                std::cout << "[ERR] INVALID NAME.\n";
            }
        } while (!valid_sname);

        // Whether or not DOB is valid. Defaults to false
        bool valid_dob = false;

        do {
            // Ask for the DOB
            std::cout << "DOB (MM/DD/YYYY): ";
            // Store input in dob variable
            std::cin >> dob;

            if (validate_dob(dob)) {
                valid_dob = true;
            } else {
                std::cout << "[ERR] INVALID DOB.\n";
            }
        } while (!valid_dob);

        // Create a new user
        User newuser(users.size() + 1, username, fname, sname, dob, role);
        users.push_back(newuser);

        // Success message
        std::cout << "USER REGISTERED.\n";
    }


// Create a new admin
void newadmin()
{
	


    // Role: Validates the username
    // Parameters: A specified username, the user's role
    // Returns: True if valid, false if invalid
    bool validate_username(const std::string& username, UserRole role) {
        std::string prefix;

        if (role == ADMINISTRATOR) {
            prefix = "A";
        } else if (role == INSTRUCTOR) {
            prefix = "I";
        } else {
            prefix = "S";
        }

        std::regex username_format("^" + prefix + "[1-9]\\d{0,4}$");

        return (username.length() >= 10) && std::regex_match(username, username_format);
    }

    // Role: Validates the two provided names
    // Parameters: A specified name
    // Returns: True if valid, false if invalid
    bool validate_name(const std::string& name) {
        return (name.length() <= 12) && std::regex_match(name, std::regex("^[A-Za-z]+$"));
    }

    // Role: Validates the provided DOB
    // Parameters: A specified DOB
    // Returns: True if valid, false if invalid
    bool validate_dob(const std::string& dob) {
        // Provides the accepted format for a DOB
        std::regex datefmt("^\\d{2}/\\d{2}/\\d{4}$");

        if (!std::regex_match(dob, datefmt)) {
            return false;
        }

        int month = std::stoi(dob.substr(0, 2));
        int day = std::stoi(dob.substr(3, 2));
        int year = std::stoi(dob.substr(6, 4));

        if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1900 || year > 2025) {
            return false;
        }

        // Return true if all checks pass
        return true;
    }

    // Role: Checks if the username is unique
    // Parameters: A specified username
    // Returns: True if valid, false if invalid
    bool unique_username(const std::string& username) {
        for (const auto& user : users) {
            if (user.username == username) {
                return false;
            }
        }

        return true;
    }
