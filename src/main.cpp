// The main code for the LMS.

// Imports
#include <ncurses.h>
// TODO #include <"userman.h">
// TODO #include <"courseman.h">
// TODO #include <"datpersist.h">



// Main function
int main()
{
	// Initialize ncurses
	initscr();
	// Disable line-buffering
	cbreak();
	// Disable input echoing
	noecho();


	// Load data from file(s)
	// TODO: Check if file(s) exist
	// load_all_data();

	// Create integer to handle user choice. Set value to 0.
	int choice;

	// Main menu loop
	while (choice != 4)
	{
		// Clear screen
		clear();
		// Print title
		mvprint(0, 0, "LEARNING MANAGEMENT SYSTEM");
		// Print option 1
		mvprint(2, 0, "1 - USER MANAGEMENT");
		// Print option 2
		mvprint(3, 0, "2 - COURSE MANAGEMENT");
		// Print option 3
		mvprint(4, 0, "3 - SAVE DATA TO FILE");
		// Print option 4
		mvprint(5, 0, "4 - EXIT PROGRAM");

		// Refresh
		refresh();

		// Set the value of choice to whatever the user input is
		choice = getch() - '0';

		// TODO: Implement the functions as they are completed.
		// If user selects option 1
		if (choice == 1)
		{
			// handle_userman();
		}
		else if (choice == 2)
		{
			// You get it
		}
		// If user enters anything other than a supported value
		else
		{
			// Print error message
			mvprint(9, 0, "[ERR]: INVALID SELECTION");
			// Refresh
			refresh();
			// Await key-press
			getch();
		}
	}

	// Stop ncurses
	endwin();
	// Exit successfully
	return 0;
}
		else
