// Functions that are used in different parts of the LMS
// Daniel Teberian


// Imports
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "fn.h"



// Check if there is a data directory
bool dir_exists(const std::filesystem::path& data_dir)
{
	// If the directory cannot be located
	if (!std::filesystem::exists(data_dir))
	{
		// Try to create the directory
		try
		{
			return std::filesystem::create_directories(data_dir);
		}

		// If the directory cannot be created
		catch (const std::filesystem::filesystem_error& err)
		{
			// Error message
			std::cerr << "[ERR] FILESYSTEM ERROR: " << err.what() << "\n";
			// Return false
			return false;
		}
	}

	// If the directory is found
	return std::filesystem::is_directory(data_dir);
}


// Check if the file exists
bool file_exists(const std::filesystem::path& fpath)
{
	return std::filesystem::exists(fpath) && std::filesystem::is_regular_file(fpath);
}
