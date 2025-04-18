// Main code for the LMS
// Daniel Teberian

// Imports
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
// TODO: #include "userman.h"
// TODO: #include "courseman.h"
// TODO: #include "datpersist.h"
#include "fn.h"


// Display menu
void show_menu();
// Get input from user
int uin();
// Handler for user-management
void proc_userman();
// Handler for course-management
void proc_courseman();
// Handler for saved data
void proc_dat();


// Main
int main()
{
	// Check for the data directory
	if (dir_exists(data_dir))
	{
		// Tell user
		std::cout << "[INFO] FOUND DATA DIRECTORY.\n";
	}
	// If not found
	else
	{
		// Tell user
		std::cout << "[INFO] DATA DIRECTORY NOT FOUND.\n";

		// Try to create the directory
		try
		{
			return std::filesystem::create_directories(data_dir);
		}

		// If LMS cannot create the directory
		catch (const std::filesystem::filesystem_error& err)
		{
			// Print error message
			std::cerr << "[ERR] FILESYSTEM ERROR: " << err.what() << "\n";
			// Return false
			return false;
		}
	}

	// Check for the administrators data file
	if (file_exists(admin_data))
	{
		// Tell the user
		std::cout << "[INFO] ADMINISTRATOR DATA FILE FOUND.\n";
	}
	// If the file is not found
	else
	{
		// Tell the user
		std::cout << "[INFO] ADMINISTRATOR DATA FILE NOT FOUND.\n";
		// Try to create the file
		std::ofstream ofs(admin_data);
		// Return true if the file was created
		return ofs.good();
	}

	// Check for the assignments data file
	if (file_exists(assignments_data))
	{
		// Tell the user
		std::cout << "[INFO] ASSIGNMENT DATA FILE FOUND.\n";
	}
	// If the file is not found
	else
	{
		// Tell the user
		std::cout << "[INFO] ASSIGNMENT DATA FILE NOT FOUND.\n";
		// Try to create the file
		std::ofstream ofs(assignments_data);
		// Return true if the file was created
		return ofs.good();
	}

	// Check for the courses data file
	if (file_exists(courses_data))
	{
		// Tell the user
		std::cout << "[INFO] COURSES DATA FILE FOUND.\n";
	}
	// If the file was not found
	else
	{
		// Tell the user
		std::cout << "[INFO] COURSES DATA FILE NOT FOUND.\n";
		// Try to create the file
		std::ofstream ofs(courses_data);
		// Return true if the file was created
		return ofs.good();
	}

	// Check for the students data file
	if (file_exists(students_data))
	{
		// Tell the user
		std::cout << "[INFO] STUDENT DATA FILE FOUND.\n";
	}
	// If the file is not found
	else
	{
		// Tell the user
		std::cout << "[INFO] STUDENT DATA FILE NOT FOUND.\n";
		// Try to create the file
		std::ofstream ofs(students_data);
		// Return tru eif the file was created
		return ofs.good();
	}

	// Initialize the selection variable, set to 0
	int selection = 0;

	// Menu prompt loop
	while (selection != 4)
	{
		// Display menu
		show_menu();
		// Assign user input to the value of selection
		selection = uin();

		// Switch, based on user input
		switch(selection)
		{
		// If user selects option 1
		case 1:
		{
			// Process user-management
			proc_userman();
			// Break out of the loop
			break;
		}

		// If user selects option 2
		case 2:
		{
			// Process course management
			proc_courseman();
			// Break out of the loop
			break;
		}

		// If user selects option 3
		case 3:
		{
			// Process saved data
			proc_dat();
			// Break out of the loop
			break;
		}

		// If user selects option 4
		case 4:
		{
			// Print message, telling user that the program is terminating
			std::cout << "[INFO] EXITING." << std::endl;
			// Break out of the cycle
			break;
		}

		// If the user selects anything other than a supported value (default)
		default:
		{
			// Print message to inform user that they entered an invalid ID
			std::cout << "[ERR] INVALID SELECTION" << std::endl;
		}
	}

	// Assuming it goes correctly, exit with 0.
	return 0;
}


// Display menu
void show_menu()
{
	// Title
	std::cout << "LEARNING MANAGEMENT SYSTEM" << std::endl;

	// Option 1
	std::cout << "1 - USER MANAGEMENT" << std::endl;

	// Option 2
	std::cout << "2 - COURSE MANAGEMENT" << std::endl;

	// Option 3
	std::cout << "3 - SAVE DATA TO FILE" << std::endl;

	// Option 4
	std::cout << "4 - EXIT" << std::endl;

	// Ask user to select an option
	std::cout << "CHOOSE FROM THE ABOVE MENU: ";
}

// Retrieve the user's input
int uin()
{
	// Selection variable
	int selection;
	// Set choice to whatever the user inputs
	std::cin >> selection;
	// Return the updated value of selection
	return selection;
}


// Process user-management
void proc_userman()
{
	// Selection variable
	int selection;
	// Menu loop
	do
	{
		// Title
		std::cout << "\nUSER MANAGEMENT" << std::endl;

		// Option 1
		std::cout << "1 - REGISTER USER" << std::endl;

		// Option 2
		std::cout << "2 - LIST REGISTERED USERS" << std::endl;

		// Option 3
		std::cout << "3 - RETURN TO MAIN MENU" << std::endl;

		// Ask user for input
		std::cout << "CHOOSE FROM THE ABOVE MENU: ";

		// Set the value of selection to the user's input
		selection = uin();


		// User-management menu loop
		switch(selection)
		{
			// If user selects option 1
			case 1:
				// Add user
				// useradd();
				// Break out of loop
				break;

			// If user selects option 2
			case 2:
				// Show registered users
				// userls();
				// Break out of loop
				break;

			// If user selects option 3
			case 3:
				// Break out of loop
				break;

			// If user enters anything besides a listed entry (default)
			default:
				// Show error message
				std::cout << "[ERR] INVALID SELECTION" << std::endl;
		}
	}

	// As long as the user does not choose option 3
	while (selection != 3);
}

}
