// Header file for the functions used in the LMS
// Daniel Teberian


#ifndef FN_H
#define FN_H

// Imports
#include <filesystem>
#include <iostream>
#include <fstream>

// Data directory
std::filesystem::path data_dir = "data";

// Administrators data file path
std::filesystem::path admin_data = data_dir / "administrators.txt";

// Assignments data file path
std::filesystem::path assignments_data = data_dir / "assignments.txt";

// Courses data file path
std::filesystem::path courses_data = data_dir / "courses.txt";

// Students data file path
std::filesystem::path students_data = data_dir / "students.txt";


// Check if directory exists
bool dir_exists(const std::filesystem::path& data_dir);

// Check if file exists
bool file_exists(const std::filesystem::path& fpath);


#endif
