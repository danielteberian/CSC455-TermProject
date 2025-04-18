// Course management component of the LMS
// Daniel Teberian


// Imports
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Course management header
#include "courseman.h"


// Create a new assignment
void new_assignment()
{
	// The path for storing assignment data
	std::filesystem::path data = "data/assignments.txt";

	// Course ID
	std::string course_id;
	// Assignment name
	std::string assignment_name;
	// Maximum point value
	int max_points;


	// Ask for the course ID
	std::cout << "COURSE ID: ";
	// Store user input in the course_id variable
	std::cin >> course_id;

	// Ask for the assignment name
	std::cout << "ENTER NAME FOR THE ASSIGNMENT: ";
	// Store user input in the assignment_name variable
	std::cin >> assignment_name;

	// Make sure that the assignment's name is no more than 12 characters in length
	if (assignment_name.length() > 12)
	{
		// Error message
		std::cout << "[ERR] ASSIGNMENT NAME MUST BE FEWER THAN 13 CHARACTERS.\n";
		// Return
		return;
	}


	// Ask for the point value to be given for the assignment
	std::cout << "MAXIMUM POINT VALUE: ";
	// Store user input in the max_points variable
	std::cin >> max_points;

	// Make sure that the number of points is a positive integer
	if (max_points <= 0)
	{
		// Error message
		std::cout << "[ERR] POINT VALUE CANNOT BE BELOW ZERO.\n";
		// Return
		return;
	}

	// Check i

	// Check if an assignment data file exists
	if (!std::filesystem::exists(data))
	{
		// Tell the user that there is no data directory
		std::cout << "DATA DIRECTORY NOT FOUND.\n";

		// If a data directory can be created
		if (std::filesystem::create_directories(data)

	// Add assignment to list of assignments.
	ofstream file("data/assignments.txt", ios::app);
	file << course_id << " " << assignment_name << " " << max_points << "\n";
