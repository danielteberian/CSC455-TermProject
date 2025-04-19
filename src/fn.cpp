// Rewritten functions for the LMS
// Daniel Teberian


/* IMPORTS */
#include "fn.h"
#include <cctype>
#include <string>

/*
	Role: Validates course ID
	Parameter: ID
	Returns: True if valid, false if invalid
*/
bool valid_course(const std::string& id)
{
	if (id.length() != 6)
	{
		return false;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (!isupper(id[i]))
		{
			return false;
		}
	}

	if (!isdigit(id[3]) || id[3] == '0' || !isdigit(id[4]) || !isdigit(id[5]))
	{
		return false;
	}

	return true;
}

/*
	Role: Ensures string only contains alphabetic characters
	Parameter: str
	Returns: True if alphabetic, false if it is not
*/
bool alpha(const std::string& str)
{
	for (char c : str)
		if (!isalpha(c))
		{
			return false;
		}

	return true;
}

/*
	Role: Validates an admin username
	Parameter: username
	Returns: True if valid, false if invalid
*/
bool valid_admin_username(const std::string& username)
{
	if (username.length() < 2 || username[0] != 'A' || !isdigit(username[1]))
	{
		return false;
	}

	for (int i = 2; i < username.length(); i++)
	{
		if (!isdigit(username[i]))
		{
			return false;
		}
	}

	return true;
}

/*
	Role: Validats student username
	Parameter: username
	Returns: True if valid, false if invalid
*/
bool valid_student_username(const std::string& username)
{
	if (username.length() < 2 || username[0] != 'S' || !isdigit(username[1]))
	{
		return false;
	}

	for (int i = 2; i < username.length(); i++)
	{
		if (!isdigit(username[i]))
		{
			return false;
		}
	}

	return true;
}


/*
	Role: Validates instructor username
	Parameter: username
	Returns: True if valid, false if invalid
*/
bool valid_instructor_username(const std::string& username)
{
	if (username.length() < 2  || username[0] != 'I' || !isdigit(username[1]))
	{
		return false;
	}

	for (int i = 2; i < username.length(); i++)
	{
		if (!isdigit(username[i]))
		{
			return false;
		}
	}

	return true;
}



/*
	Role: Validate user's role
	Parameter: username, role
	Returns: True if valid, false if invalid
*/
bool valid_username(const std::string& username, char role)
{
	if (username.length() < 10)
	{
		return false;
	}

	switch (role)
	{
		case 'A':
			if (!valid_admin_username(username))
			{
				return false;
			}

			break;

		case 'S':
			if (!valid_student_username(username))
			{
				return false;
			}

			break;

		case 'I':
			if (!valid_instructor_username(username))
			{
				return false;
			}

			break;

		default:
			return false;
	}


	int digit_count = 0;

	for (int i = 1; i < username.length(); ++i)
	{
		if (!isdigit(username[i]))
		{
			return false;
		}

		digit_count++;
	}

	if (digit_count > 5)
	{
		return false;
	}

	if (isdigit(username[1]) && username[1] == '0')
	{
		return false;
	}

	return true;
}
