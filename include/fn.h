// Rewritten header for the functions
// Daniel Teberian


#ifndef FN_H
#define FN_H


#include <string>

bool valid_course(const std::string& id);
bool alpha(const std::string& str);
bool valid_admin_username(const std::string& username);
bool valid_student_username(const std::string& username);
bool valid_instructor_username(const std::string& username);
bool valid_username(const std::string& username, char role);

#endif
