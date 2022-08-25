// Developed by Hesham Elshafey
// Version 1.0

#ifndef COURSE_h
#define COURSE_h
#include <string>
#include <vector>
#include "Gradeditem.h"
#include "Student.h"
class Course
{
private:
    std::string name;
    std::string reader;
    std::vector<Gradeditem> items;
    std::vector<Student> student;
    int totalpoints{0};
    int totalnumberofstudents;

public:
    void createcourse(std::string);
    void initalcreatecourse(std::string);
    void addstudenttocourse(std::string, std::string, std::string);
    void writestudentdate();
    std::string coursenamecopier();
    void liststudentcourse();
    void intialstudentobject();
    std::string commaspacereplace(std::string a, const std::string &from, const std::string &to);
    void intialstudentobjectspliter(std::string);
    void additemtocourse(std::string, int);
    void writeitemdata();
    void listitems();
    void deletestudent(std::string);
    void deleteitem(std::string);
    void intialitemobject();
    void intialitemobjectspliter(std::string);
    void addgradescourse(std::string);
    void listgradescourse();
    int generatetotalpoints();
    void addgradesinglestudent(std::string, std::string);
    void writestudentgradestofileC();
    void initialstudentgradesC();
    void initialstudentgradesCsplitter(std::string);
    void listgradeC(std::string);
    int checkitemexitance(std::string);
    void listallgrades();
    char finallettergrade(double, int);
    int CheckStudentForDeletion(std::string);
    void ListFinalGradeHistogram(int, int, int, int, int);
};
#endif