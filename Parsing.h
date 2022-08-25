// Developed by Hesham Elshafey
// Version 1.0

#ifndef PARSING_H
#define PARSING_H
#include <string>
#include <vector>
#include <sstream>
#include "Course.h"
class parsing
{
private:
    std::string main;
    std::string verb1;
    std::string verb2;
    std::string verb3;
    std::string verb4;
    std::string verb5;
    std::string verb6;
    std::stringstream ex;
    std::string test; // used to display the coursename>> format and to check if course is set or not.
    std::vector<Course> course;
    size_t x; // used as looping variable to set the course and then used as the integer to access this specific course from the vector of coruses. 
    int terminator{0};

public:
    void MiniHelp();
    void Extractor();
    void Distributor(std::string, std::string, std::string, std::string, std::string);
    void CreateCourseP();
    void ListCoursesP();
    void DeleteCourseP();
    void CreateStudent();
    void ListStudentsP();
    void DeleteStudentP();
    int CreateItemP();
    void ListItemsP();
    int DeleteItemP();
    int AddGradesP();
    int AddGradeP();
    int ListGradeP();
    void ListGradesP();
    void DeleteGradeP();
    void DeleteGradesP();
    void Help();
    void Save();
    void Quit();
    int testsetcourse();
    void setcoursechecker(std::string);
    int intitalcourseobjects();
    void checkbufferoverrun();
};
#endif