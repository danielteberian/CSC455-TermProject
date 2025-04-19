// Rewritten user management for the LMS
// Daniel Teberian


/* IMPORTS */
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "userman.h"
#include "fn.h"



// Create an administrator
void add_admin()
{
	std::ofstream file("data/administrators.txt", std::ios::app);
	std::string id;
	std::string username;
	std::string fname;
	std::string sname;
	std::string dob;


	// Ask for the admin's ID
	std::cout << "ADMIN ID: ";
	// Store user input in the id variable
	std::cin >> username;

	// Validates username
	if (!valid_admin_username(username))
	{
		// Error
		std::cout << "[ERR] INVALID ADMIN USERNAME.\n";
		return;
	}

	// Ask for first name
	std::cout << "FIRST NAME: ";
	// Store in fname
	std::cin >> fname;

	// Ask for surname
	std::cout << "SURNAME: ";
	// Store in sname
	std::cin >> sname;

	// Ask for DOB
	std::cout << "DOB (MM/DD/YYYY): ";
	// Store in dob
	std::cin >> dob;


	file << "Admin\n" << id << "\n" << username << "\n" << fname << "\n" << sname << "\n" << dob << "\n\n";
	file.close();
	std::cout << "[INFO] ADDED ADMIN.\n";
}


void add_student()
{
	std::ofstream file("data/students.txt", std::ios::app)
	std::string id, username, fname, sname, dob;


	std::cout << "STUDENT ID: ";
	std::cin >> id;

	std::cout << "USERNAME: ";
	std::cin >> username;

	if (!valid_student_username(username))
	{
		std::cout << "[ERR] INVALID STUDENT USERNAME.\n";
		return;
	}

	std::cout << "FIRST NAME: ";
	std::cin >> fname;

	std::cout << "SURNAME: ";
	std::cin >> sname;

	std::cout << "DOB (MM/DD/YYYY): ";
	std::cin >> dob;

	file << "Student\n" << id << "\n" << username << "\n" << fname << "\n" << sname << "\n" << dob << "\nCourses:\n\n";
	file.close();

	std::cout << "[INFO] ADDED STUDENT.\n";
}


void enroll()
{
	std::string username, course_id, grade;


	std::cout << "STUDENT USERNAME: ";
	std::cin >> username;

	std::cout << "COURSE ID: ";
	std::cin >> course_id;

	std::cout << "GRADE: ";
	std::cin >> grade;

	fstream std::file("data/students.txt");
	std::vector<std::string> lns;
	std::string ln;

	bool found = false;

	while (std::getline(file, ln))
	{
		if (line == username)
		{
			found = true;
		}

		lns.push_back(line);

		if (found && line == "Courses:")
		{
			std::string entry = course_id + ":" + grade;
			lns.push_back(entry);
			found = false;
		}
	}

	file.close();

	std::ofstream std::out("data/students.txt");
	for (const auto& l : lns)
	{
		out << l << "\n";
	}

	out.close();
	std::cout << "[INFO] STUDENT ENROLLED, GRADE ASSIGNED.\n";
}


void gradebook()
{
	std::string username;
	std::cout << "USERNAME: ";
	std::cin >> username;

	ifstream file("data/students.txt");
	std::string line;
	bool found = false;

	while (std::getline(file, line))
	{
		if (line == username)
		{
			found = true;
		}

		if (found && line == "Courses:")
		{
			while (std::getline(file, line) && !line.empty())
			{
				std::cout << line << "\n";
			}

			break;
		}
	}

	file.close();
}
