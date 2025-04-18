// Header file for user-management
// Daniel Teberian

#ifndef USERMAN_H
#define USERMAN_H

// Imports
#include <string>
#include <vector>


// Forward declaration
class User;

// Structs/classes for user-management
enum UserRole
{
	ADMINISTRATOR,
	INSTRUCTOR,
	STUDENT
};


// User struct
struct User
{
	// User ID
	int id;
	// Username
	std::string username;
	// First name
	std::string fname;
	// Surname
	std::string sname;
	// DOB
	std::string dob;

	UserRole role;


	// Constructor
	User(int id, const std::string& username, const std::string& fname, const std::string& sname, const std::string& dob, UserRole role) : id(id), username(username), fname(fname), sname(sname), dob(dob), role(role)
	{

	}
};


// Vector that is used to store users and their information
extern std::vector<User> users;


// Function declarations

/*
	Role: Register user
	Parameter: None
	Returns: Void
*/
void ureg();

/*
	Role: View existing users
	Parameter: None
	Returns: Void
*/
void uview();


#endif
