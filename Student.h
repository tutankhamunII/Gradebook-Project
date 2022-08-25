// Developed by Hesham Elshafey
// Version 1.0

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include "Gradeditem.h"
class Student
{
private:
    std::string firstname;
    std::string lastname;
    std::string ID;
    std::string coursename;
    std::vector<std::string> studentdata;
    std::vector<int> grades;
    std::vector<Gradeditem> studentitems;
    int finalgrade{0};
    char letterfinalgrade;

public:
    void addstudentStudent(std::string, std::string, std::string, std::string, std::vector<Gradeditem>);
    std::vector<std::string> studentdatastringcreation();
    std::string studentIDcopier();
    void createitemobject(Gradeditem);
    void addgrades(std::string);
    int generatefinalgrade();
    void writestudentgradestofileS();
    void initialstudentgrades(std::string, int);
    int listgradeS(std::string, int);
    void onegradehistogram(int, int, int, int, int, int, std::string);
    void listgradesS();
};
#endif