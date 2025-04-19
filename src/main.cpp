// Rewritten version of the LMS
// Daniel Teberian

/* IMPORTS */
#include <iostream>
#include "userman.h"
#include "courseman.h"
#include "fn.h"


int main()
{
	// User choice
	int sel;

	while (true)
	{
		std::cout << "\nLEARNING MANAGEMENT SYSTEM\n";
		std::cout << "1 - ADD COURSE\n";
		std::cout << "2 - ASSIGN INSTRUCTOR\n";
		std::cout << "3 - ENROLL STUDENT\n";
		std::cout << "4 - GRADEBOOK\n";
		std::cout << "5 - ADD STUDENT\n";
		std::cout << "6 - DROP STUDENT\n";
		std::cout << "7 - ADD ADMINISTRATOR\n";
		std::cout << "8 - ASSIGNMENT CREATOR\n";
		std::cout << "9 - VIEW COURSES TAUGHT BY INSTRUCTOR\n";
		std::cout << "0 - EXIT\n";

		std::cout << "LMS:> ";

		// Store user-input in the sel value
		std::cin >> sel;

		if (sel == 0)
		{
			break;
		}

		// Menu logic
		switch (sel)
		{
			case 1: add_course(); break;
			case 2: assign_course(); break;
			case 3: enroll(); break;
			case 4: gradebook(); break;
			case 5: add_student(); break;
			case 6: rm_student(); break;
			case 7: add_admin(); break;
			case 8: add_assignment(); break;
			case 9: courses_instructor(); break;
		}
	}

	return 0;
}
